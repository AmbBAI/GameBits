#ifndef _GAME_ENGINE_UTILITY_VERTEX_H_
#define _GAME_ENGINE_UTILITY_VERTEX_H_

#include "common/ge_include.h"
#include "ge_type.h"

namespace ge
{

struct GE_API GE_VERTEX_DECL
{
	U32								fvf;
	int								size;
	LPDIRECT3DVERTEXDECLARATION9	decl;
	D3DVERTEXELEMENT9				element[MAX_FVF_DECL_SIZE];

	GE_VERTEX_DECL();
	bool is_valid();
	DLL_MANAGE_CLASS(GE_VERTEX_DECL);
};

class GE_API GEVertexDecl
{
protected:
	GEVertexDecl();
	virtual ~GEVertexDecl();

public:
	static GEVertexDecl* get_instance();

public:
	static GE_VERTEX_DECL* get_vertex_decl(DWORD fvf);
	static void release_vertex_decl(DWORD fvf);

protected:
	bool				_init_vertex_decl(GE_VERTEX_DECL* out_decl, DWORD fvf);
	bool				_create_vertex_decl(DWORD fvf);
	GE_VERTEX_DECL*		_get_vertex_decl(DWORD fvf);
	void				_destory_vertex_decl(GE_VERTEX_DECL* out_decl);
	void				_release_vertex_decl(DWORD fvf);

private:
	typedef std::hash_map<DWORD, GE_VERTEX_DECL*> VERTEX_DECL_MAP;
	VERTEX_DECL_MAP		vertex_decl_map_;
};



class GE_API GE_VERTEX
{
public:
	GE_VERTEX();
	GE_VERTEX(const GE_VERTEX& copy);
	virtual ~GE_VERTEX();

public:
	bool			set_fvf(U32 fvf);
	bool			set_decl(GE_VERTEX_DECL* decl);
	GE_VERTEX_DECL*	get_decl();

	void			set_position(float x, float y, float z);
	void			get_position(float& x, float& y, float& z);
	void			set_normal(float x, float y, float z);
	void			set_texcoords(float u, float v);
	void			set_blend(U32 blend);
	void			set_color(GE_COLOR& color);
	void			set_color(U32 color);
	void			set_rhw(float rhw);

	bool			pack(void* mem_buff, int size);

protected:
	bool			_append_data(void* mem_buff, int& mem_offset, void* p_data, int data_size);

private:
	D3DXVECTOR3			position_;
	float				rhw_;
	unsigned			blend_;
	D3DXVECTOR3			normal_;
	D3DCOLOR			color_;
	D3DXVECTOR2			texcoords_;

	GE_VERTEX_DECL*		decl_;
};


}

#endif // _GAME_ENGINE_UTILITY_VERTEX_H_