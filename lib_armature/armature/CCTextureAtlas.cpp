#include "CCTextureAtlas.h"
#include "../data/CCAtlasData.h"

namespace CC {

CCTextureAtlas::CCTextureAtlas()
: m_pAtlasPage(NULL)
, m_vecPaintQuad()
, m_pRenderObject(NULL)
, m_obTextureSize(CCSizeZero)
{
}

CCTextureAtlas::~CCTextureAtlas()
{
	release();
}


} // namespace