workspace "Crypt"
 architecture ("x64")
 startproject "Sandbox"

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
 IncludeDir["glm"] = "Crypt/vendor/glm"
 IncludeDir["stb_image"] = "Crypt/vendor/stb_image"

 group "Dependencies"
  include "Crypt/vendor/GLFW"
  include "Crypt/vendor/Glad"
  include "Crypt/vendor/imgui"
 group ""



 project "Crypt"
	location "Crypt"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17" 
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "crypch.h"
	pchsource "Crypt/src/crypch.cpp"

	files 
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/stb_image/**.h",
		"%{prj.name}/vendor/stb_image/**.cpp",
		"%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl"
	}

	defines
	{
		"_CRT_SECURE_NO_WARNINGS"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}",
		"%{IncludeDir.stb_image}"
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
		
		systemversion "latest"

		defines
		{
			"CRY_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

		postbuildcommands
		{
			("xcopy \"%{wks.location}bin\\" .. outputdir .. "\\Crypt\\*.*\" \"%{wks.location}bin\\" .. outputdir .. "\\Sandbox\\\" /Q /E /Y /I")
		}


	filter "configurations:Debug"
		defines "CRY_DEBUG"
		runtime "Debug"
		symbols "on"
	filter "configurations:Release"
		defines "CRY_RELEASE"
		runtime "Release"
		optimize "on"
	filter "configurations:Dist"
		defines "CRY_DIST"
		runtime "Release"
		optimize "on"

project "Crypt-ID"
	location "Crypt-ID"
	kind "ConsoleApp"
	language "C++"	
	cppdialect "C++17"
	staticruntime "on"

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
		"Crypt/src",
		"Crypt/vendor",
		"Crypt/vendor/glm"

	}

	links
	{
		"Crypt"
	}

	filter "system:windows"

		systemversion "latest"


	filter "configurations:Debug"
		defines "CRY_DEBUG"
		runtime "Debug"
		symbols "on"
	filter "configurations:Release"
		defines "CRY_RELEASE"
		runtime "Release"
		optimize "on"
	filter "configurations:Dist"
		defines "CRY_DIST"
		runtime "Release"
		optimize "on"
		
 project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"	
	cppdialect "C++17"
	staticruntime "on"

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
		"Crypt/src",
		"Crypt/vendor",
		"Crypt/vendor/glm"

	}

	links
	{
		"Crypt"
	}

	filter "system:windows"

		systemversion "latest"


	filter "configurations:Debug"
		defines "CRY_DEBUG"
		runtime "Debug"
		symbols "on"
	filter "configurations:Release"
		defines "CRY_RELEASE"
		runtime "Release"
		optimize "on"
	filter "configurations:Dist"
		defines "CRY_DIST"
		runtime "Release"
		optimize "on"

