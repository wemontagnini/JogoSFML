#include "Fase.h"

Fase::Fase()
{
}

Fase::~Fase()
{
	esvaziaVectors();
}

bool Fase::ExecutarFase1(vector<Jogador> lista_players, View & view, RenderWindow & window)
{
	Texture *hearth = new Texture;

	hearth->loadFromFile("imagens\\coracao.png");

	vector<Cenario> coracoes;
	coracoes.push_back(Cenario(hearth, Vector2f(25.0f, 25.0f), Vector2f(0, 0), true));

	srand(time(NULL));

	Plataforma fimDeFase(nullptr, Vector2f(34.0f, 38.0f), Vector2f(1528, 346), false);
//	Chefao chefe(&inimigo, Vector2u(3, 1), 0.3f, 100.0f, 100.0f, Vector2f(40.0f, 50.0f), Vector2f(-1100.0f, 343.0f), 50.0f);

	setVectors(true);
	float posMax = 0, posMin = 0;
	float deltaTime = 0.0f;
	bool esquerda = true;
	bool pulapratras = false;
	bool aux = true;
	int i;
	bool pause = false;
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
		//foguinho.Update(0, deltaTime, false, 1);
		Vector2f direction;

		for (Inimigo & inimigo : lista_inimigos)
		{
			esquerda = inimigo.mover(deltaTime, esquerda);
		}
		for (Jogador & player : lista_players)
		{

			if (player.get_coop())
			{
				player.Update(deltaTime, 1, posMax, posMin);
				posMax = player.get_posicao().x + 206;
				posMin = player.get_posicao().x - 206.0f;

			}
			else
			{
				player.Update(deltaTime, 2, posMax, posMin);
				posMax = player.get_posicao().x + 206;
				posMin = player.get_posicao().x - 206.0f;
			}
			for (Inimigo & inimigo : lista_inimigos)
				if (inimigo.get_colisor().checaColisao(player.get_colisor(), direction, 1.0f))
				{
					if (player.get_vida() <= 0)
						return false;
					else if (!pulapratras)
					{
						player--;
						pulapratras = true;
						player.set_noChao(false);
						coracoes.pop_back();
						break;
					}
				}
			for (int j = 0; j<lista_obstaculos.size(); i++)
				if (lista_obstaculos[i].get_colisor().checaColisao(player.get_colisor(), direction, 1.0f))
				{
					player.emColisao(direction);
					if (lista_obstaculos[i].get_dano())
					{
						if (player.get_vida() <= 0)
							return false;
						else if (!pulapratras)
						{
							player--;
							pulapratras = true;
							player.set_noChao(false);
							coracoes.pop_back();
							break;
						}
					}
				}
			for (Plataforma & plataforma : lista_plataformas)
			{
				if (plataforma.get_colisor().checaColisao(player.get_colisor(), direction, 1.0f))
					player.emColisao(direction);

			}
			if (fimDeFase.get_colisor().checaColisao(player.get_colisor(), direction, 1.0f))
				return true;
			/*if (pulapratras)
			{
			player.pular(deltaTime, aux);
			if (player.get_noChao())
			{
			pulapratras = false;
			aux = true;
			}
			}
			*/
			i = 0;
			if (player.get_coop())
			{
				if (player.get_posicao().x < -1072.0f)
				{
					view.setCenter(Vector2f(-1072.0f, 206.0f));
					for (Cenario &coracao : player.get_lista_coracoes())
					{
						coracao.set_posicao(Vector2f(-1280.0f + i, 100.0f));
						i += 22;
					}
				}
				else if (player.get_posicao().x > 1460.0f)
				{
					view.setCenter(Vector2f(1460.0f, 206.0f));
					for (Cenario &coracao : player.get_lista_coracoes())
					{
						coracao.set_posicao(Vector2f(1252.0f + i, 100.0f));
						i += 22;
					}
				}
				else
				{
					view.setCenter(Vector2f(player.get_posicao().x, 206.0f));
					for (Cenario &coracao : player.get_lista_coracoes())
					{
						coracao.set_posicao(Vector2f(player.get_posicao().x - 208.7f + i, 100.0f));
						i += 22;
					}
				}
			}
			else
			{
				if (player.get_posicao().x < -1072.0f)
					for (Cenario &coracao : player.get_lista_coracoes())
					{
						coracao.set_posicao(Vector2f(-1280.0f + i, 120.0f));
						i += 22;
					}
				else if (player.get_posicao().x > 1460.0f)
					for (Cenario &coracao : player.get_lista_coracoes())
					{
						coracao.set_posicao(Vector2f(1252.0f + i, 120.0f));
						i += 22;
					}
				else
					for (Cenario &coracao : player.get_lista_coracoes())
					{
						coracao.set_posicao(Vector2f(player.get_posicao().x - 208.7f + i, 120.0f));
						i += 22;
					}
			}

		}

		window.clear(Color(150, 150, 150));
		window.setView(view);


		//chefe.andar(deltaTime, player.get_posicao().x);


		for (Cenario & cenario : lista_cenario)
			cenario.desenhar(window);

		for (Plataforma & coracao : coracoes)
			coracao.desenhar(window);

		for (int j = 0; j < lista_obstaculos.size(); j++)
			lista_obstaculos[i].desenhar(window);

		for (Plataforma & plataforma : lista_plataformas)
			plataforma.desenhar(window);

		for (Inimigo & inimigo : lista_inimigos)
			inimigo.desenhar(window);

		for (Jogador & jogador : lista_players)
			for (Cenario & coracao : jogador.get_lista_coracoes())
				coracao.desenhar(window);

		for (Jogador & player : lista_players)
			player.desenhar(window);

		window.display();

	}
}

