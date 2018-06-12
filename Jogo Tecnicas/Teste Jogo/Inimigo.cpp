#include "Inimigo.h"

Inimigo::Inimigo() :Personagem()
{
	posMax = 0.0f;
	posMin = 0.0f;
}

Inimigo::Inimigo(Texture * textura, Vector2u qtdImagem, float troca, float vel_aux, float altPulo_aux, Vector2f tamPersonagem, Vector2f posicao, float distancia, int qtdDano_aux)
	:Personagem(textura, qtdImagem, troca, vel_aux, altPulo_aux, tamPersonagem, posicao)
{
	posMax = posicao.x + distancia;
	posMin = posicao.x - distancia;
	qtdDano = qtdDano_aux;
}

Inimigo::~Inimigo()
{
}

bool Inimigo::mover(float deltaTime, bool andaEsquerda)
{
	vel.x = 0.0f;
	if (!andaEsquerda)
	{
		if (corpo.getPosition().x < posMax)
		{
			corpo.move(velocidade*deltaTime, 0.0f);
			corpo.setTextureRect(animacao.uvRect);
			animacao.Update(0, deltaTime, true, 3);
			return false;
		}
		else if (corpo.getPosition().x >= posMax)
			return true;
	}
	else if (andaEsquerda)
	{
		if (corpo.getPosition().x >= posMin)
		{
			corpo.move(-velocidade * deltaTime, 0.0f);
			corpo.setTextureRect(animacao.uvRect);
			animacao.Update(0, deltaTime, false, 3);
			return true;
		}
		else if (corpo.getPosition().x <= posMin)
			return false;
	}
}
