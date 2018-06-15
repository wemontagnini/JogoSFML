#pragma once
#include <SFML/graphics.hpp>
using namespace sf;

class Animacao
{
private:
	Vector2u qtdImagem;
	Vector2u imagemAtual;
	float tempoTotal;
	float troca;

public:
	IntRect uvRect;
	Animacao();
	Animacao(Texture * textura, Vector2u qtdImagem_aux, float troca_aux);
	~Animacao();
	void Update(int linha, float deltaTime, bool viradoDireita, int colunas); // viradoDireita, linha e colunas são modificados na funcao
	void set_qtdImagem(const Vector2u qtdImagem_aux) { qtdImagem = qtdImagem_aux; }
	void set_troca(const float troca_aux) { troca = troca_aux; }
	void set_textura(const Texture * textura_aux){
		uvRect.width = float(textura_aux->getSize().x) / float(qtdImagem.x);
		uvRect.height = float(textura_aux->getSize().y) / float(qtdImagem.y);
	}

};