bool Fase::ExecutarFase2(vector<Jogador> lista_players, View & view, RenderWindow & window)
{
	Texture *hearth = new Texture;

	hearth->loadFromFile("imagens\\coracao.png");

	vector<Cenario> coracoes;
	coracoes.push_back(Cenario(hearth, Vector2f(25.0f, 25.0f), Vector2f(0, 0), true));

	Texture* fogo = new Texture;
	fogo->loadFromFile("imagens\\fogo.png");
	Fogo foguinho(Vector2f(1400.0f, 250.0f));
	srand(time(NULL));

	Plataforma fimDeFase(nullptr, Vector2f(34.0f, 38.0f), Vector2f(1528, 346), false);
	//	Chefao chefe(&inimigo, Vector2u(3, 1), 0.3f, 100.0f, 100.0f, Vector2f(40.0f, 50.0f), Vector2f(-1100.0f, 343.0f), 50.0f);

	setVectors(false);
	float posMax = 0, posMin = 0;
	float deltaTime = 0.0f;
	bool esquerda = true;
	bool pulapratras = false;
	bool aux = true;
	int i;
	bool pause = false;
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
		//foguinho.Update(deltaTime);
		for (Inimigo & inimigo : lista_inimigos)
		{
			esquerda = inimigo.mover(deltaTime, esquerda);
		}
		for (Jogador & player : lista_players)
		{

			if (player.get_coop())
			{
				player.Update(deltaTime, 1, posMax, posMin);
				posMax = player.get_posicao().x + 206;
				posMin = player.get_posicao().x - 206.0f;

			}
			else
			{
				player.Update(deltaTime, 2, posMax, posMin);
				posMax = player.get_posicao().x + 206;
				posMin = player.get_posicao().x - 206.0f;
			}
			for (Inimigo & inimigo : lista_inimigos)
				if (inimigo.get_colisor().checaColisao(player.get_colisor(), direction, 1.0f))
				{
					if (player.get_vida() <= 0)
						return false;
					else if (!pulapratras)
					{
						player--;
						pulapratras = true;
						player.set_noChao(false);
						coracoes.pop_back();
						break;
					}
				}
			for (Fogo & fogo : lista_fogo)
				if (fogo.get_colisor().checaColisao(player.get_colisor(), direction, 1.0f))
				{
					player.emColisao(direction);
					if (fogo.get_dano())
					{
						if (player.get_vida() <= 0)
							return false;
						else if (!pulapratras)
						{
							player--;
							pulapratras = true;
							player.set_noChao(false);
							coracoes.pop_back();
							break;
						}
					}
				}
			for (int j = 0; j<lista_obstaculos.size(); j++)
				if (lista_obstaculos[i].get_colisor().checaColisao(player.get_colisor(), direction, 1.0f))
				{
					player.emColisao(direction);
					if (lista_obstaculos[i].get_dano())
					{
						if (player.get_vida() <= 0)
							return false;
						else if (!pulapratras)
						{
							player--;
							pulapratras = true;
							player.set_noChao(false);
							coracoes.pop_back();
							break;
						}
					}
				}
			for (Plataforma & plataforma : lista_plataformas)
			{
				if (plataforma.get_colisor().checaColisao(player.get_colisor(), direction, 1.0f))
					player.emColisao(direction);

			}
			//if (fimDeFase.get_colisor().checaColisao(player.get_colisor(), direction, 1.0f))
			//	return true;
			/*if (pulapratras)
			{
			player.pular(deltaTime, aux);
			if (player.get_noChao())
			{
			pulapratras = false;
			aux = true;
			}
			}
			*/
			i = 0;
			if (player.get_coop())
			{
				if (player.get_posicao().x < -1072.0f)
				{
					view.setCenter(Vector2f(-1072.0f, 206.0f));
					for (Cenario &coracao : player.get_lista_coracoes())
					{
						coracao.set_posicao(Vector2f(-1280.0f + i, 100.0f));
						i += 22;
					}
				}
				else if (player.get_posicao().x > 1460.0f)
				{
					view.setCenter(Vector2f(1460.0f, 206.0f));
					for (Cenario &coracao : player.get_lista_coracoes())
					{
						coracao.set_posicao(Vector2f(1252.0f + i, 100.0f));
						i += 22;
					}
				}
				else
				{
					view.setCenter(Vector2f(player.get_posicao().x, 206.0f));
					for (Cenario &coracao : player.get_lista_coracoes())
					{
						coracao.set_posicao(Vector2f(player.get_posicao().x - 208.7f + i, 100.0f));
						i += 22;
					}
				}
			}
			else
			{
				if (player.get_posicao().x < -1072.0f)
					for (Cenario &coracao : player.get_lista_coracoes())
					{
						coracao.set_posicao(Vector2f(-1280.0f + i, 120.0f));
						i += 22;
					}
				else if (player.get_posicao().x > 1460.0f)
					for (Cenario &coracao : player.get_lista_coracoes())
					{
						coracao.set_posicao(Vector2f(1252.0f + i, 120.0f));
						i += 22;
					}
				else
					for (Cenario &coracao : player.get_lista_coracoes())
					{
						coracao.set_posicao(Vector2f(player.get_posicao().x - 208.7f + i, 120.0f));
						i += 22;
					}
			}

		}

		window.clear(Color(150, 150, 150));
		window.setView(view);


		//chefe.andar(deltaTime, player.get_posicao().x);


		for (Cenario & cenario : lista_cenario)
			cenario.desenhar(window);

		for (Plataforma & coracao : coracoes)
			coracao.desenhar(window);

		for (Fogo & fogo : lista_fogo)
		{
			fogo.Update(deltaTime);
			fogo.desenhar(window);
		}
		for (int j = 0; j<lista_obstaculos.size(); j++)
			lista_obstaculos[i].desenhar(window);

		for (Plataforma & plataforma : lista_plataformas)
			plataforma.desenhar(window);

		for (Inimigo & inimigo : lista_inimigos)
			inimigo.desenhar(window);

		for (Jogador & jogador : lista_players)
			for (Cenario & coracao : jogador.get_lista_coracoes())
				coracao.desenhar(window);

		for (Jogador & player : lista_players)
			player.desenhar(window);
		foguinho.desenhar(window);
		window.display();

	}
}


