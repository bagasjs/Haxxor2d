#include "Buffer.h"

namespace hb2d
{
	Buffer::Buffer()
	{
		GL_CALL(glGenBuffers(1, &m_RendererID));
	}

	Buffer::~Buffer()
	{
		GL_CALL(glDeleteBuffers(1, &m_RendererID));
	}

	VertexBuffer::VertexBuffer(const void* data, unsigned int size)
	{
		GL_CALL(glBindBuffer(GL_ARRAY_BUFFER, m_RendererID));
		GL_CALL(glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW));			
	}

	void VertexBuffer::Bind() const
	{
		GL_CALL(glBindBuffer(GL_ARRAY_BUFFER, m_RendererID));
	}

	void VertexBuffer::Unbind() const
	{
		GL_CALL(glBindBuffer(GL_ARRAY_BUFFER, 0));
	}

	IndexBuffer::IndexBuffer(const unsigned int* indexes, unsigned int count): m_Count(count)
	{
		GL_CALL(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID));
		GL_CALL(glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), indexes, GL_STATIC_DRAW));
	}

	void IndexBuffer::Bind() const
	{
		GL_CALL(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID));
	}

	void IndexBuffer::Unbind() const
	{
		GL_CALL(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
	}
}