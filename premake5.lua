-- Global variables
outputdir = "%{cfg.buildcfg}_%{cfg.system}_%{cfg.architecture}"
inputdir = "%{prj.name}/src"

-- Workspace definition (applies to all projects)
workspace "Filbert"
    configurations { "Debug", "Release" }
    platforms { "x86", "x64" }
    startproject "Sandbox"
    language "C++"
    architecture "x64"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("obj/" .. outputdir .. "/%{prj.name}")

    includedirs
    {
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

    filter "configurations:Release"
        defines { "NDEBUG" }
        optimize "Full"
    
    filter "system:windows"
        cppdialect "C++17"
        systemversion "latest"
        defines { "FLB_WINDOWS" }
    filter {}
    
    -- Project definitions
    project "Filbert"
        location "Filbert"
        kind "SharedLib"
        defines { "FLB_BUILD_DLL" }

        pchheader("filbertPCH.h")
        pchsource("Filbert/src/filbertPCH.cpp")

        postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/Sandbox/\"")
		}

    project "Sandbox"
        location "Sandbox"

        filter "configurations:Debug"
            kind "ConsoleApp"
        filter "configurations:Release"
            kind "WindowedApp"
        filter {}
            
        includedirs
        {
            "Filbert/src"
        }
        
        links
        {
            "Filbert"
        }
        