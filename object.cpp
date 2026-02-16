#include "object.h"

static void buildRightWall(std::vector<Vector3> base, std::vector<Vector3> rWallvertices);

object createFigure(figureType type, float scalar)
{
	object myObject;

	switch (type)
	{
	case figureType::Cube:

		myObject.vertices.resize(8);

		myObject.scale = scalar;

		myObject.vertices[0] = { 0, 0, 0 };
		myObject.vertices[1] = { 0, 0, 1 };
		myObject.vertices[2] = { 1, 0, 1 };
		myObject.vertices[3] = { 1, 0, 0 };

		//buildRightWall(myObject.vertices, myObject.vertices);

		myObject.vertices[4] = { 0, 1, 0 };
		myObject.vertices[5] = { 0, 1, 1 };
		myObject.vertices[6] = { 1, 1, 0 };
		myObject.vertices[7] = { 1, 1, 1 };

		for (int i = 0; i < myObject.vertices.size(); i++)
		{
			myObject.vertices[i] = myObject.vertices[i] * myObject.scale;
		}

		myObject.index =
		{
			0, 1, 2, 0, 2, 3,
			4, 5, 7, 7, 6, 4,
			0, 4, 6, 6, 3, 0,
			5, 2, 7, 1, 2, 5,
			2, 6, 7, 2, 3, 6,
			1, 4, 0, 1, 5, 4
		};

		break;
	case figureType::Prism:

		myObject.vertices.resize(4);

		myObject.scale = scalar;

		myObject.vertices[0] = {0, 0, 0};
		myObject.vertices[1] = {1, 0, 0};
		myObject.vertices[2] = {0, 1, 0};
		myObject.vertices[3] = {0, 0, 1};

		myObject.vertices[0] = myObject.vertices[0] * myObject.scale;
		myObject.vertices[1] = myObject.vertices[1] * myObject.scale;
		myObject.vertices[2] = myObject.vertices[2] * myObject.scale;
		myObject.vertices[3] = myObject.vertices[3] * myObject.scale;

		myObject.index =
		{
			0, 1, 2
		};

		break;
	case figureType::Dodecahedro:

		break;
	default:
		break;
	}

	return myObject;
}

void getFigureFacesFromIndexes(object& object)
{
	for (int i = 0; i < object.index.size(); i += 3)
	{
		object.positions.push_back(object.vertices[object.index[i]]);
		object.positions.push_back(object.vertices[object.index[i + 1]]);
		object.positions.push_back(object.vertices[object.index[i + 2]]);
	}
}

void draw(const std::vector<Vector3> positions, const std::vector<Vector3> vertices)
{
	for (int i = 0; i < vertices.size(); i++)
	{
		DrawCircle3D(vertices[i], 0.05f, { 0,0,0 }, 0, RED);
	}

	for (int i = 0; i < positions.size(); i += 3)
	{
		DrawTriangle3D(positions[i], positions[i + 1], positions[i + 2], BLUE);
	}
}

Vector3 operator*(Vector3& vector1, float scalar)
{
	return { vector1.x * scalar, vector1.y * scalar, vector1.z * scalar };
}

void buildRightWall(std::vector<Vector3> base, std::vector<Vector3> rWallvertices)
{
	for (int i = 4; i < 8; i++)
	{
		rWallvertices[i] = { base[i - 4].x, base[i - 4].y + 1, 0 };
	}
}
