#include "crypch.h"
#include "Crypt/Renderer/RenderCommand.h"

#include "Platform/OpenGL/OpenGLRendererAPI.h"

namespace Crypt {

	Scope<RendererAPI> RenderCommand::s_RendererAPI = RendererAPI::Create();
}