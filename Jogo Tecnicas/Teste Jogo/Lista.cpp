#include "Lista.h"

template<class T1>
void Lista<T1>::incluir(T1 i)
{
	Elemento <T1*> * novo = new Elemento<T1>;
	novo->set_infomacao(i);
	if (get_primeiro() == nullptr)
	{
		set_primeiro(novo);
		get_primeiro()->set_proximo(nullptr);
		set_ultimo(novo);
		tamanho++;
	}
	else
	{
		get_ultimo()->get_proximo(novo);
		set_ultimo(novo);
		tamanho++;
	}
}

template<class T1>
void Lista<T1>::excluir_inicio()
{
	if (get_primeiro() != nullptr)
	{
		Elemento <T1> * aux = get_primeiro();
		set_primeiro(get_primeiro()->get_proximo());
		delete aux->get_informacao;
		delete aux;
		tamanho--;
	}
}
