#include "AGEpch.h"
#include "RenderCommand.h"

#include "Platform/OpenGl/OpenGLRendererAPI.h"

namespace AGE
{
	RendererAPI* RenderCommand::s_RendererAPI = new OpenGLRendererAPI;
}