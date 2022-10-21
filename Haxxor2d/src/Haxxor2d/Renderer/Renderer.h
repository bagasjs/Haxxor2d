#pragma once

#include "Core.h"
#include "VertexArray.h"
#include "Buffer.h"
#include "Shader.h"

namespace hb2d
{
	class HBAPI Renderer
	{
	public:
		void Clear();
		void Draw(const VertexArray& va) const;
		void Draw(const VertexArray& va, const IndexBuffer& ib) const;
		void Draw(const VertexArray& va, const IndexBuffer& ib, const Shader& shader) const;
	};
}