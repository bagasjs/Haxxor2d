#include "Node.h"
#include "haxxor2d.h"

struct HB_VEC2
{
	float x;
	float y;
};

struct HB_VEC3: public HB_VEC2
{
	float z;
};

struct HB_VEC4: public HB_VEC3
{
	float w;
};

struct RenderData
{
	hb2d::VertexBuffer vb;
	hb2d::IndexBuffer hb;
}

Node::Node(HB_VEC3 vertices)
{
	RenderData* renderData = new RenderData();
	renderData->vb
}

Node::Node(HB_VEC2 start, HB_VEC2 finish)
{

}