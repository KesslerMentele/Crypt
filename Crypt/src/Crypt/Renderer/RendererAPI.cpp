#include "crypch.h"
#include "Crypt/Renderer/RendererAPI.h"

#include "Platform/OpenGL/OpenGLRendererAPI.h"

namespace Crypt {

	RendererAPI::API RendererAPI::s_API = RendererAPI::API::OpenGL;

	Scope<RendererAPI> RendererAPI::Create()
	{
		switch (s_API)
		{
		case RendererAPI::API::None: CRY_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
		case RendererAPI::API::OpenGL: return CreateScope<OpenGLRendererAPI>();
		}
		CRY_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

}