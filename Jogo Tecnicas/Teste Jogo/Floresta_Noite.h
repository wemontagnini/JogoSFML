#pragma once
#include "Fase.h"
#include "MenuPausa.h"
class Floresta_Noite :
	public Fase
{
public:
	Floresta_Noite();
	virtual ~Floresta_Noite();
	void carrega_florestaNoite();
	bool executar(vector<Jogador*> lista_players, View & view, RenderWindow & window, MenuPausa & menu);
};

