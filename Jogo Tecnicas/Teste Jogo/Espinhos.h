#pragma once
#include "Obstaculos.h"

class Espinhos :
	public Obstaculos
{
public:
	Espinhos(const Vector2f posicao);
	Espinhos(Texture * textura, Vector2f tamanho, Vector2f posicao, const bool visivel_aux, const bool dano_aux);
	virtual ~Espinhos();
	void Update(const float deltaTime) {}
};

