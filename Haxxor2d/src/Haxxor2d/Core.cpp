#include "Core.h"

#ifdef HB_DEBUG
	void GLClearError()
	{
		while(glGetError() != GL_NO_ERROR);
	}

	void GLCheckError(const char* file, int line)
	{
		while(GLenum err = glGetError())
		{
			HB_LOG("At %s line %d:\n[OpenGL Error]: %d\n", file, line, err);
			exit(-1);
		}
	}
#endif