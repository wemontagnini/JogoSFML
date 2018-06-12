#include "SFML/Graphics.hpp"
#include "Animacao.h"
#include "Colisor.h"
#pragma once
using namespace sf;

class Personagem
{
protected:
	RectangleShape corpo;
	Animacao animacao;
	unsigned int linha;
	float velocidade;
	bool viradoDireita;
	Vector2f vel;
	bool noChao;
	float altPulo;

public:
	Personagem();
	Personagem(Texture * texura, Vector2u qtdImagem, float troca, float vel_aux, float altPulo_aux,  Vector2f tamPersonagem, Vector2f posicao);
	virtual ~Personagem();
	void Update(float deltaTime, int i); //vel, noChao, linha, viradoDireita não podem ser const, são alterados na funcao
	void emColisao(Vector2f direcao); //direcao, vel e noChao nao podem ser const, são alterados na função
	void desenhar(RenderWindow & window) { window.draw(corpo); }
	void mover(Vector2f auxiliar) { corpo.move(auxiliar); }
	void set_posicao(Vector2f auxiliar) { corpo.setPosition(auxiliar); }
	//Gets Necessários
	bool get_noChao() { return noChao; }
	RectangleShape get_corpo() { return corpo; }
	Vector2f get_posicao() { return corpo.getPosition(); }
	Colisor get_colisor() { return Colisor(corpo); }
	//Set Necessário
	void set_noChao(const bool noChao_aux) { noChao = noChao_aux; }
	//void set_textura(const Textura * tex_aux) { corpo.setTexture(tex_aux); }
};

