#include "Jogo.h"

Jogo::Jogo()
{

}

Jogo::~Jogo()
{
}

void Jogo::Executar(const bool coop_aux)
{
	srand(time(NULL));
	if (rand() % 2)
	{
		fase1.iniciaFase(1);
		fase2.iniciaFase(1);
	}
	else if (rand() % 3)
	{
		fase1.iniciaFase(2);
		fase2.iniciaFase(2);
	}
	else
	{
		fase1.iniciaFase(3);
		fase2.iniciaFase(3);
	}
}
