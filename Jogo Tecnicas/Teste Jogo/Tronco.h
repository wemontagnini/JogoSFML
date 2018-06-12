#pragma once
#include "Obstaculos.h"
class Tronco :
	public Obstaculos
{
public:
	Tronco();
	Tronco(Texture * textura, Vector2f tamanho, Vector2f posicao, bool dano_aux, int qtdDano_aux);
	virtual ~Tronco();
};

