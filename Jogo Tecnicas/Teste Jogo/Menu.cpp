#include "Menu.h"
#include <iostream>
using namespace std;

Menu::Menu()
{
	menu.setTexture(nullptr);
	menu.setSize(Vector2f(512.0f, 512.0f));
	menu.setOrigin(Vector2f(-10000.0f, -10000.0f));
	menu.setPosition(Vector2f(-10000.0f, -10000.0f));
}

Menu::~Menu()
{
}