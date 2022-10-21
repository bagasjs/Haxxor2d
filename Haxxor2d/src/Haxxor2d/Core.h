#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <cstdlib>

#ifdef HB_DEBUG
	#include <stdio.h>
	#define HB_LOG(...) printf(__VA_ARGS__);
	void GLClearError();
	void GLCheckError(const char* file, int line);
	#define GL_CALL(x) GLClearError();x;GLCheckError(__FILE__, __LINE__)
#else
	#define HB_LOG(...)
	#define GL_CALL(X)
#endif

#ifdef HB_PLATFORM_WINDOWS
	#ifdef HB_BUILD_DLL
		#define HBAPI __declspec(__dllexport)
	#else
		#define HBAPI __declspec(__dllimport)
	#endif
#endif