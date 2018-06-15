#include "Jogo.h"

Jogo::Jogo()
{
	RenderWindow window(VideoMode(512, 512), "Indio", Style::Close);
	View view(Vector2f(0.0f, 0.0f), Vector2f(512, 400.0f));
	Texture player1;
	Texture player2;
	player1.loadFromFile("imagens\\player1.png");
	player2.loadFromFile("imagens\\player2.png");
	int escolha; 
	menu.executarMenu(window, view, escolha);
	lista_jogadores.push_back(Jogador(&player1, Vector2u(3, 1), 0.25f, 150.0f, 100.0f, Vector2f(40.0f, 50.0f), Vector2f(1250.0f, 341.0f), 10, true));
	if(escolha == 2)
		lista_jogadores.push_back(Jogador(&player2, Vector2u(3, 1), 0.3f, 150.0f, 100.0f, Vector2f(40.0f, 50.0f), Vector2f(-1300.0f, 341.0f), 10, false));

	if (fase.ExecutarFase1(lista_jogadores, view, window))
	{
		fase.esvaziaVectors();
		for (Jogador & player : lista_jogadores)
			if (player.get_coop())
				player.set_posicao(Vector2f(1550.0f, 341.0f));
			else
				player.set_posicao(Vector2f(1600.0f, 341.0f));

		if (fase.ExecutarFase2(lista_jogadores, view, window))
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

Jogo::~Jogo()
{
}

void Jogo::Executar(bool coop_aux)
{
}
