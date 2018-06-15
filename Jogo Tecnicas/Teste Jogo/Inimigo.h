#pragma once
#include "Personagem.h"
class Inimigo :
	public Personagem
{
private:
	float posMax;
	float posMin;

public:
	Inimigo();
	Inimigo(Texture * textura, Vector2u qtdImagem, float troca, float vel_aux, float altPulo_aux, Vector2f tamPersonagem, Vector2f posicao, float distancia);
	virtual ~Inimigo();
	bool mover(float deltaTime, bool andaEsquerda); // anda esquerda nao pode ser const, é alterado o valor
	float get_posMax() { return posMax; }


};

