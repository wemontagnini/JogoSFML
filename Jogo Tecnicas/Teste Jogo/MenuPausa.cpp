#include "MenuPausa.h"
#include <iostream>
using namespace std;


MenuPausa::MenuPausa():Menu()
{
	Texture *tex = new Texture;
	tex->loadFromFile("imagens\\menuPause.png");
	menu.setTexture(tex);
	menu.setSize(Vector2f(265.0f, 80.5f));
}


MenuPausa::~MenuPausa()
{
}

void MenuPausa::executarMenu(RenderWindow & window, int & escolha, vector<Jogador*> lista_players)
{

	escolha = 0;
	Mouse mouse;
	while (!escolha)
	{
		if (mouse.getPosition().y >= 177 && mouse.getPosition().y <= 250)
		{
			cout << "entra aqui" << endl;
			if (mouse.getPosition().x >= 442 && mouse.getPosition().x <= 503 && Mouse::isButtonPressed(Mouse::Left))
				escolha = 1;
			if (mouse.getPosition().x >= 511 && mouse.getPosition().x <= 695 && Mouse::isButtonPressed(Mouse::Left))
			{
				salvarJogo(lista_players);
				escolha = 1;
			}
		}
	}
}

void MenuPausa::salvarJogo(vector<Jogador*> lista_players)
{
	fstream arquivo;
	arquivo.open("save.txt", ios::out);

	for (int i = 0; i < lista_players.size(); i++)
	{
		arquivo << lista_players[i]->get_posicao().x << " " << lista_players[i]->get_posicao().y << " "
			<< lista_players[i]->get_coop() << " " << lista_players[i]->get_vida() << " " << lista_players[i]->get_pontos() << endl;
	}
	arquivo.close();

}
