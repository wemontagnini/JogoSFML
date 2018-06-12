#include "SFML/Graphics.hpp"
#include "Plataforma.h"
#include "Espinhos.h"
#include "Fogo.h"
#include "Pedra.h"
#include "Tronco.h"
#include "Jogador.h"
#include "Inimigo.h"
#include "Jogo.h"
#include <vector>
#include "Lista.h"

using namespace std;
using namespace sf;
#pragma once

class Principal
{
private:

	Jogo j;
	Jogador p;

public:

	Principal();
	virtual ~Principal();

	void Executar();

};

