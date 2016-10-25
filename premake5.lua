-- GCOM
workspace "GCOM"
    configurations { "Debug", "Release" }
    location "build"

project "libGCOM"
    kind "SharedLib"
    language "C"
    location "build/gcom"
    files { "gcom/include/gcom/**.h", "gcom/src/**.c"}
    includedirs { "gcom/include" }

project "genuuid"
    kind "ConsoleApp"
    language "C"
    location "build/utilites/genuuid"
    files { "gcom/include/gcom/gcom-config.h", "utilities/genuuid.c" }
    includedirs { "gcom/include" }
