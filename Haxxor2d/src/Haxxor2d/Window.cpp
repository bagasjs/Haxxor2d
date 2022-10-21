#include "Window.h"

namespace hb2d
{
	Window::Window(const char* title, int width, int height)
	{

		if(!glfwInit())
			exit(-1);

		m_GLFWWindow = glfwCreateWindow(width, height, title, NULL, NULL);
		if(!m_GLFWWindow)
		{

			glfwTerminate();
			exit(-1);
		}

		glfwMakeContextCurrent(m_GLFWWindow);
		glfwSwapInterval(1);
		if(!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress))
		{
			exit(-1);
		}

		GL_CALL(glViewport(0, 0, width, height));
	}

	Renderer* Window::GetRenderer()
	{
		if(m_Renderer == nullptr)
		{
			m_Renderer = new Renderer();
		}
		return m_Renderer;
	}

	void Window::OnRender()
	{
		glfwSwapBuffers(m_GLFWWindow);
	}

	void Window::PollEvents()
	{
		glfwPollEvents();
	}

	Window::~Window()
	{
		delete m_Renderer;
		glfwTerminate();
	}
}