struct VertexShaderOutPut
{
    float4 position : SV_POSITION;
};

struct VertexShaderInput
{
    float4 position : POSITION0;
};

VertexShaderOutPut main(VertexShaderInput input)
{
    VertexShaderOutPut output;
    output.position = input.position;
    return output;
}