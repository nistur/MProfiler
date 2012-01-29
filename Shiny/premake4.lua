project "Shiny"
  kind "StaticLib"
  language "C++"
  files { "include/**.h", "src/**.c" }

  includedirs { "include" }
	
  targetdir("..")
  
  defines { "SHINY_INLINE=inline" }
  

  -- making a debug build, always useful
  configuration "Debug"
    defines { "DEBUG" }
    flags { "Symbols" }
  configuration "Release"
    defines { "NDEBUG" }
    flags { "Optimize" }
