#pragma once

#include "raylib.h"

#include <vector>
#include <string>

enum class figureType
{
	Cube,
	Prism,
	Dodecahedro
};

struct object
{
	figureType type;

	Vector3 pos;

	//Option 2
	Vector3 up;
	float rot;

	float scale;

	std::vector<Vector3> vertices;
	std::vector<int> index;
	std::vector<Vector3> positions;

	Color color;
};

Vector3 operator*(Vector3& vector1, float scalar);

object createFigure(figureType type, float scalar);

void getFigureFacesFromIndexes(object& object);

void draw(const std::vector<Vector3> positions, const std::vector<Vector3> vertices);
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