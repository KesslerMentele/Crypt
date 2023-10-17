workspace "Crypt"
 architecture ("x64")

 configurations
 {
	 "Debug",
	 "Release",
	 "Dist"
 }

 outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
 IncludeDir = {}
 IncludeDir["GLFW"] = "Crypt/vendor/GLFW/include"
 IncludeDir["Glad"] = "Crypt/vendor/Glad/include"
 IncludeDir["ImGui"] = "Crypt/vendor/imgui"


 include "Crypt/vendor/GLFW"
 include "Crypt/vendor/Glad"
 include "Crypt/vendor/imgui"

 project "Crypt"
	location "Crypt"
	kind "SharedLib"
	language "C++"
	staticruntime "off"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "crypch.h"
	pchsource "Crypt/src/crypch.cpp"

	files 
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}"
	}

	links
	{
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib",
		"dwmapi.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"

		defines
		{
			"CRY_PLATFORM_WINDOWS",
			"CRY_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

		postbuildcommands
		{
			("xcopy \"%{wks.location}bin\\" .. outputdir .. "\\Crypt\\*.*\" \"%{wks.location}bin\\" .. outputdir .. "\\Sandbox\\\" /Q /E /Y /I")
		}


	filter "configurations:Debug"
		defines "CRY_DEBUG"
		staticruntime"off"
		runtime "Debug"
		symbols "On"
	filter "configurations:Release"
		defines "CRY_RELEASE"
		runtime "Release"
		optimize "On"
	filter "configurations:Dist"
		defines "CRY_DIST"
		runtime "Release"
		optimize "On"

 project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	staticruntime "off"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
	files 
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Crypt/vendor/spdlog/include",
		"Crypt/src"
	}

	links
	{
		"Crypt"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "off"
		systemversion "latest"

		defines
		{
			"CRY_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "CRY_DEBUG"
		runtime "Debug"
		symbols "On"
	filter "configurations:Release"
		defines "CRY_RELEASE"
		runtime "Release"
		optimize "On"
	filter "configurations:Dist"
		defines "CRY_DIST"
		runtime "Release"
		optimize "On"