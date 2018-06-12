#pragma once
#include "Obstaculos.h"
class Pedra :
	public Obstaculos
{
public:
	Pedra();
	Pedra(Texture * textura, Vector2f tamanho, Vector2f posicao, bool dano_aux, int qtdDano_aux);
	virtual ~Pedra();
};

