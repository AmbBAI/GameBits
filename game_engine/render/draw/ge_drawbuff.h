#ifndef _GAME_ENGINE_DIRECTX_DRAWBUFF_H_
#define _GAME_ENGINE_DIRECTX_DRAWBUFF_H_

#include "../../common/ge_include.h"
#include "../../utility/ge_vertex.h"

namespace ge
{

class GE_API GEDrawBuff
{
	DLL_MANAGE_CLASS(GEDrawBuff);

protected:
	GEDrawBuff();
	virtual ~GEDrawBuff();

public:
	bool set_vertex_decl(GE_VERTEX_DECL* decl);
	GE_VERTEX_DECL* get_vertex_decl();

	bool init_vertex_buff(int vertex_cnt);
	bool init_index_buff(int index_cnt);
	bool init_quad_buff(int quad_cnt);
	void destory_vertex_buff();
	void destory_index_buff();
	void destory_buff();

	bool prepare_drawbuff();

	bool set_verties(GE_VERTEX* verties, int size);
	bool set_indices(unsigned short* indices, int size);

protected:
	GE_VERTEX_DECL*			vertex_decl_;

	LPDIRECT3DVERTEXBUFFER9	dx_vertex_buff_;
	LPDIRECT3DINDEXBUFFER9	dx_index_buff_;
	int						dx_vertex_cnt_;
	int						dx_index_cnt_;
};

} // namespace ge

#endif // _GAME_ENGINE_DIRECTX_DRAWBUFF_H_