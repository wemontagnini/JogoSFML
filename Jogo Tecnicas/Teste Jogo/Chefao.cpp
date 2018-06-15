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
	float auxiliar = posPlayer - get_posicao().x;
	if (auxiliar < 0)
	{
		corpo.move(-velocidade*deltaTime, 0.0f);
		corpo.setTextureRect(animacao.uvRect);
		animacao.Update(0, deltaTime, false, 3);
	}
	else if (auxiliar > 0)
	{
		corpo.move(velocidade * deltaTime, 0.0f);
		corpo.setTextureRect(animacao.uvRect);
		animacao.Update(0, deltaTime, true, 3);

	}
}
