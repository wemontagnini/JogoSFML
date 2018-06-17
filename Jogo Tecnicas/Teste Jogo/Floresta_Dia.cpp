#include "Floresta_Dia.h"



Floresta_Dia::Floresta_Dia()
{
}


Floresta_Dia::~Floresta_Dia()
{
}

void Floresta_Dia::carrega_florestaDia()
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
	ground->loadFromFile("imagens\\ground_dia.png");
	plataforma->loadFromFile("imagens\\plataforma_dia.png");
	background->loadFromFile("imagens\\fundo_dia.png");
	oca->loadFromFile("imagens\\oca_dia.png");

	//Carrega a lista de inimigos
	lista_inimigos.push_back(new Inimigo(macaco, Vector2u(3, 1), 0.3f, 50.0f, 100.0f, Vector2f(40.0f, 50.0f), Vector2f(-1100.0f, 313.0f), 50.0f));
	lista_inimigos.push_back(new Inimigo(lobo, Vector2u(3, 1), 0.3f, 75.0f, 100.0f, Vector2f(40.0f, 50.0f), Vector2f(-800.0f, 311.0f), 100.0f));
	lista_inimigos.push_back(new Inimigo(macaco, Vector2u(3, 1), 0.3f, 50.0f, 100.0f, Vector2f(40.0f, 50.0f), Vector2f(-300.0f, 313.0f), 50.0f));
	lista_inimigos.push_back(new Inimigo(lobo, Vector2u(3, 1), 0.3f, 75.0f, 100.0f, Vector2f(40.0f, 50.0f), Vector2f(-100.0f, 311.0f), 100.0f));
	lista_inimigos.push_back(new Inimigo(macaco, Vector2u(3, 1), 0.3f, 50.0f, 100.0f, Vector2f(40.0f, 50.0f), Vector2f(450.0f, 313.0f), 100.0f));
	lista_inimigos.push_back(new Inimigo(lobo, Vector2u(3, 1), 0.3f, 50.0f, 100.0f, Vector2f(40.0f, 50.0f), Vector2f(700.0f, 311.0f), 100.0f));
	lista_inimigos.push_back(new Inimigo(macaco, Vector2u(3, 1), 0.3f, 50.0f, 100.0f, Vector2f(40.0f, 50.0f), Vector2f(1200.0f, 313.0f), 100.0f));
	lista_inimigos.push_back(new Inimigo(macaco, Vector2u(3, 1), 0.3f, 150.0f, 100.0f, Vector2f(40.0f, 50.0f), Vector2f(-512.0f, 230.f), 100.0f));

	//Carrega lista de plataformas
	lista_plataformas.push_back(new Plataforma(nullptr, Vector2f(3064.0f, 88.0f), Vector2f(200.0f, 378.5f), false));
	lista_plataformas.push_back(new Plataforma(plataforma, Vector2f(300.0f, 35.0f), Vector2f(-550.0f, 270.0f), true));
	lista_plataformas.push_back(new Plataforma(plataforma, Vector2f(300.0f, 35.0f), Vector2f(200.0f, 270.0f), true));
	lista_plataformas.push_back(new Plataforma(plataforma, Vector2f(300.0f, 35.0f), Vector2f(950.0f, 270.0f), true));
	lista_plataformas.push_back(new Plataforma(nullptr, Vector2f(3.0f, 1000.0f), Vector2f(-1340.0f, 500.0f), false));
	lista_plataformas.push_back(new Plataforma(nullptr, Vector2f(3.0f, 1000.0f), Vector2f(1723.0f, 500.0f), false));

	//Carrega lista de obstaculos
	lista_obstaculos.push_back((Obstaculos*) new Espinhos(Vector2f(-550.0f, 312.0f)));
	lista_obstaculos.push_back((Obstaculos*) new Espinhos(Vector2f(200.0f, 312.0f)));
	lista_obstaculos.push_back((Obstaculos*) new Espinhos(Vector2f(950.0f, 312.0f)));
	lista_obstaculos.push_back((Obstaculos*) new Tronco(Vector2f(-960.0f, 325.0f)));
	lista_obstaculos.push_back((Obstaculos*) new Tronco(Vector2f(-225.0f, 325.0f)));
	lista_obstaculos.push_back((Obstaculos*) new Tronco(Vector2f(87, 245.0f)));
	lista_obstaculos.push_back((Obstaculos*) new Tronco(Vector2f(-670, 245.0f)));

	//Carrega lista de cenário
	lista_cenario.push_back(new Cenario(background, Vector2f(3064.0f, 408.0f), Vector2f(200.0f, 205.5f), true));
	//lista_cenario.push_back(new Cenario(canoa, Vector2f(101.0f, 53.0f), Vector2f(-1300.0f, 375.0f), true));
	lista_cenario.push_back(new Cenario(oca, Vector2f(236.0f, 189.0f), Vector2f(1528.0f, 293.0f), true));
}

