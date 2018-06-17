#include "Chefao.h"

Chefao::Chefao(Texture * textura, Vector2u qtdImagem, float troca, float vel_aux, float altPulo_aux, Vector2f tamPersonagem, Vector2f posicao, float distancia)
	:Inimigo(textura, qtdImagem, troca, vel_aux, altPulo_aux, tamPersonagem, posicao, distancia)
{
}

Chefao::~Chefao()
{
}

void Chefao::andar(const float deltaTime, const float posPlayer)
{
	vel.x = 0.0f;
	float posicao = posPlayer - get_posicao().x;
	float podeAndar = abs(posPlayer) - abs(get_posicao().x);
	bool lado;
	if (posicao < 0)
		lado = false;
	else
		lado = true;
	if (abs(podeAndar) > 0.1f)
	{
		if (posicao < 0)
		{
			corpo.move(-velocidade * deltaTime, 0.0f);
			corpo.setTextureRect(animacao.uvRect);
			animacao.Update(0, deltaTime, false, 1);
			
		}
		else if (posicao > 0)
		{
			corpo.move(velocidade * deltaTime, 0.0f);
			corpo.setTextureRect(animacao.uvRect);
			animacao.Update(0, deltaTime, true, 1);
		}
	}
	else
	{
		corpo.setTextureRect(animacao.uvRect);
		animacao.Update(0, deltaTime, lado, 1);
	}

}
