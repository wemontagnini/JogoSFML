#include "Obstaculos.h"

Obstaculos::Obstaculos()
{
}

Obstaculos::Obstaculos(Texture * textura, Vector2f tamanho, Vector2f posicao, const bool visivel_aux, const bool dano_aux)
{
	corpo.setSize(tamanho);
	corpo.setOrigin(tamanho / 2.0f);
	corpo.setTexture(textura);
	corpo.setPosition(posicao);
	visivel = visivel_aux;
	dano = dano_aux;
}

Obstaculos::~Obstaculos()
{
}
