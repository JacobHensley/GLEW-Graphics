#include <iostream>
#include "Application.h"
#include "GameLayer.h"
#include "game/Level.h"
#include "graphics/layers/UILayer.h"
#include "demo/DemoLayer.h"

int main()
{
	Application app("Test Window", 1280, 720);

	app.PushLayer(new GameLayer("GameLayer"));
	app.PushLayer(new UILayer("UILayer"));
	app.PushLayer(new DemoLayer("DemoLayer"));
	app.Run();

	//TODO:
	//Text
	//ImGUI
	//Memory Arena
	//Allocation Tracking
	//String Formatting
	//Materials
	//Game
	//add static asserts, etc
	//Debug Layer Labels
}