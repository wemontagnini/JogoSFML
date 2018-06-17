#pragma once
#include "Menu.h"
class MenuPrincipal :
	public Menu
{
public:
	MenuPrincipal();
	virtual ~MenuPrincipal();
	void executarMenu(RenderWindow & window, View & view, int & escolha);

};

