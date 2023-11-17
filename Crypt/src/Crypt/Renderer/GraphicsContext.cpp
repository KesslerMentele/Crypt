#include "crypch.h"
#include "Crypt/Renderer/GraphicsContext.h"

#include "Crypt/Renderer/Renderer.h"
#include "PLatform/OpenGL/OpenGLContext.h"


namespace Crypt {

	Scope<GraphicsContext> GraphicsContext::Create(void* window)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None: CRY_CORE_ASSERT(false, "RendererAPI:None is currently not supported!"); return nullptr;
		case RendererAPI::API::OpenGL: return CreateScope<OpenGLContext>(static_cast<GLFWwindow*>(window));
		}

		CRY_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}
}