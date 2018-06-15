#include "SFML/Graphics.hpp"
#pragma once
#include "Inimigo.h"
using namespace sf;
class Chefao :
	public Inimigo
{
public:
	Chefao(Texture * textura, Vector2u qtdImagem, float troca, float vel_aux, float altPulo_aux, Vector2f tamPersonagem, Vector2f posicao, float distancia);
	virtual ~Chefao();

	void andar(const float deltaTime, const float posPlayercorpo);
};

