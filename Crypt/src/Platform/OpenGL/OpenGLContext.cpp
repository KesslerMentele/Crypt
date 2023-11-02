#include "crypch.h"
#include "OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace Crypt{

	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
		: m_WindowHandle(windowHandle)
	{
		CRY_CORE_ASSERT(windowHandle, "Window handle is null!")
	}

	void OpenGLContext::Init()
	{
		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		CRY_CORE_ASSERT(status, "Failed to initialize GLAD!");

		CRY_CORE_INFO("OpenGL Info: ");
		CRY_CORE_INFO("  Vendor: {0}", (const char*)glGetString(GL_VENDOR));
		CRY_CORE_INFO("  Renderer: {0}", (const char*)glGetString(GL_RENDERER));
		CRY_CORE_INFO("  Version: {0}", (const char*)glGetString(GL_VERSION));

	}

	void OpenGLContext::SwapBuffers()
	{


		glfwSwapBuffers(m_WindowHandle);
	}

}