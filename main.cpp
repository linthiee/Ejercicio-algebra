#include "object.h"
#include "constants.h"

void cameraControl(Camera3D& camera, float cameraSpeed);

void main()
{
	object object;
	object.vertices.resize(8);

	object.vertices[0] = { 0, 0, 0 };
	object.vertices[1] = { 0, 1, 0 };
	object.vertices[2] = { 1, 1, 0 };
	object.vertices[3] = { 1, 0, 0 };

	object.vertices[4] = { 0, 0, 1 };
	object.vertices[5] = { 0, 1, 1 };
	object.vertices[6] = { 1, 1, 1 };
	object.vertices[7] = { 1, 0, 1 };

	Camera3D camera = { 0 };
	camera.position = { 4.0f, 4.0f, 4.0f };
	camera.target = { 0.0f, 0.0f, 0.0f };
	camera.up = { 0.0f, 1.0f, 0.0f };
	camera.fovy = 45.0f;
	camera.projection = CAMERA_PERSPECTIVE;
	float cameraSpeed = 0.2f;

	InitWindow(screenWidth, screenHeight, "ejercicio");

	while (!WindowShouldClose())
	{
		// Update
		UpdateCamera(&camera, CAMERA_FREE);
		DisableCursor();

		cameraControl(camera, cameraSpeed);

		BeginDrawing();

		ClearBackground(RAYWHITE);
		BeginMode3D(camera);

		for (int i = 0; i < object.vertices.size(); i++)
		{
			DrawCircle3D({ object.vertices[i].x * 2.0f , object.vertices[i].y * 2.0f, object.vertices[i].z }, 0.05f, { 0,0,0 }, 0, RED);
		}

		for (int i = 0; i < object.vertices.size() / 2; i++)
		{
			DrawLine3D(object.vertices[i], object.vertices[(i + 1) % 4], BLUE);
			DrawLine3D(object.vertices[i + 4], object.vertices[((i + 1) % 4) + 4], BLUE);
			DrawLine3D(object.vertices[i], object.vertices[i + 4], BLUE);
		}

		DrawGrid(20, 1.0f);
		EndMode3D();

		EndDrawing();
	}

	CloseWindow();

}

void cameraControl(Camera3D& camera, float cameraSpeed)
{
	if (IsKeyDown(KEY_RIGHT)) camera.position.x += cameraSpeed;
	if (IsKeyDown(KEY_LEFT)) camera.position.x -= cameraSpeed;
	if (IsKeyDown(KEY_UP)) camera.position.z -= cameraSpeed;
	if (IsKeyDown(KEY_DOWN)) camera.position.z += cameraSpeed;
	if (IsKeyDown(KEY_Q)) camera.position.y += cameraSpeed;
	if (IsKeyDown(KEY_E)) camera.position.y -= cameraSpeed;
}