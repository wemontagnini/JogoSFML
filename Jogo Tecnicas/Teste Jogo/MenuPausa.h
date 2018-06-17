#pragma once
#include "Menu.h"
#include "Jogador.h"
#include <vector>
#include <fstream>
class MenuPausa :
	public Menu
{
public:
	MenuPausa();
	virtual ~MenuPausa();
	void executarMenu(RenderWindow & window, int & escolha, vector<Jogador*> lista_players);
	void set_origem(Vector2f origem) { menu.setOrigin(origem); }
	void set_posicao(Vector2f posicao) { menu.setPosition(posicao); }
	//void executarMenu(RenderWindow & window, View & view, int & escolha, vector<Jogador*> lista_players);
	void salvarJogo(vector<Jogador*> lista_players);
};

