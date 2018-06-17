#include "Jogo.h"

Jogo::Jogo()
{
	Executar();
}

Jogo::~Jogo()
{
}

void Jogo::Executar()
{
	RenderWindow window(VideoMode(512, 512), "Indio", Style::Close);
	View view(Vector2f(0.0f, 0.0f), Vector2f(512, 408.0f));
	Texture* player1 = new Texture;
	Texture* player2 = new Texture;
	player1->loadFromFile("imagens\\chefao.png");
	player2->loadFromFile("imagens\\player2.png");
	int escolha;
	menu_principal.executarMenu(window, view, escolha);
	lista_jogadores.push_back(new Jogador(player1, Vector2u(4, 1), 0.25f, 150.0f, 100.0f, Vector2f(60.0f, 70.0f), Vector2f(-1250.0f, 341.0f), 50, true));
	if (escolha == 2)
		lista_jogadores.push_back(new Jogador(player2, Vector2u(3, 1), 0.3f, 150.0f, 100.0f, Vector2f(40.0f, 50.0f), Vector2f(-1300.0f, 341.0f), 10, false));

	if (dia.executar(lista_jogadores, view, window, menu_pausa))
	{
		for (int i = 0; i< lista_jogadores.size(); i++)
			if (lista_jogadores[i]->get_coop())
				lista_jogadores[i]->set_posicao(Vector2f(1550.0f, 341.0f));
			else
				lista_jogadores[i]->set_posicao(Vector2f(1600.0f, 341.0f));

		if (noite.executar(lista_jogadores, view, window, menu_pausa))
		{


		}
		else
		{
			cout << "Deu ruim!!! Mas na fase 2!" << endl;
		}
	}
	else
	{
		cout << "Deu ruim!!!" << endl;
	}
}
