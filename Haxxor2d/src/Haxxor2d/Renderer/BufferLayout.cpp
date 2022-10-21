#include "BufferLayout.h"

namespace hb2d
{	
	BufferLayout::BufferLayout() : m_Stride(0) {}
	void BufferLayout::Push(unsigned int count, Identity<float>)
	{
		m_Elements.push_back({ GL_FLOAT, count,  GL_FALSE});
		m_Stride += count * VertexBufferElement::GetSizeOfType(GL_FLOAT);
	}
	void BufferLayout::Push(unsigned int count, Identity<unsigned int>)
	{
		m_Elements.push_back({ GL_UNSIGNED_INT, count,  GL_FALSE});
		m_Stride += count * VertexBufferElement::GetSizeOfType(GL_UNSIGNED_INT);
	}
	void BufferLayout::Push(unsigned int count, Identity<unsigned char>)
	{
		m_Elements.push_back({ GL_UNSIGNED_BYTE, count,  GL_TRUE});
		m_Stride += count * VertexBufferElement::GetSizeOfType(GL_UNSIGNED_BYTE);
	}
}