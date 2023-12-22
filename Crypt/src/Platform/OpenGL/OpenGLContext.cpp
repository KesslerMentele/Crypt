#include "crypch.h"
#include "Platform/OpenGL/OpenGLContext.h"

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
		CRY_PROFILE_FUNCTION();

		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		CRY_CORE_ASSERT(status, "Failed to initialize GLAD!");

		CRY_CORE_INFO("OpenGL Info: ");
		CRY_CORE_INFO("  Vendor: {0}", (const char*)glGetString(GL_VENDOR));
		CRY_CORE_INFO("  Renderer: {0}", (const char*)glGetString(GL_RENDERER));
		CRY_CORE_INFO("  Version: {0}", (const char*)glGetString(GL_VERSION));

		CRY_CORE_ASSERT(GLVersion.major > 4 || (GLVersion.major == 4 && GLVersion.minor >= 5), "Crypt requires at least OpenGL version 4.5!");

	}

	void OpenGLContext::SwapBuffers()
	{
		CRY_PROFILE_FUNCTION();

		glfwSwapBuffers(m_WindowHandle);
	}

}