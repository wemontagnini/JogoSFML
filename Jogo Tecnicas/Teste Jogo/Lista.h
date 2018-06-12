#include "Elemento.h"
#pragma once


template <class T1>
class Lista
{
private:
	Elemento <T1*> *primeiro;
	Elemento <T1*> *ultimo;
	int tamanho;
public:

	Lista();
	virtual ~Lista(){ primeiro = nullptr; ultimo = nullptr;	tamanho = 0;	}

	void set_primeiro(Elemento<T1*> *primeiro_aux) { primeiro = primeiro_aux; }
	Elemento<T1*> * get_primeiro() { return primeiro; }

	T1 get_infoPrimeiro() { return primeiro->get_informacao(); }

	void set_ultimo(Elemento<T1*> * ultimo_aux) { ultimo = ultimo_aux; }
	Elemento<T1*> get_ultimo() { return ultimo; }

	void set_tamanho(int t_aux) { tamanho = t_aux; }
	int get_tamanho() { return tamanho; }

	void incluir(T1 i);
	void excluir_inicio();
};

