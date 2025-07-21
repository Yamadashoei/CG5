#include "Test.hlsli"

Texture2D<float32_t4> gTexture : register(t0);
SamplerState gSampler : register(s0);

struct PixelShaderOutput
{
    float32_t4 color : SV_TARGET0;
};

PixelShaderOutput main(VertexShaderOutput input)
{
    PixelShaderOutput output;
    float32_t2 uv = input.texcoord;
    float32_t4 textureColor = gTexture.Sample(gSampler, uv);
    
    //grayscale
    float32_t value = dot(textureColor.rgb, float32_t3(0.2125f, 0.7154f, 0.0721f));
    float32_t4 color = float32_t4(value, value, value, textureColor.a); 

    // Vignette処理
    float2 center = float2(0.5f, 0.5f); // 画面の中心に設定
    float dist = distance(uv, center); // UV座標と中心の距離を計算
    float vignette = smoothstep(0.6f, 0.3f, dist); // vignette値を計算
    color.rgb *= vignette; // vignette

    output.color = color;
    return output;
}