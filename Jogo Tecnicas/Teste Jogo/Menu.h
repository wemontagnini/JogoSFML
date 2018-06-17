#include "SFML/Graphics.hpp"
#include "Jogador.h"
#include <vector>
#pragma once
using namespace sf;

class Menu
{
protected:
	RectangleShape menu;
public:
	Menu();
	virtual ~Menu();
	void desenhar(RenderWindow & window) { window.draw(menu); }
	virtual void executarMenu(RenderWindow & window, View & view, int & escolha) {}
	virtual void executarMenu(RenderWindow & window, View & view, int & escolha, vector<Jogador*> lista_players) {}
};

