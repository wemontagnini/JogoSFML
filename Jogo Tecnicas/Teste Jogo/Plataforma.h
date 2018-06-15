#include "SFML/Graphics.hpp"
#include "Colisor.h"
#pragma once
using namespace sf;
class Plataforma
{
private:
	RectangleShape corpo;
	bool visivel;
public:
	Plataforma();
	Plataforma(Texture * textura, Vector2f tamanho, Vector2f posicao, const bool visivel_aux);
	virtual ~Plataforma();

	void desenhar(RenderWindow &window) { if (visivel) { window.draw(corpo); } }
	Colisor get_colisor() { return Colisor(corpo); }
	Vector2f get_posicao() { return corpo.getPosition(); }
	void set_posicao(const Vector2f pos_aux) { corpo.setPosition(pos_aux); }
	void set_textura(Texture * tex_aux) { corpo.setTexture(tex_aux); }
	void set_tamanho(const Vector2f tam_aux) { corpo.setSize(tam_aux); corpo.setOrigin(tam_aux / 2.0f);}
	void set_visivel(const bool visivel_aux) { visivel = visivel_aux; }
	void set_texturaRect(const IntRect aux) { corpo.setTextureRect(aux); }
};

