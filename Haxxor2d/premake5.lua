PROJECT_VENDORS = "%{wks.location}/vendors"


project "Haxxor2d"
	kind "SharedLib"
	language "C++"
	targetdir("%{wks.location}/bin/%{cfg.buildcfg}")
	objdir("%{wks.location}/bin-int/%{cfg.buildcfg}/%{prj.name}")

	files { 
		"%{prj.location}/src/**.cpp", 
		"%{prj.location}/src/**.h" 
	}

	includedirs {
		"%{prj.location}/src",
		"%{prj.location}/src/Haxxor2d",
		"%{prj.location}/src/Haxxor2d/Renderer",
		PROJECT_VENDORS .. "/glfw/include",
		PROJECT_VENDORS .. "/glad/include",
	}

	links {
		"glfw",
		"Glad",
		"opengl32",
		"gdi32",
		"user32",
		"kernel32",
		"mingw32",
		"dwmapi"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines {
			"HB_PLATFORM_WINDOWS",
			"HB_BUILD_DLL",
		}
	
	filter "configurations:Debug"
		defines "HB_DEBUG"
		symbols "On"
	
	filter "configurations:Release"
		defines "HB_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "HB_DIST"
		optimize "On"