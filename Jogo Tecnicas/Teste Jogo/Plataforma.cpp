#include "Plataforma.h"

Plataforma::Plataforma()
{
}
Plataforma::Plataforma(Texture * textura, Vector2f tamanho, Vector2f posicao)
{
	corpo.setSize(tamanho);
	corpo.setOrigin(tamanho / 2.0f);
	corpo.setTexture(textura);
	corpo.setPosition(posicao);
}

Plataforma::~Plataforma()
{
}
