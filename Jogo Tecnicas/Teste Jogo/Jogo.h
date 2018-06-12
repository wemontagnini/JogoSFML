#include "SFML/Graphics.hpp"
#include "Fase.h"
#include "Jogador.h"
using namespace std;
using namespace sf;
#pragma once
class Jogo
{
private:
	Jogador * pjogadores;
	bool pause;
	bool coop;
	Fase fase1;
	Fase fase2;

public:
	Jogo();
	virtual ~Jogo();
	void Executar(const bool coop_aux);
};

