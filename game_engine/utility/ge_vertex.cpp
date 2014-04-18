#include "ge_vertex.h"
#include "../common/ge_engine.h"

namespace ge
{

DLL_MANAGE_CLASS_IMPLEMENT(GE_VERTEX_DECL);

GE_VERTEX_DECL::GE_VERTEX_DECL()
: fvf(NULL)
, size(0)
, decl(NULL)
{
	memset(element, 0, sizeof(element));
}

bool GE_VERTEX_DECL::is_valid()
{
	if (fvf == NULL)	return false;
	if (size <= 0)		return false;
	if (decl == NULL)	return false;
	return true;
}


GEVertexDecl::GEVertexDecl()
: vertex_decl_map_()
{
}

GEVertexDecl::~GEVertexDecl()
{
	FOR_EACH (VERTEX_DECL_MAP, vertex_decl_map_, itor_decl)
	{
		_destory_vertex_decl(itor_decl->second);
		GE_RELEASE(itor_decl->second);
	}
	vertex_decl_map_.clear();
}

GEVertexDecl* GEVertexDecl::get_instance()
{
	static GEVertexDecl _global_ge_vertex_decl;
	return &_global_ge_vertex_decl;
}

bool GEVertexDecl::_init_vertex_decl( GE_VERTEX_DECL* out_decl, DWORD fvf )
{
	if (out_decl == NULL) return false;

	LPDIRECT3DDEVICE9 p_d3d_device = GEEngine::get_instance()->get_device();
	if (p_d3d_device == NULL) return false;

	_destory_vertex_decl(out_decl);

	out_decl->fvf = fvf;
	HRESULT h_res = S_OK;
	h_res = D3DXDeclaratorFromFVF(fvf, out_decl->element);
	assert(SUCCEEDED(h_res));
	if (FAILED(h_res)) return false;

	out_decl->size = (int)D3DXGetFVFVertexSize(fvf);
	h_res = p_d3d_device->CreateVertexDeclaration(out_decl->element, &(out_decl->decl));
	assert(SUCCEEDED(h_res));
	if (FAILED(h_res)) return false;

	return true;
}

void GEVertexDecl::_destory_vertex_decl( GE_VERTEX_DECL* out_decl )
{
	D3D_RELEASE((out_decl->decl));
	out_decl->fvf = NULL;
	out_decl->size = 0;
	memset(out_decl->element, 0, sizeof(out_decl->element));
}

bool GEVertexDecl::_create_vertex_decl( DWORD fvf )
{
	if (vertex_decl_map_.find(fvf) != vertex_decl_map_.end()) return true;
	GE_VERTEX_DECL* _decl = GE_VERTEX_DECL::create();
	if (_decl)
	{
		vertex_decl_map_[fvf] = _decl;
		_decl->retain();
		return _init_vertex_decl(_decl, fvf);
	}
	return false;
}

void GEVertexDecl::_release_vertex_decl( DWORD fvf )
{
	VERTEX_DECL_MAP::iterator itor_decl = vertex_decl_map_.find(fvf);
	if (itor_decl == vertex_decl_map_.end()) return;
	_destory_vertex_decl(itor_decl->second);
	GE_RELEASE(itor_decl->second);
	vertex_decl_map_.erase(itor_decl);
}

GE_VERTEX_DECL* GEVertexDecl::_get_vertex_decl( DWORD fvf )
{
	VERTEX_DECL_MAP::iterator itor_decl = vertex_decl_map_.find(fvf);
	if (itor_decl == vertex_decl_map_.end()) return NULL;
	return itor_decl->second;
}

GE_VERTEX_DECL* GEVertexDecl::get_vertex_decl( DWORD fvf )
{
	GEVertexDecl* vertex_decl = GEVertexDecl::get_instance();
	if (!vertex_decl->_create_vertex_decl(fvf)) return NULL;
	return vertex_decl->_get_vertex_decl(fvf);
}

void GEVertexDecl::release_vertex_decl( DWORD fvf )
{
	GEVertexDecl* vertex_decl = GEVertexDecl::get_instance();
	vertex_decl->_release_vertex_decl(fvf);
}



GE_VERTEX::GE_VERTEX()
: position_(0.f, 0.f, 0.f)
, normal_(0.f, 0.f, 0.f)
, texcoords_(0.f, 0.f)
, blend_(0)
, color_(0xffffffff)
, decl_(NULL)
{
}

GE_VERTEX::GE_VERTEX( const GE_VERTEX& copy )
{
	position_	= copy.position_;
	rhw_		= copy.rhw_;
	blend_		= copy.blend_;
	normal_		= copy.normal_;
	color_		= copy.color_;
	texcoords_	= copy.texcoords_;

	decl_		= NULL;
	set_decl(copy.decl_);
}

GE_VERTEX::~GE_VERTEX()
{
	GE_RELEASE(decl_);
}

bool GE_VERTEX::set_fvf( U32 fvf )
{
	return set_decl(GEVertexDecl::get_vertex_decl(fvf));
}

bool GE_VERTEX::set_decl( GE_VERTEX_DECL* decl )
{
	if (decl == decl_) return true;
	GE_RELEASE(decl_);

	if (decl == NULL) return false;
	if (!decl->is_valid()) return false;

	decl_ = decl;
	decl_->retain();

	return true;
}

GE_VERTEX_DECL* GE_VERTEX::get_decl()
{
	return decl_;
}

void GE_VERTEX::set_position( float x, float y, float z )
{
	position_.x = x;
	position_.y = y;
	position_.z = z;
}

void GE_VERTEX::set_rhw( float rhw )
{
	rhw_ = rhw;
}

void GE_VERTEX::set_normal( float x, float y, float z )
{
	normal_.x = x;
	normal_.y = y;
	normal_.z = z;
}

void GE_VERTEX::set_texcoords( float u, float v )
{
	texcoords_.x = u;
	texcoords_.y = v;
}

void GE_VERTEX::set_blend( U32 blend )
{
	blend_ = blend;
}

void GE_VERTEX::set_color( U32 color )
{
	color_ = color;
}

void GE_VERTEX::set_color( GE_COLOR& color )
{
	color_ = color.argb;
}

bool GE_VERTEX::pack( void* mem_buff, int size )
{
	if (mem_buff == NULL) return false;

	if (decl_ == NULL) return false;
	if (!decl_->is_valid()) return false;

	assert(decl_->size == size);
	if(decl_->size != size) return false;

	int buff_offset = 0;
	memset(mem_buff, 0, size);

	for (int i=0; ; ++i)
	{
		if (decl_->element[i].Type == D3DDECLTYPE_UNUSED) break;
		switch (decl_->element[i].Usage)
		{
		case D3DDECLUSAGE_POSITION:
			{
				_append_data(mem_buff, buff_offset, (void*)&(position_), sizeof(D3DXVECTOR3));

				//if (decl_->element[i].Type == D3DDECLTYPE_FLOAT4)
				//	_append_data(mem_buff, buff_offset, (void*)&(w_), sizeof(float));
			}
			break;
		case D3DDECLUSAGE_POSITIONT:
			{
				_append_data(mem_buff, buff_offset, (void*)&(position_), sizeof(D3DXVECTOR3));
				_append_data(mem_buff, buff_offset, (void*)&(rhw_), sizeof(float));
			}
			break;
		case D3DDECLUSAGE_NORMAL:
			{
				_append_data(mem_buff, buff_offset, (void*)&(normal_), sizeof(D3DXVECTOR3));
			}
			break;
		case D3DDECLUSAGE_COLOR:
			{
				_append_data(mem_buff, buff_offset, (void*)&(color_), sizeof(U32));
			}
			break;
		case D3DDECLUSAGE_BLENDINDICES:
			{
				//if (true)
					_append_data(mem_buff, buff_offset, (void*)&(blend_), sizeof(U32));
				//else
			}
			break;
		case D3DDECLUSAGE_BLENDWEIGHT:
			{
				//
			}
			break;
		case D3DDECLUSAGE_TEXCOORD:
			{
				//if (true)
					_append_data(mem_buff, buff_offset, (void*)&(texcoords_), sizeof(D3DXVECTOR2));
				//else
			}
			break;
		}
	}

	assert(buff_offset == decl_->size);
	if (buff_offset != decl_->size) return false;
	return true;
}

bool GE_VERTEX::_append_data( void* mem_buff, int& mem_offset, void* p_data, int data_size )
{
	memcpy((char*)mem_buff + mem_offset, p_data, data_size);
	mem_offset += data_size;
	return true;
}

}


