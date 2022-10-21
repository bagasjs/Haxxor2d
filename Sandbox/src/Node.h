#pragma once

struct HB_VEC2;
struct HB_VEC3;
struct HB_VEC4;

struct RenderData;

class Node
{
public:
	Node(HB_VEC3 vertices);
	Node(HB_VEC2 start, HB_VEC2 finish);
	virtual ~Node() = default;

	RenderData* GenerateDrawData();
};