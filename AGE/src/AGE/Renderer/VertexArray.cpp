#include "AGEpch.h"
#include "VertexArray.h"

#include "Renderer.h"

#include "Platform/OpenGl/OpenGLVertexArray.h"

namespace AGE
{
	VertexArray* VertexArray::Create()
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::None:
				AGE_CORE_ASSERT(false, "RendererAPI::None is currently not supported");
				return nullptr;			
			case RendererAPI::OpenGl:
				return new OpenGLVertexArray();
		}
		AGE_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}
}