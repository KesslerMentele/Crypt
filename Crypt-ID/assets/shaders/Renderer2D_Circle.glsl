// Renderer2D Circle Shader

#type vertex
#version 450 core

layout(location = 0) in vec3 a_WorldPosition;
layout(location = 1) in vec3 a_LocalPosition;
layout(location = 2) in vec4 a_Color;
layout(location = 3) in float a_Thickness;
layout(location = 4) in float a_Fade;
layout(location = 5) in int a_EntityID;

layout(std140, binding = 0) uniform Camera
{
	mat4 u_ViewProjection;
};

struct VertexOutput
{
	vec3 LocalPosition;
	vec4 Color;
	float Thickness;
	float Fade;

};

layout(location = 0) out VertexOutput Output;
layout(location = 3) out flat int v_EntityID;

void main()
{
	Output.LocalPosition = a_LocalPosition;
	Output.Color = a_Color;
	Output.Thickness = a_Thickness;
	Output.Fade = a_Fade;
	v_EntityID = a_EntityID;

	gl_Position = u_ViewProjection * vec4(a_Position, 1.0);
}

#type fragment
#version 450 core

layout(location = 0) out vec4 color;
layout(location = 1) out int color2;

struct VertexOutput
{
	vec3 LocalPosition;
	vec4 Color;
	float Thickness;
	float Fade;
};

layout (location = 0) in VertexOutput Input;
layout (location = 3) in flat int v_EntityID;

void main()
{
	vec2 uv = fragCoord / iResolution.xy * 2.0 - 1.0;
	float aspect = iResolution.x / iResolution.y;
	uv.x *= aspect;

	float distance = 1.0 - length(uv);
	vec3 clolr = vec3(smoothstep(Input.Thickness + Input.fade, distance));

	fragColor = vec4(color, 1.0);
	fragColor.rgb *= Input.Color;
}
