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
		      os.getenv("MSDKDIR") .. "/SDK/MEngine/Libs",
		      os.getenv("MSDKDIR") .. "/SDK/MIngEd/Libs",
		      "." }

	includedirs { os.getenv("MSDKDIR") .. "/SDK/MCore/Includes",
		      os.getenv("MSDKDIR") .. "/SDK/MEngine/Includes",
		      os.getenv("MSDKDIR") .. "/SDK/MIngEd/Includes",
		      "Shiny/include" }

	targetprefix ""

	defines { "MPLUGIN_DYNAMIC" }

	prebuildcommands  ("Mnpk MProfiler.npk data")
	prebuildcommands  ("MEmbedder MProfiler.npk MProfiler_npk.h MProfiler_npk")
	postbuildcommands ("MPlugin install MProfiler.so")

	-- link to it
	links { "MCore", "MEngine", "Shiny" }

	-- allow making a debug build, always useful
        configuration "Debug"
	    defines { "DEBUG" }
	    flags { "Symbols" }
        configuration "Release"
	    defines { "NDEBUG" }
	    flags { "Optimize" }
