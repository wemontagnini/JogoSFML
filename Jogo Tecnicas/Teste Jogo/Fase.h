#include "SFML/Graphics.hpp"
#include"Plataforma.h"
#include "Espinhos.h"
#include "Fogo.h"
#include "Pedra.h"
#include "Tronco.h"
#include "Jogador.h"
#include "Inimigo.h"
#include "Obstaculos.h"
#include "Chefao.h"
#include "Cenario.h"
#include <vector>
using namespace std;
using namespace sf;
#pragma once
class Fase
{
protected:
	vector <Inimigo*> lista_inimigos;
	vector <Obstaculos*> lista_obstaculos;
	vector <Plataforma*> lista_plataformas;
	vector <Cenario*> lista_cenario;

public:
	Fase();
	virtual ~Fase();
	void setVectors(const bool fase1);
	void arrumaCamera(vector<Jogador*> lista_players, View & view, vector<Plataforma*> lista_view);
	void esvaziaVectors();



};

