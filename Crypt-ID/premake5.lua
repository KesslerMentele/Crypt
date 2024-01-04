project "Crypt-ID"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"src/**.h",
		"src/**.cpp"
	}

	includedirs
	{
		"%{wks.location}/Crypt/vendor/spdlog/include",
		"%{wks.location}/Crypt/src",
		"%{wks.location}/Crypt/vendor",
		"%{IncludeDir.glm}",
		"%{IncludeDir.entt}",
		"%{IncludeDir.imguizmo}"
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
