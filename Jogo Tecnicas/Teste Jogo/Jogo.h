#include "SFML/Graphics.hpp"
#include "Fase.h"
#include "Jogador.h"
#include "Chefao.h"
#include "Inimigo.h"
#include "Obstaculos.h"
#include "Plataforma.h"
#include "Menu.h"
#include <vector>
using namespace std;
using namespace sf;
#pragma once
class Jogo
{
private:
	vector <Jogador> lista_jogadores;
	Fase fase;
	bool pause;
	bool coop;
	Menu menu;

public:
	Jogo();
	virtual ~Jogo();
	void Executar(const bool coop_aux);
};

