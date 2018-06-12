#pragma once
#include "Obstaculos.h"
class Espinhos :
	public Obstaculos
{
public:
	Espinhos();
	Espinhos(Texture * textura, Vector2f tamanho, Vector2f posicao, bool dano_aux, int qtdDano_aux);
	virtual ~Espinhos();
};

