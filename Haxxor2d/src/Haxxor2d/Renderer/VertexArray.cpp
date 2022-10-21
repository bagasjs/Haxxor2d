#include "VertexArray.h"

namespace hb2d
{
	VertexArray::VertexArray()
	{
		GL_CALL(glGenVertexArrays(1, &m_RendererID));
	}

	VertexArray::~VertexArray()
	{
		GL_CALL(glDeleteVertexArrays(1, &m_RendererID));
	}

	void VertexArray::Bind() const
	{
		GL_CALL(glBindVertexArray(m_RendererID));
	}

	void VertexArray::Unbind() const
	{
		GL_CALL(glBindVertexArray(0));
	}

	void VertexArray::AssignBuffer(const VertexBuffer& vb, const BufferLayout& layout) const
	{
		Bind();
		const auto& elements = layout.GetElements();
		unsigned int offset = 0;
		for(unsigned int i = 0; i < elements.size(); i++)
		{
			const auto& element = elements[i];
			GL_CALL(glEnableVertexAttribArray(i));
			GL_CALL(glVertexAttribPointer(i, element.count, element.type, 
				element.normalized, layout.GetStride(), (const void*) offset));
			offset += element.count * VertexBufferElement::GetSizeOfType(element.type);
		}
	}
}