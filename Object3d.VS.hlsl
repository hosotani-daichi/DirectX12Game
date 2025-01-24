#include "Object3d.hlsli"

struct TransformationMatrix
{
    float32_t4x4 WVP;
    float32_t4x4 World;
};
ConstantBuffer<TransformationMatrix> gTransformationMatrix : register(b0);

struct VertexShaderInput
{
    float32_t4 position : POSITION0;
    float32_t2 texcoord : TEXCOORD0;

};

VertexShaderOutput main(VertexShaderInput input)
{
    VertexShaderOutput output;
    output.position = mul(input.position, gTransformationMatrix.WVP); //output.position = input.position
    output.texcoord = input.texcoord;
    output.worldPosition = mul(input.position, gTransformationMatrix.World).xyz;
    return output;
}

struct Camera
{
    float32_t3 worldPosition;
};
