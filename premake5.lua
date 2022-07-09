workspace "AGE"

	architecture "x64"
	startproject "Sandbox"
	configurations
	{	
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "AGE/vendor/GLFW/include"
IncludeDir["Glad"] = "AGE/vendor/Glad/include"
IncludeDir["ImGui"] = "AGE/vendor/imgui"
IncludeDir["glm"] = "AGE/vendor/glm"
IncludeDir["stb_image"] = "AGE/vendor/stb_image"


include "AGE/vendor/GLFW"
include "AGE/vendor/Glad"
include "AGE/vendor/imgui"

project "AGE"
	location "AGE"
	kind "StaticLib"
	language "C++"
	cppdialect "c++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "AGEpch.h"
	pchsource "AGE/src/AGEpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/stb_image/**.h",
		"%{prj.name}/vendor/stb_image/**.cpp",
		"%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl",
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
		"opengl32.lib"
	}

	filter "system:windows"				
		systemversion "latest"

		defines
		{
			"AGE_PLATFORM_WINDOWS",
			"AGE_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

	filter "configurations:Debug"
		defines "AGE_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "AGE_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "AGE_DIST"
		runtime "Release"
		optimize "on"

project "Sandbox"
	location "Sandbox"
	kind "consoleApp"
	language "C++"
	cppdialect "c++17"
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
		"AGE/vendor/spdlog/include",
		"AGE/src",
		"AGE/vendor",
		"%{IncludeDir.glm}"
	}

	links
	{
		"AGE"
	}

	filter "system:windows"				
		systemversion "latest"

		defines
		{
			"AGE_PLATFORM_WINDOWS"			
		}

	filter "configurations:Debug"
		defines "AGE_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "AGE_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "AGE_DIST"
		runtime "Release"
		optimize "on"