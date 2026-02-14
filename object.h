#pragma once

#include "raylib.h"

#include <vector>
#include <string>

struct object
{
	Vector3 pos;

	//Option 2
	Vector3 up;
	float rot;

	Vector3 scale;

	std::vector<Vector3> vertices;

	Color color;
};

void draw();
//
//std::string toString()
//{
//	// El formato deb ser:
//   // pos: (0,0,0)
//   // scale: (0,0,0)
//   // rot vector: (0,0,0)
//   // rot angle: 0
//   // Vertices: {(0,0,0) , (0,0,0) , (0,0,0)}
//
//	return std::string();
//}