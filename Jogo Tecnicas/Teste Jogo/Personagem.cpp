#include "Personagem.h"
Personagem::Personagem() :animacao()
{
	altPulo = 0.0f;
	velocidade = 0.0f;
	linha = 0;
	viradoDireita = true;
}

Personagem::Personagem(Texture * textura, Vector2u qtdImagem, float troca, float velocidade_aux, float altPulo_aux, Vector2f tamPersonagem, Vector2f posicao)
	:animacao(textura, qtdImagem, troca)
{
	altPulo = altPulo_aux;
	velocidade = velocidade_aux;
	linha = 0;
	viradoDireita = true;

	corpo.setSize(tamPersonagem);
	corpo.setPosition(posicao);
    corpo.setTexture(textura);
	corpo.setOrigin(corpo.getSize() / 2.0f);
}

Personagem::~Personagem()
{
}

void Personagem::Update(float deltaTime, int i)
{
	int colunas = 0;
	vel.x = 0.0f;
	if (i == 1)
	{
		if (Keyboard::isKeyPressed(Keyboard::A))
			vel.x -= velocidade;
		if (Keyboard::isKeyPressed(Keyboard::D))
			vel.x += velocidade;

		if (Keyboard::isKeyPressed(Keyboard::W) && noChao)
		{
			noChao = false;
			vel.y = -sqrtf(2.0f * 981.0f * altPulo);
		}
	}
	else if (i == 2)
	{
		if (Keyboard::isKeyPressed(Keyboard::Left))
			vel.x -= velocidade;
		if (Keyboard::isKeyPressed(Keyboard::Right))
			vel.x += velocidade;

		if (Keyboard::isKeyPressed(Keyboard::Up) && noChao)
		{
			noChao = false;
			vel.y = -sqrtf(2.0f * 981.0f * altPulo);
		}
	}
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

void Personagem::emColisao(Vector2f direcao)
{
	if (direcao.x < 0.0f)
		vel.x = 0.0f; //Colisao na direita
	if (direcao.x > 0.0f)
		vel.x = 0.0f; //Colisao na esquerda
	if (direcao.y < 0.0f)
	{
		vel.y = 0.0f; //Colisao no chao
		noChao = true;
	}
	if (direcao.y > 0.0f)
		vel.y = 0.0f; // Colisao no topo
}
