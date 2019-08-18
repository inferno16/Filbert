-- Global variables
outputdir = "%{cfg.buildcfg}_%{cfg.system}_%{cfg.architecture}"
inputdir = "%{prj.name}/src"

-- Workspace definition (applies to all projects)
workspace "Filbert"
    configurations { "Debug", "Release" }
    platforms { "x86", "x64" }
    startproject "Sandbox"
    language "C++"
    cppdialect "C++17"
    staticruntime "On"
    architecture "x64"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("obj/" .. outputdir .. "/%{prj.name}")

    includedirs
    {
        "Filbert/src",
        "Filbert/vendor/spdlog/include"
    }

    vpaths 
    {
        ["Header Files"] = {"**.hpp", "**.h" },
        ["Source Files"] = { "**.cpp", "**.cc", "**.c" }
    }

    files
    {
        inputdir .. "/**.h",
        inputdir .. "/**.cpp"
    }

    filter "platforms:x86"
        architecture "x86"

    filter "platforms:x64"
        architecture "x64"
        
    filter "configurations:Debug"
        defines { "DEBUG" }
        optimize "Debug"
        symbols "On"

    filter "configurations:Release"
        defines { "NDEBUG" }
        optimize "Full"
    
    filter "system:windows"
        systemversion "latest"
        defines { "FLB_WINDOWS" }
    filter {}
    
    -- Project definitions
    include "Filbert/vendor/GLFW"
    include "Filbert/vendor/Glad"

    project "Filbert"
        location "Filbert"
        kind "StaticLib"
        defines { "GLFW_INCLUDE_NONE" }

        pchheader("filbertPCH.h")
        pchsource("Filbert/src/filbertPCH.cpp")

        links 
        {
            "GLFW",
            "Glad",
            "opengl32.lib"
        }

        includedirs
        {
            "Filbert/vendor/GLFW/include",
            "Filbert/vendor/Glad/include"
        }

    project "Sandbox"
        location "Sandbox"

        filter "configurations:Debug"
            kind "ConsoleApp"
        filter "configurations:Release"
            kind "WindowedApp"
        filter {}
        
        links
        {
            "Filbert"
        }
        