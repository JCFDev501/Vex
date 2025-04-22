workspace "Vex"
architecture "x64"

configurations {"Debug", "Release", "Dist"}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Vex"
location "Vex"
kind "SharedLib"
language "C++"

targetdir("bin/" .. outputdir .. "/%{prj.name}")
objdir("bin-int/" .. outputdir .. "/%{prj.name}")

files {"%{prj.name}/src/**.h", "%{prj.name}/src/**.cpp"}

includedirs {"%{prj.name}/src", "%{prj.name}/vendor/spdlog/include"}

filter "system:windows"
cppdialect "C++20"
staticruntime "On"
systemversion "latest"

defines {"VEX_PLATFORM_WINDOWS", "VEX_BUILD_DLL"}

postbuildcommands {("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")}

filter "configurations:Debug"
defines "VEX_DEBUG"
symbols "On"
buildoptions "/utf-8"

filter "configurations:Release"
defines "VEX_RELEASE"
optimize "On"
buildoptions "/utf-8"

filter "configurations:Dist"
defines "VEX_DIST"
optimize "On"
buildoptions "/utf-8"

project "Sandbox"
location "Sandbox"
kind "ConsoleApp"
language "C++"

targetdir("bin/" .. outputdir .. "/%{prj.name}")
objdir("bin-int/" .. outputdir .. "/%{prj.name}")

files {"%{prj.name}/src/**.h", "%{prj.name}/src/**.cpp"}

includedirs {"Vex/vendor/spdlog/include", "Vex/src"}

links {"Vex"}

filter "system:windows"
cppdialect "C++20"
staticruntime "On"
systemversion "latest"

defines {"VEX_PLATFORM_WINDOWS"}

filter "configurations:Debug"
defines "VEX_DEBUG"
symbols "On"
buildoptions "/utf-8"

filter "configurations:Release"
defines "VEX_RELEASE"
optimize "On"
buildoptions "/utf-8"

filter "configurations:Dist"
defines "VEX_DIST"
optimize "On"
buildoptions "/utf-8"

