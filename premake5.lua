-- file lists
local configHeader = "gcom-config.h"
local pubIncludeDir =  "gcom/include"
local publicHeaders = pubIncludeDir .. "/gcom/**.h"
local privateHeaders = "gcom/src/**.h"
local gcomSource = "gcom/src/**.c"

-- GCOM
workspace "GCOM"
    configurations { "Debug", "Release" }
    location "build"

project "libGCOM"
    kind "SharedLib"
    language "C"
    location "build/gcom"
    files { configHeader, publicHeaders, privateHeaders, gcomSource}
    includedirs { _MAIN_SCRIPT_DIR, pubIncludeDir }
    defines { "GCOM_DLL_EXPORTS" }

project "genuuid"
    kind "ConsoleApp"
    language "C"
    location "build/utilites/genuuid"
    files { configHeader, "utilities/genuuid.c" }
    includedirs { _MAIN_SCRIPT_DIR }    
