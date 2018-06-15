#include "Tronco.h"
#include <iostream>
using namespace std;

Tronco::Tronco(Vector2f posicao):Obstaculos()
{
	Texture * tex = new Texture;
	tex->loadFromFile("imagens\\tronco.png");
	set_textura(tex);
	set_dano(false);
	set_posicao(posicao);
	set_tamanho(Vector2f(30.0f, 40.0f));
	set_visivel(true);
}

Tronco::Tronco(Texture * textura, Vector2f tamanho, Vector2f posicao, const bool visivel_aux, const bool dano_aux)
	:Obstaculos(textura, tamanho, posicao, visivel_aux, dano_aux)
{
}

Tronco::~Tronco()
{
	
}
