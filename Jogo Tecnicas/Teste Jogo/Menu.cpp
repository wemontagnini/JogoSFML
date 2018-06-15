#include "Menu.h"
#include <iostream>
using namespace std;

Menu::Menu()
{
	Texture *tex = new Texture;
	tex->loadFromFile("imagens\\menu.png");
	menu.setTexture(tex);
	menu.setSize(Vector2f(512.0f, 512.0f));
	menu.setOrigin(Vector2f(-10000, -10000));
	menu.setPosition(Vector2f(-10000.0f, -10000.0f));
}

Menu::~Menu()
{
}

void Menu::executarMenu(RenderWindow & window, View & view, int & escolha)
{
	escolha = 0;

	view.setCenter(Vector2f(-10000, -10000));
	Mouse mouse;

	while (!escolha)
	{
		if (mouse.getPosition().x >= 564 && mouse.getPosition().x <= 775)
		{
			if (mouse.getPosition().y >= 317 && mouse.getPosition().y <= 380 && Mouse::isButtonPressed(Mouse::Left))
				escolha = 1;
			if (mouse.getPosition().y >= 392 && mouse.getPosition().y <= 443 && Mouse::isButtonPressed(Mouse::Left))
				escolha = 2;
			if (mouse.getPosition().y >= 474 && mouse.getPosition().y <= 518 && Mouse::isButtonPressed(Mouse::Left))
				escolha = 3;
			if (mouse.getPosition().y >= 522 && mouse.getPosition().y <= 585 && Mouse::isButtonPressed(Mouse::Left))
				escolha = 4;
			if (mouse.getPosition().y >= 598 && mouse.getPosition().y <= 655 && Mouse::isButtonPressed(Mouse::Left))
				escolha = 5;
		}
		window.draw(menu);
		window.display();
	}
}
