#include "Obstaculos.h"

Obstaculos::Obstaculos():Plataforma()
{
	dano = false;
	qtdDano = 0;
}
Obstaculos::Obstaculos(Texture * textura, Vector2f tamanho, Vector2f posicao, bool dano_aux, int qtdDano_aux)
	:Plataforma(textura, tamanho, posicao)
{
	dano = dano_aux;
	qtdDano = qtdDano_aux;
}

Obstaculos::~Obstaculos()
{
}
