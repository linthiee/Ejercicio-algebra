#include "object.h"
#include "constants.h"

void main()
{
	object object;
	object.vertices.resize(8);

	object.vertices[0] = { screenWidth / 4, screenHeight / 4, 0 };
	object.vertices[1] = { screenWidth / 4, screenHeight / 2, 0 };
	object.vertices[2] = { screenWidth / 4 + 100, screenHeight / 2, 0 };
	object.vertices[3] = { screenWidth / 2 - 100, screenHeight / 4, 0 };

	object.vertices[4] = { object.vertices[0].x - 10,object.vertices[0].y + 15, 0 };
	object.vertices[5] = { object.vertices[1].x - 10,object.vertices[1].y + 15, 0 };
	object.vertices[6] = { object.vertices[2].x - 10,object.vertices[2].y + 15, 0 };
	object.vertices[7] = { object.vertices[3].x - 10,object.vertices[3].y + 15, 0 };

	InitWindow(screenWidth, screenHeight, "ejercicio");

	while (!WindowShouldClose())
	{
		// Update

		BeginDrawing();

		ClearBackground(BLACK);

		for (int i = 0; i < object.vertices.size(); i++)
		{
			DrawCircle3D(object.vertices[i], 5.0f, { 0,0,0 }, 0, RED);
		}

		DrawLine3D(object.vertices[0], object.vertices[1], BLUE);
		DrawLine3D(object.vertices[1], object.vertices[2], BLUE);
		DrawLine3D(object.vertices[2], object.vertices[3], BLUE);
		DrawLine3D(object.vertices[3], object.vertices[0], BLUE);

		DrawLine3D(object.vertices[4], object.vertices[5], BLUE);
		DrawLine3D(object.vertices[5], object.vertices[6], BLUE);
		DrawLine3D(object.vertices[6], object.vertices[7], BLUE);
		DrawLine3D(object.vertices[7], object.vertices[4], BLUE);

		DrawLine3D(object.vertices[4], object.vertices[0], BLUE);
		DrawLine3D(object.vertices[5], object.vertices[1], BLUE);
		DrawLine3D(object.vertices[6], object.vertices[2], BLUE);
		DrawLine3D(object.vertices[7], object.vertices[3], BLUE);

		EndDrawing();
	}

	CloseWindow();

}