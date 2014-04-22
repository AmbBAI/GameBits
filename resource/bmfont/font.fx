/*

This effect file is designed for rending bitmap fonts output by
AngelCode Bitmap Font Generator. It is capable of rendering
from 32bit textures that pack colored icons together with outlined
characters into one texture, where the icons use all 32bits and the
characters only use 8bits each.

*/

texture  g_txScene : TEXTURE0;

sampler2D g_samScene =
sampler_state
{
    Texture = <g_txScene>;
    MinFilter = Linear;
    MagFilter = Linear;
    MipFilter = Linear;
};

float4 PixWithoutOutline( float4 color : COLOR0,
                          float2 tex0  : TEXCOORD0 ) : COLOR0
{
    float4 pixel = tex2D(g_samScene, tex0);

    float val = min(pixel.a, pixel.rgb);
    pixel.rgb = 1;
    pixel.a   = val;
    
	return pixel * color;
}

float4 PixWithOutline( float4 color : COLOR0,
                       float2 tex0  : TEXCOORD0 ) : COLOR0
{
    float4 pixel = tex2D(g_samScene, tex0);
    
    float val = min(pixel.a, pixel.rgb);
	pixel.rgb = val > 0.5 ? 2*val-1 : 0;
	pixel.a   = val > 0.5 ? 1 : 2*val;
    
	return pixel * color;
}


//--------------------------------------------------------------------------------------
// Techniques
//--------------------------------------------------------------------------------------
technique RenderWithOutline
{
    pass P0
    {
		// Turn on alpha blending
		AlphaBlendEnable = true;
		DestBlend = INVSRCALPHA;
		SrcBlend = SRCALPHA;
		
		// Set the vertex and pixel shaders
        PixelShader  = compile ps_2_0 PixWithOutline();
    }
}

technique RenderWithoutOutline
{
    pass P0
    {
		// Turn on alpha blending
		AlphaBlendEnable = true;
		DestBlend = INVSRCALPHA;
		SrcBlend = SRCALPHA;
		
		// Set the vertex and pixel shaders
        PixelShader  = compile ps_2_0 PixWithoutOutline();
    }
}
