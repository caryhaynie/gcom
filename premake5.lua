local uv = require("tools/uv")

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
    files { configHeader, "utilities/genuuid/src/genuuid.c", "utilities/genuuid/src/genuuid.h" }
    includedirs { _MAIN_SCRIPT_DIR }
    filter { "system:Windows"}
        files { "utilities/genuuid/src/platform_win32.c" }
    filter { "system:bsd or linux or macosx" }
        files { "utilities/genuuid/src/platform_posix.c" }