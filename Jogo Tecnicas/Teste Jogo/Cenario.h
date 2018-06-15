#pragma once
#include "Plataforma.h"
class Cenario :
	public Plataforma
{
public:
	Cenario(Texture * textura, Vector2f tamanho, Vector2f posicao, const bool visivel_aux);
	virtual ~Cenario();
	//virtual void Update(const int linha, const float deltaTime, const bool viradoDireita, const int colunas) = 0;
};

