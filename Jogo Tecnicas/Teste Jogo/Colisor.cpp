#include "Colisor.h"
using namespace sf;
using namespace std;



Colisor::Colisor(RectangleShape& corpo):
	corpo(corpo)
{
}


Colisor::~Colisor()
{
}

bool Colisor::checaColisao(Colisor outro, Vector2f &direcao, float empurra)
{
	Vector2f outroPosicao = outro.get_posicao();
	Vector2f outroMetade = outro.get_metade();
	Vector2f posicaoAtual = get_posicao();
	Vector2f metadeAtual = get_metade();

	float deltaX = outroPosicao.x - posicaoAtual.x;
	float deltaY = outroPosicao.y - posicaoAtual.y; 
	float intersecX = abs(deltaX) - (outroMetade.x + metadeAtual.x);
	float intersecY = abs(deltaY) - (outroMetade.y + metadeAtual.y); 


	if (intersecX < 0.0f && intersecY < 0.0f)
	{
		empurra = min(max(empurra, 0.0f), 1.0f);
		if (intersecX > intersecY)
		{
			if (deltaX > 0.0f)
			{
				mover(Vector2f(intersecX * (1.0f - empurra), 0.0f));
				outro.mover(Vector2f(-intersecX * empurra, 0.0f));
				direcao.x = 1.0f;
				direcao.y = 0.0f;
			}
			else
			{
				mover(Vector2f(-intersecX * (1.0f - empurra), 0.0f));
				outro.mover(Vector2f(intersecX * empurra, 0.0f));
				direcao.x = -1.0f;
				direcao.y = 0.0f;
			}
		}
		else
		{
			if (deltaY > 0.0f)
			{
				mover(Vector2f(0.0f, intersecY *(1.0f - empurra)));
				outro.mover(Vector2f(0.0f, -intersecY * empurra));
				direcao.x = 0.0f;
				direcao.y = 1.0f;
			}
			else
			{
				mover(Vector2f(0.0f, -intersecY * (1.0f - empurra)));
				outro.mover(Vector2f(0.0f, intersecY * empurra));
				direcao.x = 0.0f;
				direcao.y = -1.0f;
			}
		}
		return true;
	}
	return false;
}