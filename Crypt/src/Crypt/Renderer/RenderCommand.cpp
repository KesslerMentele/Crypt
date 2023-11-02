#include "crypch.h"
#include "RenderCommand.h"

#include "Platform/OpenGL/OpenGLRendererAPI.h"

namespace Crypt {

	RendererAPI* RenderCommand::s_RendererAPI = new OpenGLRendererAPI;
}