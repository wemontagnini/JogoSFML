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
	int tomandoDanoInimigo;
	int tomandoDanoObstaculo;

public:
	Personagem();
	Personagem(Texture * texura, Vector2u qtdImagem, float troca, float vel_aux, float altPulo_aux,  Vector2f tamPersonagem, Vector2f posicao);
	virtual ~Personagem();
	void Update(float deltaTime, const bool coop);
	//vel, noChao, linha, viradoDireita não podem ser const, são alterados na funcao
	void emColisao(Vector2f direcao); //direcao, vel e noChao nao podem ser const, são alterados na função
	void emDano(Personagem * player, Personagem * inimigo, const float deltaTime);
	void emDano(Personagem * player, const float deltaTime);
	void desenhar(RenderWindow & window) { window.draw(corpo); }
	void mover(Vector2f auxiliar) { corpo.move(auxiliar); }
	//Gets Necessários
	bool get_noChao() { return noChao; }
	RectangleShape get_corpo() { return corpo; }
	Vector2f get_posicao() { return corpo.getPosition(); }
	Colisor get_colisor() { return Colisor(corpo); }
	int get_tomandoDanoInimigo() { return tomandoDanoInimigo; }
	int get_tomandoDanoObstaculo() { return tomandoDanoObstaculo; }
	Vector2f get_vel() { return vel; }
	bool get_viradoDireita() { return viradoDireita; }
	float get_velocidade() { return velocidade; }
	float get_altPulo() { return altPulo; }

	//Set Necessário
	void set_noChao(const bool noChao_aux) { noChao = noChao_aux; }
	void set_textura(const Texture * tex_aux) { corpo.setTexture(tex_aux); }
	void set_tomandoDanoInimigo(const int dano_aux) { tomandoDanoInimigo = dano_aux; }
	void set_vel(const Vector2f vel_aux) { vel = vel_aux; }
	void set_tomandoDanoObstaculo(const int dano_aux) { tomandoDanoObstaculo = dano_aux; }
	void set_posicao(Vector2f auxiliar) { corpo.setPosition(auxiliar); }
};

