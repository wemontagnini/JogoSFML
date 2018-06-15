#include "Pedra.h"


Pedra::Pedra(Texture * textura, Vector2f tamanho, Vector2f posicao, bool dano_aux)
	:Obstaculos(textura, tamanho, posicao, dano_aux)
{
}

Pedra::~Pedra()
{
}
