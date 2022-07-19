#include "AGEpch.h"
#include "Texture.h"

#include "Renderer.h"
#include "Platform/OpenGl/OpenGLTexture.h"

namespace AGE
{
	Ref<Texture2D> Texture2D::Create(uint32_t width, uint32_t height)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None:
			AGE_CORE_ASSERT(false, "RendererAPI::None is currently not supported");
			return nullptr;
		case RendererAPI::API::OpenGL:
			return CreateRef<OpenGLTexture2D>(width, height);
		}
		AGE_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
		
	}
	Ref<Texture2D> Texture2D::Create(const std::string& path)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None:
			AGE_CORE_ASSERT(false, "RendererAPI::None is currently not supported");
			return nullptr;
		case RendererAPI::API::OpenGL:
			return CreateRef<OpenGLTexture2D>(path);
		}
		AGE_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;

	}
}