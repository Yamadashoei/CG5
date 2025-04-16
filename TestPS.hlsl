struct PixelShaderOutput
{
    float4 color : SV_TAREGET0;
};

PixelShaderOutput main()
{
    PixelShaderOutput output;
    output.color = float4(1.0f, 1.0f, 1.0f, 1.0f); // Red color
    return output;
}