#include "AGEpch.h"
#include "OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace AGE
{
	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
		:m_windowHandle(windowHandle)
	{
		AGE_CORE_ASSERT(windowHandle, "Window Handle Is Null!")
	}
	void OpenGLContext::Init()
	{
		glfwMakeContextCurrent(m_windowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		AGE_CORE_ASSERT(status, "Failed to initialize Glad!");
			
		AGE_CORE_INFO("OpenGL Info:");
		AGE_CORE_INFO("  Vendor: {0}", glGetString(GL_VENDOR));
		AGE_CORE_INFO("  Renderer: {0}", glGetString(GL_RENDERER));
		AGE_CORE_INFO("  Version: {0}", glGetString(GL_VERSION));
	}

	void OpenGLContext::SwapBuffers()
	{
		glfwSwapBuffers(m_windowHandle);
	}
}