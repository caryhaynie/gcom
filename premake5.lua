-- GCOM
workspace "GCOM"
    configurations { "Debug", "Release" }
    location "build"

project "libGCOM"
    kind "SharedLib"
    language "C"
    location "build/gcom"
    files { "include/**.h", "libraries/**.c"}
    includedirs { "include" }

project "genuuid"
    kind "ConsoleApp"
    language "C"
    location "build/utilites/genuuid"
    files { "libraries/gcom-config.h", "utilities/genuuid.c" }
    includedirs { "libraries" }
