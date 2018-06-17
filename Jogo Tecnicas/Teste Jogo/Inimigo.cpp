#include "Inimigo.h"

Inimigo::Inimigo() :Personagem()
{
	posMax = 0.0f;
	posMin = 0.0f;
}

Inimigo::Inimigo(Texture * textura, Vector2u qtdImagem, float troca, float vel_aux, float altPulo_aux, Vector2f tamPersonagem, Vector2f posicao, float distancia)
	:Personagem(textura, qtdImagem, troca, vel_aux, altPulo_aux, tamPersonagem, posicao)
{
	posMax = posicao.x + distancia;
	posMin = posicao.x - distancia;
}

Inimigo::~Inimigo()
{
}

bool Inimigo::mover(float deltaTime, bool andaEsquerda)
{
	//vel.y += 981.0f*deltaTime;
	vel.x = 0.0f;
	if (!andaEsquerda)
	{
		if (corpo.getPosition().x < posMax)
		{
			corpo.move(velocidade*deltaTime, vel.y);
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
			corpo.move(-velocidade * deltaTime, vel.y);
			corpo.setTextureRect(animacao.uvRect);
			animacao.Update(0, deltaTime, false, 3);
			return true;
		}
		else if (corpo.getPosition().x <= posMin)
			return false;
	}
}
