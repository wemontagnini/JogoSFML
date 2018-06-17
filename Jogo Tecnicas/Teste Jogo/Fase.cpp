#include "Fase.h"

Fase::Fase()
{
}

Fase::~Fase()
{
	esvaziaVectors();
}

void Fase::setVectors(const bool fase1)
{
	
}

void Fase::arrumaCamera(vector<Jogador*> lista_players, View & view, vector<Plataforma*> lista_view)
{
	int k = 0;
	float posicao;
	if (lista_players.size() == 1)
	{
		posicao = lista_players[0]->get_posicao().x;
		if (lista_players[0]->get_posicao().x < -1072.0f)
		{
			view.setCenter(Vector2f(-1072.0f, 206.0f));
			for (int j = 0; j < lista_players[0]->get_lista_coracoes().size(); j++)
			{
				lista_players[0]->get_lista_coracoes()[j]->set_posicao(Vector2f(-1280.0f + k, 100.0f));
				k += 22;
			}
		}
		else if (lista_players[0]->get_posicao().x > 1460.0f)
		{
			view.setCenter(Vector2f(1460.0f, 206.0f));
			for (int j = 0; j < lista_players[0]->get_lista_coracoes().size(); j++)
			{
				lista_players[0]->get_lista_coracoes()[j]->set_posicao(Vector2f(1252.0f + k, 100.0f));
				k += 22;
			}

		}
		else
		{
			view.setCenter(Vector2f(lista_players[0]->get_posicao().x, 206.0f));
			for (int j = 0; j < lista_players[0]->get_lista_coracoes().size(); j++)
			{
				lista_players[0]->get_lista_coracoes()[j]->set_posicao(Vector2f(lista_players[0]->get_posicao().x - 208.7f + k, 100.0f));
				k += 22;
			}
		}
	}
	else
	{
		posicao = (lista_players[0]->get_posicao().x + lista_players[1]->get_posicao().x) / 2;
		if (posicao < -1072.0f)
		{
			view.setCenter(Vector2f(-1072.0f, 206.0f));
			lista_view[0]->set_posicao(Vector2f(-1072.0f + 206.0f, 206.0f));
			for (int j = 0; j < lista_players[0]->get_lista_coracoes().size(); j++)
			{
				lista_players[0]->get_lista_coracoes()[j]->set_posicao(Vector2f(-1280.0f + k, 100.0f));
				k += 22;
			}
		}
		else if (posicao > 1460.0f)
		{
			lista_view[0]->set_posicao(Vector2f(1460.0f + 206.0f, 206.0f));
			lista_view[1]->set_posicao(Vector2f(1460.0f - 206.0f, 206.0f));
			view.setCenter(Vector2f(1460.0f, 206.0f));
			for (int j = 0; j < lista_players[0]->get_lista_coracoes().size(); j++)
			{
				lista_players[0]->get_lista_coracoes()[j]->set_posicao(Vector2f(1252.0f + k, 100.0f));
				k += 22;
			}

		}
		else
		{
			lista_view[0]->set_posicao(Vector2f(posicao + 206.0f, 206.0f));
			lista_view[1]->set_posicao(Vector2f(posicao - 206.0f, 206.0f));
			view.setCenter(Vector2f(posicao, 206.0f));
			for (int j = 0; j < lista_players[0]->get_lista_coracoes().size(); j++)
			{
				lista_players[0]->get_lista_coracoes()[j]->set_posicao(Vector2f(lista_players[0]->get_posicao().x - 208.7f + k, 100.0f));
				k += 22;
			}
		}
	}
	
}

void Fase::esvaziaVectors()
{
	while(!lista_cenario.empty())
		lista_cenario.pop_back();
	while(!lista_inimigos.empty())
		lista_inimigos.pop_back();
	while(!lista_plataformas.empty())
		lista_plataformas.pop_back();
	while(!lista_obstaculos.empty())
		lista_obstaculos.pop_back();

}
