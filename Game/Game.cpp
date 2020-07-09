// Game.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Math/Math.h"
#include "Math/Random.h"
#include "Math/Transform.h"
#include "Math/Color.h"
#include "core.h"
#include <vector>
#include <string>

float speed = 300.0f;

sn::Transform transform{ {400, 300}, 4, 0 };


float frameTime;
float roundTime{ 0 };
bool gameOver = false;

DWORD prevTime;
DWORD deltaTime;

bool Update(float dt) {
	DWORD time = GetTickCount();
	deltaTime = time - prevTime;
	prevTime = time;

	frameTime = dt;
	roundTime += dt;
	if (roundTime >= 5.0f)gameOver = true;
	if (gameOver) dt = 0;

	bool quit = false;
	quit = Core::Input::IsPressed(Core::Input::KEY_ESCAPE);

	int x;
	int y;
	Core::Input::GetMousePos(x, y);

	/*sn::Vector2 target = sn::Vector2{ x, y };
	sn::Vector2 direction = target - position;
	direction.normalize();*/

	sn::Vector2 force;
	if (Core::Input::IsPressed('W')) { force = sn::Vector2::forward * speed * dt; }
	sn::Vector2 direction = force;
	direction = sn::Vector2::rotate(direction, transform.angle);
	transform.position = transform.position + direction;

	if (Core::Input::IsPressed('A')) { transform.angle = angle - (dt * 3.0f); }
	if (Core::Input::IsPressed('D')) { angle = angle + (dt * 3.0f); }

	//if (Core::Input::IsPressed('A')) { position += sn::Vector2::left * speed * dt; }
	//if (Core::Input::IsPressed('D')) { position += sn::Vector2::right * speed * dt; }

	//position = position + direction * speed;
	//if (Core::Input::IsPressed(Core::Input::KEY_LEFT)) position += sn::Vector2{ -1.0f, 0.0f } * speed;
	//if (Core::Input::IsPressed(Core::Input::KEY_RIGHT)) position += sn::Vector2{ 1.0f, 0.0f } * speed;

	return quit;
}

void Draw(Core::Graphics& graphics) {

	graphics.DrawString(10, 10, std::to_string(frameTime).c_str());
	graphics.DrawString(10, 20, std::to_string(1.0f / frameTime).c_str());
	graphics.DrawString(10, 30, std::to_string(deltaTime).c_str());

	if (gameOver) graphics.DrawString(400, 300, "Game Over!");

	ship.Draw(graphics, transform);
	
	for (size_t i = 0; i < points.size() - 1; i++) {
		sn::Vector2 p1 = points[i];
		sn::Vector2 p2 = points[i + 1];

		p1 *= scale;
		p2 *= scale;
		p1 = sn::Vector2::rotate(p1, angle);
		p2 = sn::Vector2::rotate(p2, angle);
		p1 += position;
		p2 += position;

		graphics.DrawLine(p1.x, p1.y, p2.x, p2.y);
	}
}

int main()
{	
	//DWORD ticks = GetTickCount();
	//std::cout << ticks / 1000 / 60 / 60 << std::endl;

	char name[] = "Put window name here: ";
	Core::Init(name, 800, 600);
	Core::RegisterUpdateFn(Update);
	Core::RegisterDrawFn(Draw);

	Core::GameLoop();
	Core::Shutdown();
}
