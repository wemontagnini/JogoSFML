#include "Animacao.h"

Animacao::Animacao()
{
	troca = 0;
	qtdImagem = Vector2u(0, 0);
	tempoTotal = 0.0f;
	imagemAtual.x = 0;
	uvRect.height = 0;
	uvRect.width = 0;
}

Animacao::Animacao(Texture * textura, Vector2u qtdImagem_aux, float troca_aux)
{
	troca = troca_aux;
	qtdImagem = qtdImagem_aux;
	tempoTotal = 0.0f;
	imagemAtual.x = 0;
	uvRect.width = textura->getSize().x / float(qtdImagem.x);
	uvRect.height = textura->getSize().y / float(qtdImagem.y);
}

Animacao::~Animacao()
{
}

void Animacao::Update(int linha, float deltaTime, bool viradoDireita, int colunas)
{
	imagemAtual.y = linha;
	tempoTotal += deltaTime;

	if (tempoTotal >= troca)
	{
		tempoTotal -= troca;
		if (colunas)
		{
			imagemAtual.x++;
			if (imagemAtual.x >= qtdImagem.x)
					imagemAtual.x = 0;
		}
		else
			imagemAtual.x = 1;
	}
	uvRect.top = imagemAtual.y * uvRect.height;

	if (viradoDireita)
	{
		uvRect.left = imagemAtual.x *uvRect.width;
		uvRect.width = abs(uvRect.width);
	}
	else
	{
		uvRect.left = (imagemAtual.x + 1) *abs(uvRect.width);
		uvRect.width = -abs(uvRect.width);
	}
}