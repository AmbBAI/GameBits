#ifndef _GAME_ENGINE_RENDER_ATLAS_RENDER_H_
#define _GAME_ENGINE_RENDER_ATLAS_RENDER_H_

#include "../common/ge_include.h"
#include "../utility/ge_vertex.h"

namespace ge
{

struct GE_API GE_QUAD
{
	float		xys[8];
	unsigned	color;
	int			texid;
	float		uvs[8];
};

struct GE_API GE_QUAD_EX
{
	GE_VERTEX tl;
	GE_VERTEX tr;
	GE_VERTEX bl;
	GE_VERTEX br;
	int texid;
};

class GETextureGroup;
class GEREffect;
class GE_API GEAtlasRender
{
	DLL_MANAGE_CLASS(GEAtlasRender);

	GEAtlasRender();
	virtual ~GEAtlasRender();

public:
	static const DWORD DEFAULT_FVF_FORMAT;

public:
	virtual bool set_vertex_fvf(DWORD fvf);
	virtual bool set_vertex_decl(GE_VERTEX_DECL* vertex_decl);
	virtual GE_VERTEX_DECL* get_vertex_decl();

	virtual bool init_texture_group();
	virtual bool set_texture_group(GETextureGroup* texture_group);
	virtual GETextureGroup* get_texture_group();
	virtual void release_texture_group();

	virtual bool init_render();
	virtual bool update_render();
	virtual void release_render();
	virtual bool prepare_render();

	virtual bool add_quad(GE_QUAD& quad);
	virtual bool add_quad(GE_QUAD_EX& quad);
	virtual bool add_quad(int texture_id = 0);
	virtual void clear_quads();
	virtual bool draw_quads(GEREffect* effect = NULL);

public:
	virtual bool init();
	virtual void destory();

protected:
	virtual bool _set_verties(std::vector<GE_VERTEX>& vertex_array);
	virtual bool _set_indices(std::vector<WORD>& index_array);

	virtual bool _update_render_task(int quad_index, int texture_id);

protected:
	GE_VERTEX_DECL*			vertex_decl_;

	GETextureGroup*			texture_group_;

	bool					need_render_update_;

	typedef std::vector<GE_VERTEX> VERTEX_LIST;
	VERTEX_LIST				vertex_list_;

	struct QUAD_RENDER_TASK
	{
		int			offset;
		int			count;
		int			texture;
	};

	typedef std::vector<QUAD_RENDER_TASK> QUAD_RENDER_TASK_LIST;	
	QUAD_RENDER_TASK_LIST	render_task_list_;

	LPDIRECT3DVERTEXBUFFER9	dx_vertex_buff_;
	LPDIRECT3DINDEXBUFFER9	dx_index_buff_;
	int						dx_quads_cnt_;
};

} // namespace ge

#endif // _GAME_ENGINE_RENDER_ATLAS_RENDER_H_