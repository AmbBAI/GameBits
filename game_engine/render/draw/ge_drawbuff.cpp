#include "ge_drawbuff.h"
#include "../../common/ge_engine.h"

namespace ge
{
DLL_MANAGE_CLASS_IMPLEMENT(GEDrawBuff);

GEDrawBuff::GEDrawBuff()
: vertex_decl_(NULL)
, dx_vertex_buff_(NULL)
, dx_index_buff_(NULL)
, dx_vertex_cnt_(0)
, dx_index_cnt_(0)
{

}

GEDrawBuff::~GEDrawBuff()
{
	destory_buff();
}

bool GEDrawBuff::set_vertex_decl( GE_VERTEX_DECL* decl )
{
	if (vertex_decl_ != decl) destory_vertex_buff();
	vertex_decl_ = decl;
	return true;
}

GE_VERTEX_DECL* GEDrawBuff::get_vertex_decl()
{
	return vertex_decl_;
}

bool GEDrawBuff::init_vertex_buff( int vertex_cnt )
{
	if (dx_vertex_cnt_ < vertex_cnt)
	{
		destory_vertex_buff();

		LPDIRECT3DDEVICE9 p_d3d_device = GEEngine::get_instance()->get_device();
		if (p_d3d_device == NULL) return false;

		if (vertex_decl_ == NULL) return false;
		if (!vertex_decl_->is_valid()) return false;

		HRESULT h_res = S_OK;

		h_res = p_d3d_device->CreateVertexBuffer(
			vertex_cnt * vertex_decl_->size,
			D3DUSAGE_WRITEONLY,
			NULL,
			D3DPOOL_MANAGED,
			&dx_vertex_buff_,
			NULL);
		if (FAILED(h_res)) goto init_faild;
		dx_vertex_cnt_ = vertex_cnt;
		return true;

init_faild:
		destory_vertex_buff();
		return false;

	} else return true;
}

bool GEDrawBuff::init_index_buff( int index_cnt )
{
	if (dx_index_cnt_ < index_cnt)
	{
		destory_index_buff();

		LPDIRECT3DDEVICE9 p_d3d_device = GEEngine::get_instance()->get_device();
		if (p_d3d_device == NULL) return false;

		HRESULT h_res = S_OK;
		h_res = p_d3d_device->CreateIndexBuffer(
			index_cnt * sizeof(WORD),
			D3DUSAGE_WRITEONLY,
			D3DFMT_INDEX16,
			D3DPOOL_MANAGED,
			&dx_index_buff_,
			NULL);
		if (FAILED(h_res)) goto init_faild;
		dx_index_cnt_ = index_cnt;
		return true;

init_faild:
		destory_index_buff();
		return false;

	} else return true;
}

bool GEDrawBuff::init_quad_buff( int quad_cnt )
{
	std::vector<unsigned short> indices;
	if (!init_vertex_buff(quad_cnt * 4)) goto init_faild;
	if (!init_index_buff(quad_cnt * 6)) goto init_faild;

	indices.resize(quad_cnt * 6);
	for (int i=0; i<quad_cnt; ++i)
	{
		int i6 = i * 6;
		int i4 = i * 4;
		indices[i6 + 0] = i4 + 0;
		indices[i6 + 1] = i4 + 1;
		indices[i6 + 2] = i4 + 3;
		indices[i6 + 3] = i4 + 1;
		indices[i6 + 4] = i4 + 2;
		indices[i6 + 5] = i4 + 3;
	}
	if(!set_indices(&indices[0], quad_cnt * 6)) goto init_faild;

	return true;

init_faild:
	destory_buff();
	return false;
}

void GEDrawBuff::destory_vertex_buff()
{
	if (dx_vertex_buff_)
		D3D_RELEASE(dx_vertex_buff_);
	dx_vertex_buff_ = NULL;
	dx_vertex_cnt_ = 0;
}

void GEDrawBuff::destory_index_buff()
{
	if (dx_index_buff_)
		D3D_RELEASE(dx_index_buff_);
	dx_index_buff_ = NULL;
	dx_index_cnt_ = 0;
}

void GEDrawBuff::destory_buff()
{
	destory_vertex_buff();
	destory_index_buff();
}

bool GEDrawBuff::prepare_drawbuff()
{
	LPDIRECT3DDEVICE9 p_d3d_device = GEEngine::get_instance()->get_device();
	if (p_d3d_device == NULL) return false;

	if (vertex_decl_ == NULL) return false;
	if (!vertex_decl_->is_valid()) return false;

	HRESULT h_res = S_OK;
	h_res = p_d3d_device->SetVertexDeclaration(vertex_decl_->decl);
	assert(SUCCEEDED(h_res));
	h_res = p_d3d_device->SetStreamSource(0, dx_vertex_buff_, 0, vertex_decl_->size);
	assert(SUCCEEDED(h_res));
	if (dx_index_buff_ != NULL)
	{
		h_res = p_d3d_device->SetIndices(dx_index_buff_);
		assert(SUCCEEDED(h_res));
	}
	return true;
}

bool GEDrawBuff::set_verties( GE_VERTEX* verties, int size )
{
	if (dx_vertex_buff_ == NULL) return false;
	if (verties == NULL) return false;

	if (vertex_decl_ == NULL) return false;
	if (!vertex_decl_->is_valid()) return false;

	int vertex_cnt = size;
	if (vertex_cnt <= 0) return true;
	if (vertex_cnt > dx_vertex_cnt_) return false;

	char* vertex_buff = NULL;
	HRESULT h_res = dx_vertex_buff_->Lock(
		0, vertex_cnt * vertex_decl_->size,
		(void**)&vertex_buff, 0);

	for (int i=0; i < vertex_cnt; ++i)
	{
		bool b_ret = true;
		b_ret = verties[i].pack(vertex_buff, vertex_decl_->size);
		if (!b_ret)
		{
			b_ret = false;
			break;
		}

		vertex_buff += vertex_decl_->size;
	}

	dx_vertex_buff_->Unlock();
	return true;
}

bool GEDrawBuff::set_indices( unsigned short* indices, int size )
{
	if (dx_index_buff_ == NULL) return false;
	if (indices == NULL) return false;

	int index_cnt = size;
	if (index_cnt <= 0) return true;
	if ( index_cnt > dx_index_cnt_) return false;

	WORD* index_buff = NULL;
	dx_index_buff_->Lock(
		0, index_cnt * sizeof(WORD),
		(void**)&index_buff, 0);
	for (int i=0; i < index_cnt; ++i)
	{
		index_buff[i] = indices[i];
	}
	dx_index_buff_->Unlock();
	return true;
}




}