#pragma once

#include "Core.h"
#include "Renderer.h"

namespace hb2d
{
	class HBAPI Window
	{
	public:
		Window(const char* title, int width = 1280, int height = 720);
		~Window();
		Renderer* GetRenderer();

		bool IsRunning() const { return !glfwWindowShouldClose(m_GLFWWindow); }

		void OnRender();
		void PollEvents();
	protected:
		GLFWwindow* m_GLFWWindow;
		Renderer* m_Renderer = nullptr;

	};
}