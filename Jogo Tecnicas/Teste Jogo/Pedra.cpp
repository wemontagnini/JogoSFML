#include "Pedra.h"

Pedra::Pedra() :Obstaculos()
{
}
Pedra::Pedra(Texture * textura, Vector2f tamanho, Vector2f posicao, bool dano_aux, int qtdDano_aux)
	:Obstaculos(textura, tamanho, posicao, dano_aux, qtdDano_aux)
{
}

Pedra::~Pedra()
{
}