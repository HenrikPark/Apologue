#include "AGEpch.h"
#include "OpenGLVertexArray.h"

#include "glad/glad.h"

namespace AGE
{

	static GLenum ShaderDataTypeToOpenGLBaseType(ShaderDataType type)
	{
		switch (type)
		{
			case AGE::ShaderDataType::Float:	return GL_FLOAT;
			case AGE::ShaderDataType::Float2:	return GL_FLOAT;
			case AGE::ShaderDataType::Float3:	return GL_FLOAT;
			case AGE::ShaderDataType::Float4:	return GL_FLOAT;
			case AGE::ShaderDataType::Mat3:		return GL_FLOAT;
			case AGE::ShaderDataType::Mat4:		return GL_FLOAT;
			case AGE::ShaderDataType::Int:		return GL_INT;
			case AGE::ShaderDataType::Int2:		return GL_INT;
			case AGE::ShaderDataType::Int3:		return GL_INT;
			case AGE::ShaderDataType::Int4:		return GL_INT;
			case AGE::ShaderDataType::Bool:		return GL_BOOL;
		}
		AGE_CORE_ASSERT(false, "Unknown ShadeDataType!");
		return 0;
	}


	OpenGLVertexArray::OpenGLVertexArray()
	{
		glCreateVertexArrays(1, &m_RendererID);
	}
	OpenGLVertexArray::~OpenGLVertexArray()
	{
		glDeleteVertexArrays(1, &m_RendererID);
	}
	void OpenGLVertexArray::Bind() const
	{
		glBindVertexArray(m_RendererID);
	}

	void OpenGLVertexArray::Unbind() const
	{
		glBindVertexArray(0);
	}

	void OpenGLVertexArray::AddVertexBuffer(const Ref<VertexBuffer>& vertexBuffer)
	{
		AGE_CORE_ASSERT(vertexBuffer->GetLayout().GetElements().size(), "VertexBuffer has no layout!");
		
		glBindVertexArray(m_RendererID);
		vertexBuffer->Bind();

		uint32_t index = 0;
		const auto& layout = vertexBuffer->GetLayout();
		for (const auto& element : layout)
		{
			glEnableVertexAttribArray(index);
			glVertexAttribPointer(index,
				element.GetComponentCount(),
				ShaderDataTypeToOpenGLBaseType(element.Type),
				element.Normalized ? GL_TRUE : GL_FALSE,
				layout.GetStride(),
				(const void*)element.Offset);
			index++;
		}
		m_VertexBuffers.push_back(vertexBuffer);
	}

	void OpenGLVertexArray::SetIndexBuffer(const Ref<IndexBuffer>& indexBuffer)
	{
		glBindVertexArray(m_RendererID);
		indexBuffer->Bind();

		m_IndexBuffer = indexBuffer;
	}
}