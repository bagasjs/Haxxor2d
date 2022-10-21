#include "Renderer.h"
#include "Core.h"


namespace hb2d
{
	void Renderer::Draw(const VertexArray& va, const IndexBuffer& ib) const
	{
		va.Bind();
		ib.Bind();
		GL_CALL(glDrawElements(GL_TRIANGLES, ib.GetCount(), GL_UNSIGNED_INT, nullptr));
	}

	void Renderer::Draw(const VertexArray& va, const IndexBuffer& ib, const Shader& shader) const
	{
		shader.Bind();
		va.Bind();
		ib.Bind();
		GL_CALL(glDrawElements(GL_TRIANGLES, ib.GetCount(), GL_UNSIGNED_INT, nullptr));
	}

	void Renderer::Clear()
	{
		GL_CALL(glClear(GL_COLOR_BUFFER_BIT));
	}
}