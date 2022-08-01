project "AGE-Editor"
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
		"%{wks.location}/AGE/vendor/spdlog/include",
		"%{wks.location}/AGE/src",
		"%{wks.location}/AGE/vendor",
		"%{IncludeDir.glm}",
		"%{IncludeDir.entt}"
	}

	links
	{
		"AGE"
	}

	filter "system:windows"
		systemversion "latest"

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
