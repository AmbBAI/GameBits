#include "geo_armature.h"
#include "../../render/draw/ge_draw_atlas.h"
#include "../../render/texture/ge_texture_manager.h"

namespace CC
{

const unsigned CC_VERTEX_FVF = D3DFVF_XYZ | D3DFVF_DIFFUSE | D3DFVF_TEX1;

bool CCTextureAtlas::init(CCAtlasPage* atlasPage)
{
	if (atlasPage == NULL) return false;
	return initTexture(atlasPage->m_sImageFile.c_str());
}

void CCTextureAtlas::release()
{
	releaseTexture();
}

void CCTextureAtlas::addQuad( const CC_PAINT_QUAD& quad )
{
	ge::GEDrawAtlas* render_object = (ge::GEDrawAtlas*)m_pRenderObject;
	if (render_object == NULL) return;

	ge::GE_QUAD_EX ge_quad;
	ge_quad.texid = 0;

	ge::GE_VERTEX* dst_vertex[4];
	dst_vertex[0] = &(ge_quad.tl);
	dst_vertex[1] = &(ge_quad.tr);
	dst_vertex[2] = &(ge_quad.br);
	dst_vertex[3] = &(ge_quad.bl);

	CC_PAINT_VERTEX* src_vertex[4];
	src_vertex[0] = (CC_PAINT_VERTEX*)&(quad.tl);
	src_vertex[1] = (CC_PAINT_VERTEX*)&(quad.tr);
	src_vertex[2] = (CC_PAINT_VERTEX*)&(quad.br);
	src_vertex[3] = (CC_PAINT_VERTEX*)&(quad.bl);

	for (int i=0; i<4; ++i)
	{
		dst_vertex[i]->set_decl(render_object->get_vertex_decl());
		dst_vertex[i]->set_position(src_vertex[i]->x, src_vertex[i]->y, src_vertex[i]->z);
		dst_vertex[i]->set_color(src_vertex[i]->color);
		dst_vertex[i]->set_texcoords(src_vertex[i]->u, src_vertex[i]->v);
	}

	render_object->add_quad(ge_quad);
}

void CCTextureAtlas::clearQuads()
{
	ge::GEDrawAtlas* render_object = (ge::GEDrawAtlas*)m_pRenderObject;
	if (render_object == NULL) return;

	render_object->clear_quads();
}

void CCTextureAtlas::drawQuads()
{
	ge::GEDrawAtlas* render_object = (ge::GEDrawAtlas*)m_pRenderObject;
	if (render_object == NULL) return;

	render_object->prepare_render();
	render_object->draw_quads();
}

bool CCTextureAtlas::initTexture( const char* texturePath )
{
	releaseTexture();

	ge::GEDrawAtlas* render_object = NULL;
	render_object = ge::GEDrawAtlas::create();
	if (render_object == NULL) return false;
	m_pRenderObject = render_object;

	ge::GE_VERTEX_DECL* vertex_decl = ge::GEVertexDecl::get_vertex_decl(CC_VERTEX_FVF);
	render_object->set_vertex_decl(vertex_decl);

	render_object->init_texture_group();
	ge::GETextureGroup* texture_group = render_object->get_texture_group();
	if (texture_group == NULL) return false;

	texture_group->add_texture_from_file(texturePath);
	if (texture_group->get_texture() == NULL) return false;

	int width, height;
	texture_group->get_texture()->get_size(width, height);
	m_obTextureSize.width = (float)width;
	m_obTextureSize.height = (float)height;
	return true;
}

void CCTextureAtlas::releaseTexture()
{
	ge::GEDrawAtlas* render_object = (ge::GEDrawAtlas*)m_pRenderObject;
	if (render_object)
	{
		ge::GEDrawAtlas::release(&render_object);
	}

	m_pRenderObject = NULL;
	m_obTextureSize = CCSizeZero;
}

} // namespace CC

namespace ge {

DLL_MANAGE_CLASS_IMPLEMENT(GEOArmature);

GEOArmature::GEOArmature()
: cc_armature_(NULL)
{

}

GEOArmature::~GEOArmature()
{
	destory();
}

bool GEOArmature::init( const char* data_file )
{
	CC::CCDataManager* cc_data_manager = CC::CCDataManager::getInstance();
	if (cc_data_manager == NULL) return false;

	CC::CCDataCollection* cc_data = cc_data_manager->getData(data_file);
	cc_armature_ = new CC::CCArmature();
	cc_armature_->init(cc_data->getArmatureData());
	cc_armature_->initAnimation(cc_data->getAnimationData());
	cc_armature_->initTexture();

	if(CC::CCAnimation* ptr_animation = cc_armature_->getAnimation())
	{
		ptr_animation->play(0);
		return GEObject::init();
	} else return false;
}

void GEOArmature::destory()
{
	if (cc_armature_)
	{
		cc_armature_->release();
		delete cc_armature_;
		cc_armature_ = NULL;
	}
}

void GEOArmature::update( time_t delta )
{
	cc_armature_->updateAnimation(delta / 1000.f);
	cc_armature_->updateTransform(delta / 1000.f);
}

void GEOArmature::render( time_t delta )
{
	cc_armature_->render();
}

} // namespace ge
