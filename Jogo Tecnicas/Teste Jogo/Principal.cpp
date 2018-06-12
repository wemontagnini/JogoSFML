#include "Principal.h"

Principal::Principal()
{
	Executar();
}

Principal::~Principal()
{
}

void Principal::Executar()
{
	RenderWindow window(VideoMode(512, 512), "Indio", Style::Close);

	Texture player1Texture;
	Texture player2Texture;
	Texture backGround, oca;
	Texture ground1;
	Texture tronco;
	Texture cachorro;
	Texture inimigo;
	Texture spike;
	Texture granSpike;
	Texture canoaTextura;
	Texture hearth;
	Texture plat;

	cachorro.loadFromFile("imagens\\cachorrinhos.png");
	granSpike.loadFromFile("imagens\\grandspike.png");
	inimigo.loadFromFile("imagens\\macaquinhos.png");
	oca.loadFromFile("imagens\\oca_dia.png");
	ground1.loadFromFile("imagens\\ground_noite.png");
	backGround.loadFromFile("imagens\\fundo_noite.png");
	player1Texture.loadFromFile("imagens\\player1.png");
	player2Texture.loadFromFile("imagens\\player2.png");
	tronco.loadFromFile("imagens\\toco.png");
	canoaTextura.loadFromFile("imagens\\canoa.png");
	hearth.loadFromFile("imagens\\coracao.png");
	plat.loadFromFile("imagens\\plataforma_noite.png");
	
	View view(Vector2f(0.0f, 0.0f), Vector2f(512, 400.0f));

	//Inimigo * auxiliar;
	//auxiliar = new Inimigo(&inimigo, Vector2u(3, 1), 0.3f, 50.0f, 100.0f, Vector2f(40.0f, 50.0f), Vector2f(-1100.0f, 343.0f), 50.0f, 1);
	
	//Lista<Inimigo*> lista_inimigos;
	//lista_inimigos.incluir(auxiliar);

	//auxiliar = new Inimigo(&player2Texture, Vector2u(3, 1), 0.3f, 50.0f, 100.0f, Vector2f(40.0f, 50.0f), Vector2f(-1100.0f, 343.0f), 50.0f, 1);
	//lista_inimigos.incluir(auxiliar);

	srand(time(NULL));
	vector <Inimigo> inimigos;

		inimigos.push_back(Inimigo(&inimigo, Vector2u(3, 1), 0.3f, 50.0f, 100.0f, Vector2f(40.0f, 50.0f), Vector2f(-1100.0f, 343.0f), 50.0f, 1));
		inimigos.push_back(Inimigo(&cachorro, Vector2u(3, 1), 0.3f, 75.0f, 100.0f, Vector2f(40.0f, 50.0f), Vector2f(-800.0f, 341.0f), 100.0f, 1));
		inimigos.push_back(Inimigo(&inimigo, Vector2u(3, 1), 0.3f, 50.0f, 100.0f, Vector2f(40.0f, 50.0f), Vector2f(-300.0f, 343.0f), 50.0f, 1));
		inimigos.push_back(Inimigo(&cachorro, Vector2u(3, 1), 0.3f, 75.0f, 100.0f, Vector2f(40.0f, 50.0f), Vector2f(-100.0f, 341.0f), 100.0f, 1));
		inimigos.push_back(Inimigo(&inimigo, Vector2u(3, 1), 0.3f, 50.0f, 100.0f, Vector2f(40.0f, 50.0f), Vector2f(450.0f, 343.0f), 100.0f, 1));
		inimigos.push_back(Inimigo(&cachorro, Vector2u(3, 1), 0.3f, 50.0f, 100.0f, Vector2f(40.0f, 50.0f), Vector2f(700.0f, 341.0f), 100.0f, 1));
		inimigos.push_back(Inimigo(&inimigo, Vector2u(3, 1), 0.3f, 50.0f, 100.0f, Vector2f(40.0f, 50.0f), Vector2f(1200.0f, 343.0f), 100.0f, 1));
		inimigos.push_back(Inimigo(&inimigo, Vector2u(3, 1), 0.3f, 150.0f, 100.0f, Vector2f(40.0f, 50.0f), Vector2f(-512.0f, 267.0f), 100.0f, 1));
		
		vector <Plataforma> plats;

		plats.push_back(Plataforma(&ground1, Vector2f(3064.0f, 88.0f), Vector2f(200.0f, 410.0f)));
		plats.push_back(Plataforma(&plat, Vector2f(300.0f, 35.0f), Vector2f(-550.0f, 300.0f)));
		plats.push_back(Plataforma(&plat, Vector2f(300.0f, 35.0f), Vector2f(200.0f, 300.0f)));
		plats.push_back(Plataforma(&plat, Vector2f(300.0f, 35.0f), Vector2f(950.0f, 300.0f)));
		plats.push_back(Plataforma(nullptr, Vector2f(3.0f, 1000.0f), Vector2f(-1340.0f, 500.0f)));
		plats.push_back(Plataforma(nullptr, Vector2f(3.0f, 1000.0f), Vector2f(1723.0f, 500.0f)));

		vector <Obstaculos> obstaculos;
		
		obstaculos.push_back(Espinhos(&granSpike, Vector2f(300.0f, 50.0f), Vector2f(-550.0f, 372.0f), true, 2));
		obstaculos.push_back(Espinhos(&granSpike, Vector2f(300.0f, 50.0f), Vector2f(200.0f, 372.0f), true, 2));
		obstaculos.push_back(Espinhos(&granSpike, Vector2f(300.0f, 50.0f), Vector2f(950.0f, 372.0f), true, 2));
		obstaculos.push_back(Tronco(&tronco, Vector2f(30.0f, 40.0f), Vector2f(-960.0f, 355.0f), false, 0));
		obstaculos.push_back(Tronco(&tronco, Vector2f(30.0f, 40.0f), Vector2f(-225.0f, 355.0f), false, 0));
		obstaculos.push_back(Tronco(&tronco, Vector2f(30.0f, 40.0f), Vector2f(87, 275.0f), false, 0));
		obstaculos.push_back(Tronco(&tronco, Vector2f(30.0f, 40.0f), Vector2f(-670, 275.0f), false, 0));

	vector <Plataforma> coracoes;
	coracoes.push_back(Plataforma(&hearth, Vector2f(20.0f, 20.0f), Vector2f(-1200.0f, 206.0f)));
	coracoes.push_back(Plataforma(&hearth, Vector2f(20.0f, 20.0f), Vector2f(-1200.0f, 206.0f)));
	coracoes.push_back(Plataforma(&hearth, Vector2f(20.0f, 20.0f), Vector2f(-1200.0f, 206.0f)));
	coracoes.push_back(Plataforma(&hearth, Vector2f(20.0f, 20.0f), Vector2f(-1200.0f, 206.0f)));
	coracoes.push_back(Plataforma(&hearth, Vector2f(20.0f, 20.0f), Vector2f(-1200.0f, 206.0f)));

	Plataforma cenario(&backGround, Vector2f(3064.0f, 660.0f), Vector2f(200.0f, 300.0f));
	Plataforma canoa(&canoaTextura, Vector2f(101.0f, 53.0f), Vector2f(-1300.0f, 375.0f));
	Plataforma oca1(&oca, Vector2f(236.0f, 189.0f), Vector2f(1528.0f, 293.0f));

	//Plataforma cenario2(&backGround, Vector2f(3064.0f, 660.0f), Vector2f(10200.0f, 300.0f));
	//Plataforma canoa2(&canoaTextura, Vector2f(101.0f, 53.0f), Vector2f(-11300.0f, 375.0f));
	//Plataforma oca2(&oca, Vector2f(236.0f, 189.0f), Vector2f(11528.0f, 293.20f));

	Jogador player(&player1Texture, Vector2u(3, 1), 0.3f, 150.0f, 100.0f, Vector2f(40.0f, 50.0f), Vector2f(-1300.0f, 341.0f), 10, false);
	Jogador player2(&player2Texture, Vector2u(3, 1), 0.25f, 100.0f, 150.0f, Vector2f(40.0f, 50.0f), Vector2f(-1300.0f, 341.0f), 50, false);

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
		player.Update(deltaTime, 1);
		player2.Update(deltaTime, 2);

		for (Inimigo & inimigo : inimigos)
		{
			esquerda = inimigo.mover(deltaTime, esquerda);
			//if(inimigo.get_posicao().x == inimigo.get_posMax())
		}

		for (Inimigo & inimigo : inimigos)
			if (inimigo.get_colisor().checaColisao(player.get_colisor(), direction, 1.0f))
			{
				if (player.get_vida() <= 0)
					break;
				else if (!pulapratras)
				{
					player--;
					pulapratras = true;
					player.set_noChao(false);
					coracoes.pop_back();
					break;
				}
			}
		for (Obstaculos & obstaculo : obstaculos)
			if (obstaculo.get_colisor().checaColisao(player.get_colisor(), direction, 1.0f))
			{
				player.emColisao(direction);
				if (obstaculo.get_dano())
				{
					if (player.get_vida() <= 0)
						break;
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
		if (player.get_vida() <= 0)
			break;
		for (Plataforma & plataforma : plats)
		{
			if (plataforma.get_colisor().checaColisao(player.get_colisor(), direction, 1.0f))
				player.emColisao(direction);
			if (plataforma.get_colisor().checaColisao(player2.get_colisor(), direction, 1.0f))
				player2.emColisao(direction);
		}
		if (pulapratras)
		{
			player.pular(deltaTime, aux);
			if (player.get_noChao())
			{
				pulapratras = false;
				aux = true;
			}
		}

		i = 0;

		if (player.get_posicao().x < -1072.0f)
		{
			view.setCenter(Vector2f(-1072.0f, 206.0f));
			//view.setCenter(Vector2f(-1072.0f, player.get_posicao().y));
			for (Plataforma &coracao : coracoes)
			{
				coracao.set_posicao(Vector2f(-1280.0f + i, 100.0f));
				i += 22;
			}
		}
		else if (player.get_posicao().x > 1460.0f)
		{
			view.setCenter(Vector2f(1460.0f, 206.0f));
			//view.setCenter(Vector2f(1460.0f, player.get_posicao().y));
			for (Plataforma &coracao : coracoes)
			{
				coracao.set_posicao(Vector2f(1252.0f + i, 100.0f));
				i += 22;
			}
		}
		else
		{
			view.setCenter(Vector2f(player.get_posicao().x, 206.0f));
			//view.setCenter(Vector2f(player.get_posicao().x, player.get_posicao().y));
			for (Plataforma &coracao : coracoes)
			{
				coracao.set_posicao(Vector2f(player.get_posicao().x - 208.7f + i, 100.0f));
				i += 22;
			}
		}

		window.clear(Color(150, 150, 150));
		window.setView(view);

		cenario.desenhar(window);
		oca1.desenhar(window);
		//for (i = 0; i < lista_inimigos.get_tamanho(); i++)
		//	lista_inimigos.get_infoPrimeiro()->desenhar(window);

		for (Plataforma & coracao : coracoes)
			coracao.desenhar(window);

		for (Obstaculos & obstaculo : obstaculos)
			obstaculo.desenhar(window);

		for (Plataforma & plataforma : plats)
			plataforma.desenhar(window);

		for (Inimigo & inimigo : inimigos)
			inimigo.desenhar(window);

		canoa.desenhar(window);
		player2.desenhar(window);
		player.desenhar(window);
		//cout << player.get_posicao().x << endl;
		window.display();
	}
}
