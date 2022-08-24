include "./vendor/premake/premake_customization/solution_items.lua"
include "Dependencies.lua"

workspace "AGE"
	architecture "x86_64"
	startproject "AGE-Editor"

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
	include "AGE/vendor/Box2D"
	include "AGE/vendor/GLFW"
	include "AGE/vendor/Glad"
	include "AGE/vendor/imgui"
	include "AGE/vendor/yaml-cpp"
group ""

group "Core"
	include "AGE"
	include "AGE-ScriptCore"
group ""

group "Tools"
	include "AGE-Editor"
group ""

group "Misc"
	include "Sandbox"
group ""