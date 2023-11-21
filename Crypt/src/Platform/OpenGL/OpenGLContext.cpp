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

		#ifdef HZ_ENABLE_ASSERTS
				int versionMajor;
				int versionMinor;
				glGetIntegerv(GL_MAJOR_VERSION, &versionMajor);
				glGetIntegerv(GL_MINOR_VERSION, &versionMinor);

				CRY_CORE_ASSERT(versionMajor > 4 || (versionMajor == 4 && versionMinor >= 5), "Crypt requires at least OpenGL version 4.5!");
		#endif

	}

	void OpenGLContext::SwapBuffers()
	{
		CRY_PROFILE_FUNCTION();

		glfwSwapBuffers(m_WindowHandle);
	}

}