void Fase::setVectors(const bool fase1)
{
	Texture *fogo = new Texture;
	Texture *lobo = new Texture;
	Texture *macaco = new Texture;
	Texture *granSpike = new Texture;
	Texture *ground1 = new Texture;
	Texture *plataforma = new Texture;
	Texture *background = new Texture;
	Texture *canoa = new Texture;
	Texture *oca = new Texture;
	Texture *chefao = new Texture;

	lobo->loadFromFile("imagens\\lobo.png");
	granSpike->loadFromFile("imagens\\grandspike.png");
	macaco->loadFromFile("imagens\\macaco.png");
	fogo->loadFromFile("imagens\\fogo.png");
	chefao->loadFromFile("imagens\\fogo.png");
	if (fase1)
	{
		//Carrega as texturas que serão utilizadas
		ground1->loadFromFile("imagens\\ground_dia.png");
		plataforma->loadFromFile("imagens\\plataforma_dia.png");
		background->loadFromFile("imagens\\fundo_dia.png");
		canoa->loadFromFile("imagens\\canoa.png");
		oca->loadFromFile("imagens\\oca_dia.png");

		//Carrega a lista de inimigos
		lista_inimigos.push_back(Inimigo(macaco, Vector2u(3, 1), 0.3f, 50.0f, 100.0f, Vector2f(40.0f, 50.0f), Vector2f(-1100.0f, 343.0f), 50.0f));
		lista_inimigos.push_back(Inimigo(lobo, Vector2u(3, 1), 0.3f, 75.0f, 100.0f, Vector2f(40.0f, 50.0f), Vector2f(-800.0f, 341.0f), 100.0f));
		lista_inimigos.push_back(Inimigo(macaco, Vector2u(3, 1), 0.3f, 50.0f, 100.0f, Vector2f(40.0f, 50.0f), Vector2f(-300.0f, 343.0f), 50.0f));
		lista_inimigos.push_back(Inimigo(lobo, Vector2u(3, 1), 0.3f, 75.0f, 100.0f, Vector2f(40.0f, 50.0f), Vector2f(-100.0f, 341.0f), 100.0f));
		lista_inimigos.push_back(Inimigo(macaco, Vector2u(3, 1), 0.3f, 50.0f, 100.0f, Vector2f(40.0f, 50.0f), Vector2f(450.0f, 343.0f), 100.0f));
		lista_inimigos.push_back(Inimigo(lobo, Vector2u(3, 1), 0.3f, 50.0f, 100.0f, Vector2f(40.0f, 50.0f), Vector2f(700.0f, 341.0f), 100.0f));
		lista_inimigos.push_back(Inimigo(macaco, Vector2u(3, 1), 0.3f, 50.0f, 100.0f, Vector2f(40.0f, 50.0f), Vector2f(1200.0f, 343.0f), 100.0f));
		lista_inimigos.push_back(Inimigo(macaco, Vector2u(3, 1), 0.3f, 150.0f, 100.0f, Vector2f(40.0f, 50.0f), Vector2f(-512.0f, 267.0f), 100.0f));

		//Carrega lista de plataformas
		lista_plataformas.push_back(Plataforma(ground1, Vector2f(3064.0f, 88.0f), Vector2f(200.0f, 410.0f), true));
		lista_plataformas.push_back(Plataforma(plataforma, Vector2f(300.0f, 35.0f), Vector2f(-550.0f, 300.0f), true));
		lista_plataformas.push_back(Plataforma(plataforma, Vector2f(300.0f, 35.0f), Vector2f(200.0f, 300.0f), true));
		lista_plataformas.push_back(Plataforma(plataforma, Vector2f(300.0f, 35.0f), Vector2f(950.0f, 300.0f), true));
		lista_plataformas.push_back(Plataforma(nullptr, Vector2f(3.0f, 1000.0f), Vector2f(-1340.0f, 500.0f), false));
		lista_plataformas.push_back(Plataforma(nullptr, Vector2f(3.0f, 1000.0f), Vector2f(1723.0f, 500.0f), false));

		//Carrega lista de obstaculos
		lista_obstaculos.push_back(Espinhos(Vector2f(-550.0f, 372.0f)));
		lista_obstaculos.push_back(Espinhos(Vector2f(200.0f, 372.0f)));
		lista_obstaculos.push_back(Espinhos(Vector2f(950.0f, 372.0f)));
		lista_obstaculos.push_back(Tronco(Vector2f(-960.0f, 355.0f)));
		lista_obstaculos.push_back(Tronco(Vector2f(-225.0f, 355.0f)));
		lista_obstaculos.push_back(Tronco(Vector2f(87, 275.0f)));
		lista_obstaculos.push_back(Tronco(Vector2f(-670, 275.0f)));

		//Carrega lista de cenário
		lista_cenario.push_back(Cenario(background, Vector2f(3064.0f, 660.0f), Vector2f(200.0f, 300.0f), true));
		lista_cenario.push_back(Cenario(canoa, Vector2f(101.0f, 53.0f), Vector2f(-1300.0f, 375.0f), true));
		lista_cenario.push_back(Cenario(oca, Vector2f(236.0f, 189.0f), Vector2f(1528.0f, 293.0f), true));
	}
	else
	{
		ground1->loadFromFile("imagens\\ground_noite.png");
		plataforma->loadFromFile("imagens\\plataforma_noite.png");
		background->loadFromFile("imagens\\fundo_noite.png");
		canoa->loadFromFile("imagens\\canoa.png");
		oca->loadFromFile("imagens\\oca_noite.png");

		//Carrega a lista de inimigos
		lista_inimigos.push_back(Inimigo(macaco, Vector2u(3, 1), 0.3f, 50.0f, 100.0f, Vector2f(40.0f, 50.0f), Vector2f(-1100.0f, 343.0f), 50.0f));
		lista_inimigos.push_back(Inimigo(lobo, Vector2u(3, 1), 0.3f, 75.0f, 100.0f, Vector2f(40.0f, 50.0f), Vector2f(-800.0f, 341.0f), 100.0f));
		lista_inimigos.push_back(Inimigo(macaco, Vector2u(3, 1), 0.3f, 50.0f, 100.0f, Vector2f(40.0f, 50.0f), Vector2f(-300.0f, 343.0f), 50.0f));
		lista_inimigos.push_back(Inimigo(lobo, Vector2u(3, 1), 0.3f, 75.0f, 100.0f, Vector2f(40.0f, 50.0f), Vector2f(-100.0f, 341.0f), 100.0f));
		lista_inimigos.push_back(Inimigo(macaco, Vector2u(3, 1), 0.3f, 50.0f, 100.0f, Vector2f(40.0f, 50.0f), Vector2f(450.0f, 343.0f), 100.0f));
		lista_inimigos.push_back(Inimigo(lobo, Vector2u(3, 1), 0.3f, 50.0f, 100.0f, Vector2f(40.0f, 50.0f), Vector2f(700.0f, 341.0f), 100.0f));
		lista_inimigos.push_back(Inimigo(macaco, Vector2u(3, 1), 0.3f, 50.0f, 100.0f, Vector2f(40.0f, 50.0f), Vector2f(1200.0f, 343.0f), 100.0f));
		lista_inimigos.push_back(Inimigo(macaco, Vector2u(3, 1), 0.3f, 150.0f, 100.0f, Vector2f(40.0f, 50.0f), Vector2f(-512.0f, 267.0f), 100.0f));

		//Carrega lista de plataformas
		lista_plataformas.push_back(Plataforma(ground1, Vector2f(3064.0f, 88.0f), Vector2f(200.0f, 410.0f), true));
		lista_plataformas.push_back(Plataforma(plataforma, Vector2f(300.0f, 35.0f), Vector2f(-550.0f, 300.0f), true));
		lista_plataformas.push_back(Plataforma(plataforma, Vector2f(300.0f, 35.0f), Vector2f(200.0f, 300.0f), true));
		lista_plataformas.push_back(Plataforma(plataforma, Vector2f(300.0f, 35.0f), Vector2f(950.0f, 300.0f), true));
		lista_plataformas.push_back(Plataforma(nullptr, Vector2f(3.0f, 1000.0f), Vector2f(-1340.0f, 500.0f), false));
		lista_plataformas.push_back(Plataforma(nullptr, Vector2f(3.0f, 1000.0f), Vector2f(1723.0f, 500.0f), false));

		//Carrega lista de obstaculos
		lista_obstaculos.push_back(Espinhos(Vector2f(-550.0f, 372.0f)));
		lista_obstaculos.push_back(Espinhos(Vector2f(200.0f, 372.0f)));
		lista_obstaculos.push_back(Espinhos(Vector2f(950.0f, 372.0f)));

		lista_obstaculos.push_back(Fogo(Vector2f(-960.0f, 355.0f)));
		lista_obstaculos.push_back(Fogo(Vector2f(-225.0f, 355.0f)));
		lista_obstaculos.push_back(Fogo(Vector2f(87, 275.0f)));
		lista_obstaculos.push_back(Fogo(Vector2f(1570, 275.0f)));

		//Carrega lista de fogo
		lista_fogo.push_back(Fogo(Vector2f(-960.0f, 355.0f)));
		lista_fogo.push_back(Fogo(Vector2f(-225.0f, 355.0f)));
		lista_fogo.push_back(Fogo(Vector2f(87, 275.0f)));
		lista_fogo.push_back(Fogo(Vector2f(-670, 275.0f)));

		//Carrega lista de cenário
		//lista_cenario.push_back(Cenario(nullptr, Vector2f(34.0f, 38.0f), Vector2f(1528, 346), false));
		lista_cenario.push_back(Cenario(background, Vector2f(3064.0f, 660.0f), Vector2f(200.0f, 300.0f), true));
		lista_cenario.push_back(Cenario(canoa, Vector2f(101.0f, 53.0f), Vector2f(-1300.0f, 375.0f), true));
		lista_cenario.push_back(Cenario(oca, Vector2f(236.0f, 189.0f), Vector2f(1528.0f, 293.0f), true));
	}

}

void Fase::esvaziaVectors()
{
	while(!lista_cenario.empty())
		lista_cenario.pop_back();
	while(!lista_inimigos.empty())
		lista_inimigos.pop_back();
	while(!lista_plataformas.empty())
		lista_plataformas.pop_back();
	while(!lista_obstaculos.empty())
		lista_obstaculos.pop_back();

}

