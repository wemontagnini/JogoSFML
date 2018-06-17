#pragma once
#include "Fase.h"
#include "MenuPausa.h"
class Floresta_Dia :
	public Fase
{
public:
	Floresta_Dia();
	virtual ~Floresta_Dia();

	void carrega_florestaDia();
	bool executar(vector<Jogador*> lista_players, View & view, RenderWindow & window, MenuPausa & menu);
};

