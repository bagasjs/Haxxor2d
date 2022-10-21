PROJECT_VENDORS = "%{wks.location}/vendors"


project "Sandbox"
	kind "ConsoleApp"
	language "C++"
	targetdir("%{wks.location}/bin/%{cfg.buildcfg}")
	objdir("%{wks.location}/bin-int/%{cfg.buildcfg}/%{prj.name}")

	files { 
		"%{prj.location}/src/**.cpp", 
		"%{prj.location}/src/**.h" 
	}

	includedirs {
		"%{wks.location}/Haxxor2d/src",
		"%{wks.location}/Haxxor2d/src/Haxxor2d",
		"%{wks.location}/Haxxor2d/src/Haxxor2d/Renderer",
		PROJECT_VENDORS .. "/glfw/include",
		PROJECT_VENDORS .. "/glad/include",
	}

	links {
		"Haxxor2d"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines {
			"HB_PLATFORM_WINDOWS",
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