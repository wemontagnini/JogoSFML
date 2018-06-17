#include "MenuPrincipal.h"



MenuPrincipal::MenuPrincipal():Menu()
{
	Texture *tex = new Texture;
	tex->loadFromFile("imagens\\menuPrincipal.png");
	menu.setTexture(tex);
}


MenuPrincipal::~MenuPrincipal()
{
}

void MenuPrincipal::executarMenu(RenderWindow & window, View & view, int & escolha)
{
	escolha = 0;

	view.setCenter(Vector2f(-10000, -10000));
	Mouse mouse;

	while (!escolha)
	{
		if (mouse.getPosition(window).x >= 128 && mouse.getPosition(window).x <= 360)
		{
			if (mouse.getPosition(window).y >= 166 && mouse.getPosition(window).y <= 223 && Mouse::isButtonPressed(Mouse::Left))
				escolha = 1;
			if (mouse.getPosition(window).y >= 235 && mouse.getPosition(window).y <= 291 && Mouse::isButtonPressed(Mouse::Left))
				escolha = 2;
			if (mouse.getPosition(window).y >= 302 && mouse.getPosition(window).y <= 360 && Mouse::isButtonPressed(Mouse::Left))
				escolha = 3;
			if (mouse.getPosition(window).y >= 370 && mouse.getPosition(window).y <= 428 && Mouse::isButtonPressed(Mouse::Left))
				escolha = 4;
			if (mouse.getPosition(window).y >= 440 && mouse.getPosition(window).y <= 497 && Mouse::isButtonPressed(Mouse::Left))
				escolha = 5;
		}
		desenhar(window);
		window.display();
	}
}
