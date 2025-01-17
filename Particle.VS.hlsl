#include "Particle.hlsli"

struct TransformationMatrix
{
    float32_t4x4 WVP;
};
StructuredBuffer<TransformationMatrix> gTransformationMatrices : register(t0);

struct VertexShaderInput
{
    float32_t4 position : POSITION0;
    float32_t2 texcoord : TEXCOORD0;
};




VertexShaderOutput main(VertexShaderInput input)
{
    VertexShaderOutput output;
    output.position = mul(input.position, gTransformationMatrices[InstanceID].WVP); //output.position = input.position
    output.texcoord = input.texcoord;
    return output;
}

