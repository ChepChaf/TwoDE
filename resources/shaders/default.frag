#version 330 core

out vec4 out_Color;

in vec2 TexCoord;

uniform sampler2D texture1;

void main()
{
    vec4 color = texture(texture1, TexCoord);

    if (color.a == 0.0)
    {
        discard;
    }
    else
    {
        out_Color = color;
    }
}