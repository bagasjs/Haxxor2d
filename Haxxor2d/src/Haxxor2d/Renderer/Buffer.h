#pragma once

#include "Core.h"

namespace hb2d
{
	class HBAPI Buffer
	{
	public:
		Buffer();
		~Buffer();
		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;
	protected:
		unsigned int m_RendererID;
	};

	class HBAPI VertexBuffer: public Buffer
	{
	public:
		VertexBuffer(const void* data, unsigned int size);
		void Bind() const;
		void Unbind() const;
	};

	class HBAPI IndexBuffer: public Buffer
	{
	public:
		IndexBuffer(const unsigned int* indexes, unsigned int count);
		void Bind() const;
		void Unbind() const;


		inline unsigned int GetCount() const { return m_Count; }

	private:
		unsigned int m_Count;
	};
}
