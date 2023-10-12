workspace "Crypt"
 architecture ("x64")

 configurations
 {
	 "Debug",
	 "Release",
	 "Dist"
 }

 outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

 project "Crypt"
	location "Crypt"
	kind "SharedLib"
	language "C++"

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
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"CRY_PLATFORM_WINDOWS",
			"CRY_BUILD_DLL"
		}

		postbuildcommands
		{
			("xcopy \"%{wks.location}bin\\" .. outputdir .. "\\Crypt\\*.*\" \"%{wks.location}bin\\" .. outputdir .. "\\Sandbox\\\" /Q /E /Y /I")
		}


	filter "configurations:Debug"
		defines "CRY_DEBUG"
		symbols "On"
	filter "configurations:Release"
		defines "CRY_RELEASE"
		optimize "On"
	filter "configurations:Dist"
		defines "CRY_DIST"
		optimize "On"

 project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

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
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"CRY_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "CRY_DEBUG"
		symbols "On"
	filter "configurations:Release"
		defines "CRY_RELEASE"
		optimize "On"
	filter "configurations:Dist"
		defines "CRY_DIST"
		optimize "On"