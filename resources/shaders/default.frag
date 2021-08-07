#version 330 core

struct Material {
    vec3 diffuse;
};

uniform Material material;

out vec4 out_Color;

in vec2 TexCoord;

uniform sampler2D texture1;

void main()
{
    vec4 texColor = texture(texture1, TexCoord);

    if (texColor.a == 0.0)
    {
        discard;
    }
    else
    {
        out_Color = vec4(texColor.rgb * material.diffuse, texColor.a);
    }
}