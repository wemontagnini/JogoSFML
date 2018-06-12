#include "Jogador.h"

Jogador::Jogador():Personagem()
{
	coop = false;
	vida = 0;
}

Jogador::Jogador(Texture * textura, Vector2u qtdImagem, float troca, float vel_aux, float altPulo_aux, Vector2f tamPersonagem, Vector2f posicao, int vida_aux, bool coop_aux)
	:Personagem(textura, qtdImagem, troca, vel_aux, altPulo_aux, tamPersonagem, posicao)
{
	coop = coop_aux;
	vida = vida_aux;
}

Jogador::~Jogador()
{
}

void Jogador::pular(float deltaTime, bool& aux)
{
	int colunas = 0;
	if (aux)
	{
		vel.y = -sqrtf(2.0f * 981.0f * altPulo);
		aux = false;
	}
	vel.x -= velocidade;

	vel.y += 981.0f * deltaTime;
	if (vel.x == 0.0f)
	{
		linha = 0;
		colunas = 0;
	}
	else
	{
		colunas = 3;
		linha = 0;

		if (vel.x > 0.0f)
			viradoDireita = true;
		else
			viradoDireita = false;
	}

	animacao.Update(linha, deltaTime, viradoDireita, colunas);
	corpo.setTextureRect(animacao.uvRect);
	mover(vel*deltaTime);
}
