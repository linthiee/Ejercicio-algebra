#include "object.h"

static void buildTop(const std::vector<Vector3>& base, std::vector<Vector3>& top);
static void drawOutline(const std::vector<Vector3>& faces);

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
		myObject.vertices[3] = { 1, 0, 0 }; //construir la base del cubo en xz

		buildTop(myObject.vertices, myObject.vertices); //construir el techo del cubo (+1 de altura, todo lo demas queda igual)

		for (int i = 0; i < myObject.vertices.size(); i++)
		{
			myObject.vertices[i] = myObject.vertices[i] * myObject.scale;
		}

		//ya tenemos todos los vertices que vamos a necesitar, asi que solo queda conectar todos entre si
		myObject.index =
		{
			0, 2, 1, 0, 3, 2,
			4, 5, 6, 4, 6, 7,
			0, 1, 5, 0, 5, 4,
			1, 2, 6, 1, 6, 5,
			2, 3, 7, 2, 7, 6,
			0, 4, 7, 0, 7, 3
		};

		myObject.color = PINK;

		break;
	case figureType::Prism:

		myObject.vertices.resize(4);

		myObject.scale = scalar;

		myObject.vertices[0] = { 2, 2, 2 };
		myObject.vertices[1] = { 3, 2, 2 };
		myObject.vertices[2] = { 2, 3, 2 };
		myObject.vertices[3] = { 3, 3, 2 };

		for (int i = 0; i < myObject.vertices.size(); i++)
		{
			myObject.vertices[i] = myObject.vertices[i] * myObject.scale;
		}

		myObject.index =
		{
			0, 1, 2,
			0, 1, 3
		};

		myObject.color = YELLOW;

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

void draw(const std::vector<Vector3>& positions, const std::vector<Vector3>& vertices, const Color& color)
{
	for (int i = 0; i < vertices.size(); i++)
	{
		DrawCircle3D(vertices[i], 0.05f, { 0,0,0 }, 0, RED);
	}

	for (int i = 0; i < positions.size(); i += 3)
	{
		DrawTriangle3D(positions[i], positions[i + 1], positions[i + 2], color);
	}

	drawOutline(positions);
}

Vector3 operator*(Vector3& vector1, float scalar)
{
	return { vector1.x * scalar, vector1.y * scalar, vector1.z * scalar };
}

void buildTop(const std::vector<Vector3>& base, std::vector<Vector3>& top)
{
	for (int i = base.size() / 2; i < base.size(); i++)
	{
		top[i] = { base[i - (base.size() / 2)].x, base[i - (base.size() / 2)].y + 1, base[i - (base.size() / 2)].z };
	}
}

void drawOutline(const std::vector<Vector3>& faces)
{
	for (int i = 0; i < faces.size(); i += 3)
	{
		DrawLine3D(faces[i % faces.size()], faces[(i + 1) % faces.size()], MAROON);
		DrawLine3D(faces[(i + 1) % faces.size()], faces[(i + 2) % faces.size()], MAROON);
	}
}
