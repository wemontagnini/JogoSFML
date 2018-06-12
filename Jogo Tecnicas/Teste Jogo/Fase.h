#include "SFML/Graphics.hpp"
#include"Plataforma.h"
#include "Espinhos.h"
#include "Fogo.h"
#include "Pedra.h"
#include "Tronco.h"
#include "Jogador.h"
#include "Inimigo.h"
#include <vector>
using namespace std;
using namespace sf;
#pragma once
class Fase
{
private:

public:
	Fase();
	virtual ~Fase();
	void iniciaFase(int i);
};

