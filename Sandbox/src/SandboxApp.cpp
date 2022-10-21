#include "Haxxor2d.h"

int Main(int argc, char** argv)
{
	hb2d::Window* window = new hb2d::Window("My Application");
	hb2d::Renderer* renderer = window->GetRenderer();

	float positions[] = {
		-.5f, -.5f,
		.5f, -.5f,
		.5f, .5f,
		-.5f, .5f
	};

	unsigned int indicies[] = {
		0, 1, 2,
		2, 3, 0
	};

	hb2d::VertexArray* va = new hb2d::VertexArray();

	hb2d::VertexBuffer* vb = new hb2d::VertexBuffer(positions, 4 * 4 * sizeof(float));
	hb2d::BufferLayout* layout = new hb2d::BufferLayout();
	layout->Push<float>(2);
	va->AssignBuffer(*vb, *layout);

	hb2d::IndexBuffer* ib = new hb2d::IndexBuffer(indicies, 6);

	while(window->IsRunning())
	{
		renderer->Draw(*va, *ib);
		window->OnRender();
		window->PollEvents();
	}

	delete layout, ib, vb, va, window;
	return 0;
}