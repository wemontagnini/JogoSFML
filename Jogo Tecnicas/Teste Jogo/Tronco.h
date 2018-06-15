#pragma once
#include "Obstaculos.h"
class Tronco :
	public Obstaculos
{
public:
	Tronco(Vector2f(posicao));
	Tronco(Texture * textura, Vector2f tamanho, Vector2f posicao, const bool visivel_aux, const bool dano_aux);
	virtual ~Tronco();
	void Update(const float deltaTime) {}
};

