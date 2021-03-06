#include "AGEpch.h"
#include "VertexArray.h"

#include "Renderer.h"

#include "Platform/OpenGl/OpenGLVertexArray.h"

namespace AGE
{
	Ref<VertexArray> VertexArray::Create()
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::API::None:
				AGE_CORE_ASSERT(false, "RendererAPI::None is currently not supported");
				return nullptr;			
			case RendererAPI::API::OpenGL:
				return std::make_shared<OpenGLVertexArray>();
		}
		AGE_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}
}