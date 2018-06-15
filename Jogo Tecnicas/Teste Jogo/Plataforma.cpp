#include "Plataforma.h"

Plataforma::Plataforma()
{
}
Plataforma::Plataforma(Texture * textura, Vector2f tamanho, Vector2f posicao, const bool visivel_aux)
{
	corpo.setSize(tamanho);
	corpo.setOrigin(tamanho / 2.0f);
	corpo.setTexture(textura);
	corpo.setPosition(posicao);
	visivel = visivel_aux;
}

Plataforma::~Plataforma()
{
}
