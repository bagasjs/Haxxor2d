#pragma once

extern int Main(int argc, char** argv);

#ifdef HB_PLAFORM_WINDOWS
	#include <Windows.h>
	int APIENTRY WinMain(HINSTANCE hInst, HINSTANCE hInstPrev, PSTR cmdline, int cmdshow)
	{
		return Main(__argc, __argv);
	}
#else
	int main(int argc, char** argv)
	{
		return Main(argc, argv);
	}
#endif