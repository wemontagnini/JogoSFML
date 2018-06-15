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
	Fogo(Vector2f posicao);
	Fogo(Texture * textura, Vector2f tamanho, Vector2f posicao, bool visivel_aux, const bool dano_aux, Vector2u qtdImagem_aux, const float troca_aux);
	virtual ~Fogo();
	virtual void Update(const float deltaTime);
	Animacao get_animacao() { return animacao; }

};

