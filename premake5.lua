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
