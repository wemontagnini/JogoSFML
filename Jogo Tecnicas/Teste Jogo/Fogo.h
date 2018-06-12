#include "SFML/Graphics.hpp"
#include "Animacao.h"
#pragma once
#include "Obstaculos.h"
class Fogo :
	public Obstaculos
{
private:
	Animacao animacao;
public:
	Fogo();
	Fogo(Texture * textura, Vector2f tamanho, Vector2f posicao, bool dano_aux, int qtdDano_aux, Vector2u qtdImagem_aux, float troca_aux);
	virtual ~Fogo();
};

