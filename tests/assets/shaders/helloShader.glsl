#shader vertex
#version 410
layout (location = 0) in vec2 position;
layout (location = 1) in vec3 attribColor;

out vec3 color;

void main()
{
    gl_Position = vec4(position, 0.0, 1.0);
    color = attribColor;
}

#shader fragment
#version 410
in vec3 color;
out vec4 FragColor;

void main()
{
    FragColor = vec4(color, 1.0);
}
