#include "SFML/Graphics.hpp"
#include "Floresta_Dia.h"
#include "Floresta_Noite.h"
#include "Jogador.h"
#include "Chefao.h"
#include "Inimigo.h"
#include "Obstaculos.h"
#include "Plataforma.h"
#include "MenuPausa.h"
#include "MenuPrincipal.h"
#include <vector>
using namespace std;
using namespace sf;
#pragma once
class Jogo
{
private:
	vector <Jogador*> lista_jogadores;
	Floresta_Dia dia;
	Floresta_Noite noite;
	bool pause;
	bool coop;
	MenuPrincipal menu_principal;
	MenuPausa menu_pausa;

public:
	Jogo();
	virtual ~Jogo();
	void Executar();
};

