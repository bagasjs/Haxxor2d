#pragma once

// Vertex Array will be generated once in the renderer class
#include "Core.h"
#include "BufferLayout.h"
#include "Buffer.h"

namespace hb2d
{
	class HBAPI VertexArray
	{
	public:
		VertexArray();
		~VertexArray();

		void Bind() const;
		void Unbind() const;

		void AssignBuffer(const VertexBuffer& vb, const BufferLayout& layout) const;

	private:
		unsigned int  m_RendererID;
	};	
}
