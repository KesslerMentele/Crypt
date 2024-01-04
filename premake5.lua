include "./vendor/premake/premake_customization/solution_items.lua"

workspace "Crypt"
	architecture "x86_64"
	startproject "Crypt-ID"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

	solution_items
	{
		".editorconfig"
	}
	
	flags
	{
		"MultiProcessorCompile"
	}

	outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
	IncludeDir = {}
	IncludeDir["GLFW"] = "%{wks.location}/Crypt/vendor/GLFW/include"
	IncludeDir["Glad"] = "%{wks.location}/Crypt/vendor/Glad/include"
	IncludeDir["ImGui"] = "%{wks.location}/Crypt/vendor/imgui"
	IncludeDir["glm"] = "%{wks.location}/Crypt/vendor/glm"
	IncludeDir["entt"] = "%{wks.location}/Crypt/vendor/entt/include"
	IncludeDir["yaml_cpp"] = "%{wks.location}/Crypt/vendor/yaml-cpp/include"
	IncludeDir["stb_image"] = "%{wks.location}/Crypt/vendor/stb_image"
	IncludeDir["ImGuizmo"] = "%{wks.location}/Crypt/vendor/imguizmo"

	group "Dependencies"
		include "vendor/premake"
		include "Crypt/vendor/GLFW"
		include "Crypt/vendor/Glad"
		include "Crypt/vendor/imgui"
		include "Crypt/vendor/yaml-cpp"
	group ""

include "Crypt"
include "Sandbox"
include "Crypt-ID"

