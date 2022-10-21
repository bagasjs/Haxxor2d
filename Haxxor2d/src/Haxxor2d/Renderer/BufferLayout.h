#pragma once

#include <vector>
#include "Core.h"

namespace hb2d
{
	struct VertexBufferElement
	{
		unsigned int type;
		unsigned int count;
		unsigned char normalized;

		static unsigned int GetSizeOfType(unsigned int type)
		{
			switch(type)
			{
				case GL_FLOAT: return 4;
				case GL_UNSIGNED_INT: return 4;
				case GL_UNSIGNED_BYTE: return 4;
			}
			return 0;
		}
	};

	template<typename T>
	struct Identity {};
	class HBAPI BufferLayout
	{
	public:
		BufferLayout();

		template<typename T>
		void Push(unsigned int count)
		{
			Push(count, Identity<T>());
		}

		inline const std::vector<VertexBufferElement>& GetElements() const { return m_Elements; }
		inline unsigned int GetStride() const { return m_Stride; }

	private:
		void Push(unsigned int count, Identity<float>);
		void Push(unsigned int count, Identity<unsigned int>);
		void Push(unsigned int count, Identity<unsigned char>);
	private:
		std::vector<VertexBufferElement> m_Elements;
		unsigned int m_Stride;
	};
}