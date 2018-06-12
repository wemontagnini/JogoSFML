#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>
using namespace sf;

class Colisor
{
private:
	RectangleShape& corpo;

public:
	Colisor(RectangleShape& corpo);
	~Colisor();
	
	void mover(Vector2f mover) { corpo.move(mover); }
	bool checaColisao(Colisor outro, Vector2f &direcao, float empurra);
	Vector2f get_posicao() { return corpo.getPosition(); }
	Vector2f get_metade() { return (corpo.getSize() / 2.0f); }

};

