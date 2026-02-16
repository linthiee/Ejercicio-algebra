#include "object.h"
#include "constants.h"

void cameraControl(Camera3D& camera, float cameraSpeed);


void main()
{

	//cube.vertices[4] = { 0, 0, 1 };
	//cube.vertices[5] = { 0, 1, 1 };
	//cube.vertices[6] = { 1, 1, 1 };
	//cube.vertices[7] = { 1, 0, 1 };

	//cube.vertices[4] = cube.vertices[4] * cube.scale;
	//cube.vertices[5] = cube.vertices[5] * cube.scale;
	//cube.vertices[6] = cube.vertices[6] * cube.scale;
	//cube.vertices[7] = cube.vertices[7] * cube.scale;

	Camera3D camera = { 0 };
	camera.position = { 4.0f, 4.0f, 4.0f };
	camera.target = { 0.0f, 0.0f, 0.0f };
	camera.up = { 0.0f, 1.0f, 0.0f };
	camera.fovy = 45.0f;
	camera.projection = CAMERA_PERSPECTIVE;
	float cameraSpeed = 0.2f;

	InitWindow(screenWidth, screenHeight, "ejercicio");

	object cube = createFigure(figureType::Cube, 2.0f);
	object prism = createFigure(figureType::Prism, 2.0f);

	while (!WindowShouldClose())
	{
		// Update
		UpdateCamera(&camera, CAMERA_FREE);
		DisableCursor();

		cameraControl(camera, cameraSpeed);

		BeginDrawing();

		ClearBackground(RAYWHITE);
		BeginMode3D(camera);

		getFigureFacesFromIndexes(cube);
		getFigureFacesFromIndexes(prism);

		draw(cube.positions, cube.vertices);
		//draw(prism.positions, prism.vertices);

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

