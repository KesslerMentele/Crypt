#include "crypch.h"
#include "Crypt/Renderer/VertexArray.h"

#include "Crypt/Renderer/Renderer.h"
#include "Platform/OpenGL/OpenGLVertexArray.h"

namespace Crypt {

	Ref<VertexArray> VertexArray::Create()
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None: CRY_CORE_ASSERT(false, "RendererAPI::None is currently not supported!") return nullptr;
		case RendererAPI::API::OpenGL: return CreateRef<OpenGLVertexArray>();
		}
		CRY_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

}
