workspace "Amigo"
	architecture "x64"
	configurations {
		"Debug",
		"Release",
		"Dist"
	}

outdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Amigo"
	location "Amigo"
	kind "SharedLib"
	language "C++"
	targetdir ("bin/" .. outdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outdir .. "/%{prj.name}")

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs {
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:Windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
		defines {
			"AMIGO_PLATFORM_WINDOWS",
			"AMIGO_BUILD_DLL"
		}
		postbuildcommands {
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outdir .. "/Magicbox")
		}

	filter "configurations:Debug"
		defines "AMIGO_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "AMIGO_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "AMIGO_DIST"
		optimize "On"

project "Magicbox"
	location "Magicbox"
	kind "ConsoleApp"
	language "C++"
	targetdir ("bin/" .. outdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outdir .. "/%{prj.name}")

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs {
		"Amigo/vendor/spdlog/include",
		"Amigo/src"
	}

	links {
		"Amigo"
	}

	filter "system:Windows"
		system "windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
		defines { 
			"AMIGO_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "AMIGO_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "AMIGO_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "AMIGO_DIST"
		optimize "On"