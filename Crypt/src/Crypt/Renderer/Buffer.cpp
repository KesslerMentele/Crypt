#include "crypch.h"
#include "Crypt/Renderer/Buffer.h"

#include "Crypt/Renderer/Renderer.h"

#include "Platform/OpenGL/OpenGLBuffer.h"

namespace Crypt {
	Ref<VertexBuffer> VertexBuffer::Create(uint32_t size)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None: CRY_CORE_ASSERT(false, "RendererAPI::None is currently not supported!") return nullptr;
		case RendererAPI::API::OpenGL: return CreateRef<OpenGLVertexBuffer>(size);
		}
		CRY_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}
	Ref<VertexBuffer> VertexBuffer::Create(float* vertices, uint32_t size)
	{

		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None: CRY_CORE_ASSERT(false,"RendererAPI::None is currently not supported!") return nullptr;
		case RendererAPI::API::OpenGL: return CreateRef<OpenGLVertexBuffer>(vertices, size);
		}
		CRY_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

	Ref<IndexBuffer> IndexBuffer::Create(uint32_t* indices, uint32_t size)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None: CRY_CORE_ASSERT(false, "RendererAPI::None is currently not supported!") return nullptr;
		case RendererAPI::API::OpenGL: return CreateRef<OpenGLIndexBuffer>(indices, size);
		}
		CRY_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

}