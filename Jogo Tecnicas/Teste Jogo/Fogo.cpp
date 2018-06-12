#include "Fogo.h"

Fogo::Fogo() :Obstaculos()
{
}
Fogo::Fogo(Texture * textura, Vector2f tamanho, Vector2f posicao, bool dano_aux, int qtdDano_aux, Vector2u qtdImagem_aux, float troca_aux)
	:Obstaculos(textura, tamanho, posicao, dano_aux, qtdDano_aux), animacao(textura, qtdImagem_aux, troca_aux)
{
}

Fogo::~Fogo()
{
}
