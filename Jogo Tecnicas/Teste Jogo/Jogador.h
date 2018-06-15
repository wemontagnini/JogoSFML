#include "SFML/Graphics.hpp"
#pragma once
#include "Personagem.h"
#include "Cenario.h"
#include <vector>
using namespace std;

class Jogador :
	public Personagem
{
private:
	bool coop;
	int vida;
	int pontos;
	vector <Cenario> lista_coracoes;

public:

	Jogador();
	Jogador(Texture * textura, Vector2u qtdImagem, float troca, float vel_aux, float altPulo_aux, Vector2f tamPersonagem, Vector2f posicao, int vida_aux ,bool coop_aux);
	virtual ~Jogador();
	void pular(float deltaTime, bool& aux);
	void set_coop(bool coop_aux) { coop = coop_aux; }
	bool get_coop() { return coop; }
	void mover(Vector2f auxiliar) { corpo.move(auxiliar); }
	int get_vida() { return vida; }
	int get_pontos() { return pontos; }
	void operator--(int) { vida-= 2; }
	void operator++(int) { pontos += 10; }
	vector <Cenario> get_lista_coracoes() { return lista_coracoes; }

};

