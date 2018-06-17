#include "Floresta_Noite.h"



Floresta_Noite::Floresta_Noite()
{
}


Floresta_Noite::~Floresta_Noite()
{
}

void Floresta_Noite::carrega_florestaNoite()
{
	Texture *lobo = new Texture;
	Texture *macaco = new Texture;
	Texture *ground = new Texture;
	Texture *plataforma = new Texture;
	Texture *background = new Texture;
	Texture *canoa = new Texture;
	Texture *oca = new Texture;
	Texture *chefao = new Texture;

	lobo->loadFromFile("imagens\\lobo.png");
	macaco->loadFromFile("imagens\\macaco.png");
	chefao->loadFromFile("imagens\\fogo.png");
	ground->loadFromFile("imagens\\ground_noite.png");
	plataforma->loadFromFile("imagens\\plataforma_noite.png");
	background->loadFromFile("imagens\\fundo_noite.png");
	canoa->loadFromFile("imagens\\canoa.png");
	oca->loadFromFile("imagens\\oca_noite.png");

	//Carrega a lista de inimigos
	lista_inimigos.push_back(new Inimigo(macaco, Vector2u(3, 1), 0.3f, 50.0f, 100.0f, Vector2f(40.0f, 50.0f), Vector2f(-1100.0f, 343.0f), 50.0f));
	lista_inimigos.push_back(new Inimigo(lobo, Vector2u(3, 1), 0.3f, 75.0f, 100.0f, Vector2f(40.0f, 50.0f), Vector2f(-800.0f, 341.0f), 100.0f));
	lista_inimigos.push_back(new Inimigo(macaco, Vector2u(3, 1), 0.3f, 50.0f, 100.0f, Vector2f(40.0f, 50.0f), Vector2f(-300.0f, 343.0f), 50.0f));
	lista_inimigos.push_back(new Inimigo(lobo, Vector2u(3, 1), 0.3f, 75.0f, 100.0f, Vector2f(40.0f, 50.0f), Vector2f(-100.0f, 341.0f), 100.0f));
	lista_inimigos.push_back(new Inimigo(macaco, Vector2u(3, 1), 0.3f, 50.0f, 100.0f, Vector2f(40.0f, 50.0f), Vector2f(450.0f, 343.0f), 100.0f));
	lista_inimigos.push_back(new Inimigo(lobo, Vector2u(3, 1), 0.3f, 50.0f, 100.0f, Vector2f(40.0f, 50.0f), Vector2f(700.0f, 341.0f), 100.0f));
	lista_inimigos.push_back(new Inimigo(macaco, Vector2u(3, 1), 0.3f, 50.0f, 100.0f, Vector2f(40.0f, 50.0f), Vector2f(1200.0f, 343.0f), 100.0f));
	lista_inimigos.push_back(new Inimigo(macaco, Vector2u(3, 1), 0.3f, 150.0f, 100.0f, Vector2f(40.0f, 50.0f), Vector2f(-512.0f, 267.0f), 100.0f));

			//Carrega lista de plataformas
	lista_plataformas.push_back(new Plataforma(ground, Vector2f(3064.0f, 88.0f), Vector2f(200.0f, 410.0f), true));
	lista_plataformas.push_back(new Plataforma(plataforma, Vector2f(300.0f, 35.0f), Vector2f(-550.0f, 300.0f), true));
	lista_plataformas.push_back(new Plataforma(plataforma, Vector2f(300.0f, 35.0f), Vector2f(200.0f, 300.0f), true));
	lista_plataformas.push_back(new Plataforma(plataforma, Vector2f(300.0f, 35.0f), Vector2f(950.0f, 300.0f), true));
	lista_plataformas.push_back(new Plataforma(nullptr, Vector2f(3.0f, 1000.0f), Vector2f(-1340.0f, 500.0f), false));
	lista_plataformas.push_back(new Plataforma(nullptr, Vector2f(3.0f, 1000.0f), Vector2f(1723.0f, 500.0f), false));

	//Carrega lista de obstaculos
	lista_obstaculos.push_back((Obstaculos*) new Espinhos(Vector2f(-550.0f, 372.0f)));
	lista_obstaculos.push_back((Obstaculos*) new Espinhos(Vector2f(200.0f, 372.0f)));
	lista_obstaculos.push_back((Obstaculos*) new Espinhos(Vector2f(200.0f, 372.0f)));
	lista_obstaculos.push_back((Obstaculos*) new Espinhos(Vector2f(950.0f, 372.0f)));
	lista_obstaculos.push_back((Obstaculos*) new Fogo(Vector2f(-960.0f, 355.0f)));
	lista_obstaculos.push_back((Obstaculos*) new Fogo(Vector2f(-225.0f, 355.0f)));
	lista_obstaculos.push_back((Obstaculos*) new Fogo(Vector2f(87, 275.0f)));
	lista_obstaculos.push_back((Obstaculos*) new Fogo(Vector2f(1570, 275.0f)));

	//Carrega lista de cenário
	lista_cenario.push_back(new Cenario(background, Vector2f(3064.0f, 660.0f), Vector2f(200.0f, 300.0f), true));
	lista_cenario.push_back(new Cenario(canoa, Vector2f(101.0f, 53.0f), Vector2f(-1300.0f, 375.0f), true));
	lista_cenario.push_back(new Cenario(oca, Vector2f(236.0f, 189.0f), Vector2f(1528.0f, 293.0f), true));

}

