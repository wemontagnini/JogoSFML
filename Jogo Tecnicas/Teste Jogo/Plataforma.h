#include "SFML/Graphics.hpp"
#include "Colisor.h"
#pragma once
using namespace sf;
class Plataforma
{
private:
	RectangleShape corpo;
public:
	Plataforma();
	Plataforma(Texture * textura, Vector2f tamanho, Vector2f posicao);
	virtual ~Plataforma();

	void desenhar(RenderWindow &window) { window.draw(corpo); }
	Colisor get_colisor() { return Colisor(corpo); }
	Vector2f get_posicao() { return corpo.getPosition(); }
	void set_posicao(const Vector2f aux) { corpo.setPosition(aux); }
};

