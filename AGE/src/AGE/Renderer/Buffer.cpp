#include "AGEpch.h"
#include "Buffer.h"

#include "Renderer.h"

#include "Platform/OpenGl/OpenGLBuffer.h"
namespace AGE
{
	Ref<VertexBuffer> VertexBuffer::Create(uint32_t size)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None:
			AGE_CORE_ASSERT(false, "RendererAPI::None is currently not supported");
			return nullptr;
			break;
		case RendererAPI::API::OpenGL:
			return CreateRef<OpenGLVertexBuffer>(size);
			break;
		}
		AGE_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}
	Ref<VertexBuffer> VertexBuffer::Create(float* vertices, uint32_t size)
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::API::None:
				AGE_CORE_ASSERT(false, "RendererAPI::None is currently not supported");
				return nullptr;
				break;
			case RendererAPI::API::OpenGL:
				return CreateRef<OpenGLVertexBuffer>(vertices,size);
				break;
		}
		AGE_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

	Ref<IndexBuffer> IndexBuffer::Create(uint32_t* indices, uint32_t size)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None:
			AGE_CORE_ASSERT(false, "RendererAPI::None is currently not supported");
			return nullptr;
			break;
		case RendererAPI::API::OpenGL:
			return CreateRef<OpenGLIndexBuffer>(indices, size);
			break;

		default:
			break;
		}
		AGE_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}
}