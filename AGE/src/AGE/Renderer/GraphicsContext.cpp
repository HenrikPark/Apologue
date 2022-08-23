#include "AGEpch.h"
#include "AGE/Renderer/GraphicsContext.h"

#include "AGE/Renderer/Renderer.h"
#include "Platform/OpenGL/OpenGLContext.h"

namespace AGE
{

	Scope<GraphicsContext> GraphicsContext::Create(void* window)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None:    AGE_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
		case RendererAPI::API::OpenGL:  return CreateScope<OpenGLContext>(static_cast<GLFWwindow*>(window));
		}

		AGE_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

}