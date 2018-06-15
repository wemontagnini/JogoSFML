#include "Fogo.h"

Fogo::Fogo(Vector2f posicao):Obstaculos(), animacao()
{
	Texture * tex = new Texture;
	tex->loadFromFile("imagens\\fogo.png");
	set_textura(tex);
	set_dano(true);
	set_posicao(posicao);
	set_tamanho(Vector2f(30.0f, 40.0f));
	set_visivel(true);
	animacao.set_qtdImagem(Vector2u(6, 1));
	animacao.set_textura(tex);
	animacao.set_troca(0.25f);
}

Fogo::Fogo(Texture * textura, Vector2f tamanho, Vector2f posicao,bool visivel_aux, const bool dano_aux, Vector2u qtdImagem_aux, const float troca_aux)
	:Obstaculos(textura, tamanho, posicao, visivel_aux, dano_aux), animacao(textura, qtdImagem_aux, troca_aux)
{
}

Fogo::~Fogo()
{
}

void Fogo::Update(const float deltaTime)
{
	animacao.Update(0, deltaTime, true, 1);
	set_texturaRect(animacao.uvRect);
}

