#include "../common/ge_app.h"
#include "../common/ge_engine.h"
#include "../render/ger_material.h"
#include "../utility/geu_vertex.h"
#include "geo_primitive.h"

namespace ge
{

DLL_MANAGE_CLASS_IMPLEMENT(GEOPrimitive);

GEOPrimitive::GEOPrimitive()
: d3d_vertex_buff_(NULL)
, vertex_cnt_(0)
, d3d_index_buff_(NULL)
, index_cnt_(0)
, d3d_texture_(NULL)
{
	GEObject::type_ = GEObjectType_Primitive;
}

GEOPrimitive::~GEOPrimitive()
{

}

bool GEOPrimitive::set_vertex_decl( GE_VERTEX_DECL* vertex_decl )
{
	if (vertex_decl_ && vertex_decl->is_valid())
	{
		if (vertex_decl_ != vertex_decl)
		{
			vertex_decl_ = vertex_decl;

			release_vetrix_buff();
			release_index_buff();
		}

		return true;
	}
	return false;
}

GE_VERTEX_DECL* GEOPrimitive::get_vertex_decl()
{
	return vertex_decl_;
}

bool GEOPrimitive::create_vetrix_buff( int vertex_cnt )
{
	LPDIRECT3DDEVICE9 p_d3d_device = GEEngine::get_instance()->get_device();
	if (p_d3d_device == NULL) return false;
	if (!vertex_decl_->is_valid()) return false;

	release_vetrix_buff();
	if (vertex_cnt <= 0) return true;

	HRESULT h_res = p_d3d_device->CreateVertexBuffer(
		vertex_cnt * vertex_decl_->size,
		D3DUSAGE_WRITEONLY,
		NULL, // use decl
		D3DPOOL_MANAGED,
		&d3d_vertex_buff_,
		NULL
		);

	if(SUCCEEDED(h_res)) vertex_cnt_ = vertex_cnt;
	return SUCCEEDED(h_res);
}

bool GEOPrimitive::create_index_buff( int index_cnt )
{
	LPDIRECT3DDEVICE9 p_d3d_device = GEEngine::get_instance()->get_device();
	if (p_d3d_device == NULL) return false;

	release_index_buff();
	if (index_cnt <= 0) return true;

	HRESULT h_res = p_d3d_device->CreateIndexBuffer(
		index_cnt * sizeof(WORD),
		D3DUSAGE_WRITEONLY,
		D3DFMT_INDEX16,
		D3DPOOL_MANAGED,
		&d3d_index_buff_,
		NULL
		);

	if(SUCCEEDED(h_res)) index_cnt_ = index_cnt;
	return SUCCEEDED(h_res);
}

bool GEOPrimitive::create_texture( const char* texture_path )
{
	LPDIRECT3DDEVICE9 p_d3d_device = GEEngine::get_instance()->get_device();
	if (p_d3d_device == NULL) return false;

	release_texture();

	HRESULT h_res = S_OK;
	h_res = D3DXCreateTextureFromFile(p_d3d_device, texture_path, &d3d_texture_);
	if (FAILED(h_res) || d3d_texture_ == NULL) return false;

	d3d_texture_->GetLevelDesc(0, &texture_desc_);
	return true;
}

bool GEOPrimitive::set_vertices( GE_VERTEX* vertex_array, int offset, int vertex_cnt )
{
	if (vertex_array == NULL) return false;
	if ( offset + vertex_cnt > vertex_cnt_) return false;

	int vertex_size = vertex_decl_->size;
	if (vertex_size <= 0) return false;

	char* vertex_buff = NULL;
	HRESULT h_res = d3d_vertex_buff_->Lock(
		offset * vertex_size,
		vertex_cnt * vertex_size,
		(void**)&vertex_buff, 0);
	for (int i=0; i < vertex_cnt; ++i)
	{
		bool b_ret = true;
		b_ret = vertex_array[i].pack(vertex_buff, vertex_size);
		if (!b_ret)
		{
			b_ret = false;
			break;
		}

		vertex_buff += vertex_size;
	}
	d3d_vertex_buff_->Unlock();
	return true;
}

bool GEOPrimitive::set_indices( WORD* index_array, int offset, int index_cnt )
{
	if (index_array == NULL) return false;
	if ( offset + index_cnt > index_cnt_) return false;

	WORD* index_buff = NULL;
	d3d_index_buff_->Lock(
		offset * sizeof(WORD),
		index_cnt * sizeof(WORD),
		(void**)&index_buff, 0);
	for (int i=0; i < index_cnt; ++i)
	{
		index_buff[i] = index_array[i];
	}
	d3d_index_buff_->Unlock();
	return true;
}

void GEOPrimitive::release_vetrix_buff()
{
	D3D_RELEASE(d3d_vertex_buff_);
	vertex_cnt_ = 0;
}

void GEOPrimitive::release_index_buff()
{
	D3D_RELEASE(d3d_index_buff_);
	index_cnt_ = 0;
}

void GEOPrimitive::release_texture()
{
	D3D_RELEASE(d3d_texture_);
	memset(&texture_desc_, 0, sizeof(D3DSURFACE_DESC));
}

void GEOPrimitive::set_primitive_draw( int start, int cnt )
{
	draw_primitive_start_ = start;
	draw_primitive_cnt_ = cnt;
}

bool GEOPrimitive::init()
{
	return true;
}

void GEOPrimitive::release()
{
	release_vetrix_buff();
	release_index_buff();

	release_texture();
}

void GEOPrimitive::update( time_t delta )
{

}

void GEOPrimitive::render( time_t delta )
{
	LPDIRECT3DDEVICE9 p_d3d_device = GEEngine::get_instance()->get_device();
	if (p_d3d_device == NULL) return;
	
	if (vertex_decl_ == NULL) return;
	if (!vertex_decl_->is_valid()) return;

	if (d3d_vertex_buff_ == NULL) return;

	p_d3d_device->SetTexture(0, d3d_texture_);

	HRESULT h_res = S_OK;
	if (d3d_index_buff_ == NULL)
	{
		h_res = p_d3d_device->SetStreamSource(0, d3d_vertex_buff_, 0, vertex_decl_->size);
		h_res = p_d3d_device->SetVertexDeclaration(vertex_decl_->decl);
		p_d3d_device->DrawPrimitive(D3DPT_TRIANGLELIST, draw_primitive_start_, draw_primitive_cnt_);
	}
	else
	{
		h_res = p_d3d_device->SetStreamSource(0, d3d_vertex_buff_, 0, vertex_decl_->size);
		h_res = p_d3d_device->SetIndices(d3d_index_buff_);
		h_res = p_d3d_device->SetVertexDeclaration(vertex_decl_->decl);
		h_res = p_d3d_device->DrawIndexedPrimitive(D3DPT_TRIANGLELIST,
			0,						// BaseVertexIndex
			0,						// MinVertexIndex
			vertex_cnt_,			// NumVertices
			draw_primitive_start_,		// StartIndex
			draw_primitive_cnt_);		// PrimitiveCount
	}

	p_d3d_device->SetTexture(0, NULL);
}

void GEOPrimitive::get_texture_size( int& width, int& height )
{
	width = texture_desc_.Width;
	height = texture_desc_.Height;
}

int GEOPrimitive::get_vertex_buff_size()
{
	return vertex_cnt_;
}

int GEOPrimitive::get_index_buff_size()
{
	return index_cnt_;
}


}