bool Floresta_Noite::executar(vector<Jogador*> lista_players, View & view, RenderWindow & window, MenuPausa & menu)
{
	esvaziaVectors();
	carrega_florestaNoite();
	float posMax = 0, posMin = 0;
	float deltaTime = 0.0f;
	bool esquerda = true;
	bool pulapratras = false;
	bool aux = true;
	int i;
	bool pause = false;
	vector<Plataforma*> plataformas_view;
	plataformas_view.push_back(new Plataforma(nullptr, Vector2f(3.0f, 1000.0f), Vector2f(0.0f, 0.0f), false));
	plataformas_view.push_back(new Plataforma(nullptr, Vector2f(3.0f, 1000.0f), Vector2f(0.0f, 0.0f), false));

	Clock clock;
	while (window.isOpen())
	{
		deltaTime = float(clock.restart().asSeconds());
		if (deltaTime > 1.0f / 20.0f)
			deltaTime = 1.0f / 20.0f;
		Event evnt;

		while (window.pollEvent(evnt))
		{
			switch (evnt.type)
			{
			case Event::Closed:
				window.close();
				break;
			}
		}
		Vector2f direction;
		for (int k = 0; k < lista_players.size(); k++)
		{

			if (lista_players[k]->get_coop())
			{
				lista_players[k]->Update(deltaTime, true);

			}
			else
			{
				lista_players[k]->Update(deltaTime, false);
			}
			for (int j = 0; j< lista_inimigos.size(); j++)
				if (lista_inimigos[j]->get_colisor().checaColisao(lista_players[k]->get_colisor(), direction, 1.0f))
				{
					if (lista_players[k]->get_vida() <= 0)
						return false;
					else if (!pulapratras)
					{
						lista_players[k]->diminuiVida();
						pulapratras = true;
						lista_players[k]->set_noChao(false);
						break;
					}
				}
			for (int j = 0; j<lista_obstaculos.size(); j++)
				if (lista_obstaculos[j]->get_colisor().checaColisao(lista_players[k]->get_colisor(), direction, 1.0f))
				{
					lista_players[k]->emColisao(direction);
					if (lista_obstaculos[j]->get_dano())
					{
						if (lista_players[k]->get_vida() <= 0)
							return false;
						else if (!pulapratras)
						{
							lista_players[k]->diminuiVida();
							pulapratras = true;
							lista_players[k]->set_noChao(false);
							break;
						}
					}
				}
			for (int j = 0; j<lista_plataformas.size(); j++)
			{
				if (lista_plataformas[j]->get_colisor().checaColisao(lista_players[k]->get_colisor(), direction, 1.0f))
					lista_players[k]->emColisao(direction);

			}

			i = 0;
			if (lista_players[k]->get_coop())
				arrumaCamera(lista_players, view, plataformas_view);


		}

		window.clear(Color(150, 150, 150));
		window.setView(view);

		for (int j = 0; j<lista_cenario.size(); j++)
			lista_cenario[j]->desenhar(window);

		for (int j = 0; j < lista_obstaculos.size(); j++)
		{
			lista_obstaculos[j]->Update(deltaTime);
			lista_obstaculos[j]->desenhar(window);
		}

		for (int j = 0; j< lista_plataformas.size(); j++)
			lista_plataformas[j]->desenhar(window);

		for (int j = 0; j<lista_inimigos.size(); j++)
		{
			lista_inimigos[j]->desenhar(window);
			esquerda = lista_inimigos[j]->mover(deltaTime, esquerda);
		}

		for (int k = 0; k < lista_players.size(); k++)
		{
			for (int l = 0; l< lista_players[k]->get_lista_coracoes().size(); l++)
				lista_players[k]->get_lista_coracoes()[l]->desenhar(window);
			lista_players[k]->desenhar(window);
		}
		window.display();
	}
}
