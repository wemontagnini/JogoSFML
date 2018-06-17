#include "Espinhos.h"


Espinhos::Espinhos(const Vector2f posicao) :Obstaculos()
{
	Texture * tex = new Texture;
	tex->loadFromFile("imagens\\grandspike.png");
	set_textura(tex);
	set_dano(true);
	set_posicao(posicao);
	set_tamanho(Vector2f(320.0f, 50.0f));
	set_visivel(true);
}
Espinhos::Espinhos(Texture * textura, Vector2f tamanho, Vector2f posicao, const bool visivel_aux, const bool dano_aux)
	:Obstaculos(textura, tamanho, posicao, visivel_aux, dano_aux)
{
	
}

Espinhos::~Espinhos()
{
}
