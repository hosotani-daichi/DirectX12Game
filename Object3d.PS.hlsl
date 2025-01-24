#include"Object3d.hlsli"

struct PixelShaderOutput
{
    float32_t4 color : SV_TARGET0;
};

Texture2D<float32_t4> gTexture : register(t0);
SamplerState gSampler : register(s0);

struct Material
{
    float32_t4 color;
    int32_t enableLighting;
    float32_t4x4 uvTransform;
    float32_t shininess;
};

ConstantBuffer<Material> gMaterial : register(b0);
ConstantBuffer<Camera> gCamera : register(b2);


PixelShaderOutput main(VertexShaderOutput input)
{
    PixelShaderOutput output;
    output.color = gMaterial.color;
    float32_t4 textureColor = gTexture.Sample(gSampler, input.texcoord);
    output.color = gMaterial.color * textureColor;
    
    if (gMaterial.enableLighting != 0)
    {
        float cos = sturate(dot(normalize(input.normal), -gDirectionalLight.direction));
        output.color = gMaterial.color * textureColor * gDirectionalLight.color * cos * gDirectionalLight.intensity;
    }
    else
    {
        output.color = gMaterial.color * textureColor;
    }
    
    float32_t3 reflectLight = reflect(gDirectionalLight.direction, normalize(input.normal));
    
    //入射光の反射ベクトルを求める。数式でいうところのr
    float32_t3 reflectLight = reflect(normalize(gDirectionalLight), normalize(input.normalize));
    //拡散反射
    float32_t3 diffuse = gMaterial.color.rgb * textureColor.rgb * gDirectionalLight.color.rgb * cos * gDirectionalLight.intensity;
    //鏡面反射
    float32_t3 specular = gDirectionalLight.color.rgb * gDirectionalLight.intensity * specularPow* float32_t3(1.0f, 1.0f, 1.0f);
    //拡散反射+鏡面反射
    output.color.rgb = diffuse + specular;
    //アルファは今まで通り
    output.color.a = gMaterial.color.a * textureColor.a;
    
    return output;
}

//half lambert
float NdotL = dot(normalize(input.normal), normalize(-gDirectionalLight.direction));
float cos = pow(NdotL * 0.5f + 0.5f, 2.0f);
float32_t3 toEye = normalize(gCamera.worldPosition - input.worldPosition);

float RdotE = dot(reflectLight, toEye);
float specularPow = pow(saturate(RdotE), gMaterial.shininess); //反射強度

struct DirectionalLight
{
    float32_t4 color;
    float32__t3 direction;
    float intensity;
};



