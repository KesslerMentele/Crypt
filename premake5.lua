include "./vendor/premake/premake_customization/solution_items.lua"
include "Dependencies.lua"

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