bool Floresta_Dia::executar(vector<Jogador*> lista_players, View & view, RenderWindow & window, MenuPausa & menu)
{
	esvaziaVectors();
	carrega_florestaDia();
	Texture * textura = new Texture;
	textura->loadFromFile("imagens\\passaro.png");
	vector<Plataforma*> plataformas_view;
	plataformas_view.push_back(new Plataforma(nullptr, Vector2f(3.0f, 1000.0f), Vector2f(-10000.0f, -10000.0f), false));
	plataformas_view.push_back(new Plataforma(nullptr, Vector2f(3.0f, 1000.0f), Vector2f(-10000.0f, -10000.0f), false));
	Chefao chefe(textura, Vector2u(4, 1), 0.3f, 100.0f, 0, Vector2f(40.0f, 50.0f), Vector2f(-1300.0f, 250.0f), 0);
	Plataforma fimDeFase(nullptr, Vector2f(34.0f, 38.0f), Vector2f(1528, 346), false);
	float posMax = 0, posMin = 0;
	float deltaTime = 0.0f;
	bool esquerda = true;
	bool aux = true;
	int i;
	bool pause = false;
	int escolha;
	int dano_obstaculo = 0;
	int dano_pracima = 0;
	int dano_inimigo = 0;
	Clock clock;
	while (window.isOpen())
	{
		if (lista_players.size() == 0)
			return false;
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
		if (Keyboard::isKeyPressed(Keyboard::P))
		{
			menu.set_origem(Vector2f(256, 200));
			menu.set_posicao(view.getCenter());
			menu.desenhar(window);
			window.display();
			menu.executarMenu(window, escolha, lista_players);
		}
		Vector2f direction;
		for (int k = 0; k < lista_players.size(); k++)
		{
			if (lista_players.size() == 2)
			{
				if(lista_players[0]->get_posicao().x < lista_players[1]->get_posicao().x)
					chefe.andar(deltaTime, lista_players[0]->get_posicao().x);
				else
					chefe.andar(deltaTime, lista_players[1]->get_posicao().x);
			}
			else
				chefe.andar(deltaTime, lista_players[k]->get_posicao().x);
			if (!lista_players[k]->get_tomandoDanoInimigo() && !lista_players[k]->get_tomandoDanoObstaculo())
			{
				if (lista_players[k]->get_coop())
					lista_players[k]->Update(deltaTime, true);
				else
					lista_players[k]->Update(deltaTime, false);
			}
			for (int j = 0; j < lista_inimigos.size(); j++)
				if (lista_inimigos[j]->get_tomandoDanoInimigo() >= 1 && lista_players[k]->get_tomandoDanoInimigo() >= 1)
				{
					lista_players[k]->emDano((Personagem*)lista_players[k], (Personagem*)lista_inimigos[j], deltaTime);
				}
				else
				{
					if (lista_inimigos[j]->get_colisor().checaColisao(lista_players[k]->get_colisor(), direction, 1.0f))
					{
						if (lista_players[k]->get_vida() <= 0)
						{
							delete lista_players[k];
							break;
						}
						else
						{
							lista_players[k]->diminuiVida();
							lista_players[k]->set_noChao(false);
							lista_players[k]->set_tomandoDanoInimigo(1);
							lista_inimigos[j]->set_tomandoDanoInimigo(1);
							break;
						}
					}
				}
			for (int j = 0; j < lista_obstaculos.size(); j++)
			{
				if (lista_players[k]->get_tomandoDanoObstaculo() >= 1 && lista_obstaculos[j]->get_tomandoDanoObstaculo() >= 1)
				{
					lista_players[k]->emDano((Personagem*)lista_players[k], deltaTime);
					lista_obstaculos[j]->set_tomandoDanoObstaculo(lista_obstaculos[j]->get_tomandoDanoObstaculo() + 1);
					if (lista_players[k]->get_tomandoDanoObstaculo() == 0)
						lista_obstaculos[j]->set_tomandoDanoObstaculo(0);
				}
				else
				{
					if (lista_obstaculos[j]->get_colisor().checaColisao(lista_players[k]->get_colisor(), direction, 1.0f))
					{
						lista_players[k]->emColisao(direction);
						if (lista_obstaculos[j]->get_dano())
						{
							if (lista_players[k]->get_vida() <= 0)
								break;
							else
							{
								lista_players[k]->diminuiVida();
								lista_players[k]->set_noChao(false);
								lista_players[k]->set_tomandoDanoObstaculo(1);
								lista_obstaculos[j]->set_tomandoDanoObstaculo(1);
								break;
							}
						}
					}
				}

			}

			for (int j = 0; j < lista_plataformas.size(); j++)
			{
				if (lista_plataformas[j]->get_colisor().checaColisao(lista_players[k]->get_colisor(), direction, 1.0f))
					lista_players[k]->emColisao(direction);
			}
			if (fimDeFase.get_colisor().checaColisao(lista_players[k]->get_colisor(), direction, 1.0f))
				return true;
			i = 0;

			arrumaCamera(lista_players, view, plataformas_view);
			for (int i = 0; i < 2; i++)
			{
				if (plataformas_view[i]->get_colisor().checaColisao(lista_players[k]->get_colisor(), direction, 1.0f))
					lista_players[k]->emColisao(direction);
			}

			if (lista_players[k]->get_vida() == 0)
			{
				delete lista_players[k];
				lista_players.pop_back();
				
			}

		}
		window.clear(Color(150, 150, 150));
		window.setView(view);
		for (int j = 0; j < lista_cenario.size(); j++)
			lista_cenario[j]->desenhar(window);

		for (int j = 0; j < lista_obstaculos.size(); j++)
			lista_obstaculos[j]->desenhar(window);

		for (int j = 0; j < lista_plataformas.size(); j++)
			lista_plataformas[j]->desenhar(window);


		for (int j = 0; j < lista_inimigos.size(); j++)
		{
			lista_inimigos[j]->desenhar(window);
			esquerda = lista_inimigos[j]->mover(deltaTime, esquerda);
		}

		for (int k = 0; k < lista_players.size(); k++)
		{
			for (int l = 0; l < lista_players[k]->get_lista_coracoes().size(); l++)
				lista_players[k]->get_lista_coracoes()[l]->desenhar(window);
			lista_players[k]->desenhar(window);
		}
		chefe.desenhar(window);
		window.display();
	}
}


