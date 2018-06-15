#include "SFML/Graphics.hpp"
#pragma once
using namespace sf;

class Menu
{
private:
	RectangleShape menu;
public:
	Menu();
	virtual ~Menu();
	void executarMenu(RenderWindow & window, View & view, int & escolha);
};

