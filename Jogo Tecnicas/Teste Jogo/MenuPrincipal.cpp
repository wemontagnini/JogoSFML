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
		desenhar(window);
		window.display();
	}
}
