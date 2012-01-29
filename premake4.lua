-- Maratis Profiler plugin solution
solution "MProfiler"
    configurations { "Debug", "Release" }

    include "Shiny"

    project "MProfiler"
        kind "SharedLib"
        language "C++"
        files { "**.h", "**.cpp" }

	-- add Maratis SDK to our search paths
	libdirs { os.getenv("MSDKDIR") .. "/SDK/MCore/Libs",
		      os.getenv("MSDKDIR") .. "/SDK/MGui/Libs",
		      os.getenv("MSDKDIR") .. "/SDK/MEngine/Libs",
		      "." }

	includedirs { os.getenv("MSDKDIR") .. "/SDK/MCore/Includes",
		      os.getenv("MSDKDIR") .. "/SDK/MGui/Includes",
		      os.getenv("MSDKDIR") .. "/SDK/MEngine/Includes",
		      "Shiny/include" }

	-- link to it
	links { "MCore", "MEngine", "MGui", "Shiny" }

	-- allow making a debug build, always useful
        configuration "Debug"
	    defines { "DEBUG" }
	    flags { "Symbols" }
        configuration "Release"
	    defines { "NDEBUG" }
	    flags { "Optimize" }
