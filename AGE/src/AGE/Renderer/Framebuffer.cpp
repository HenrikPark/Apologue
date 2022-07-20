#include "AGEpch.h"
#include "Framebuffer.h"

#include "Renderer.h"
#include "Platform/OpenGl/OpenGLFramebuffer.h"

namespace AGE
{
	Ref<Framebuffer> Framebuffer::Create(const FramebufferSpecification& spec)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None:
			AGE_CORE_ASSERT(false, "RendererAPI::None is currently not supported");
			return nullptr;
			break;
		case RendererAPI::API::OpenGL:
			return CreateRef<OpenGLFramebuffer>(spec);
			break;
		}
		AGE_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}
}