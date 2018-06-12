#include "SFML/Graphics.hpp"
#pragma once
#include "Plataforma.h"
class Obstaculos :
	public Plataforma
{
protected:
	bool dano;
	int qtdDano;
public:
	Obstaculos();
	Obstaculos(Texture * textura, Vector2f tamanho, Vector2f posicao, bool dano_aux, int qtdDano_aux);
	virtual ~Obstaculos();

	bool get_dano() { return dano; }
	int get_qtdDano() { return qtdDano; }
};

