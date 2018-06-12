#pragma once
template <class T2>
class Elemento
{
private:
	Elemento <T2> *proximo;
	T2 informacao;
public:
	Elemento() { proximo = nullptr;	infomacao = nullptr; }
	
	virtual ~Elemento();

	void setProximo(Elemento<T2> *proximo_aux) { proximo = proximo_aux; }
	Elemento<T2> *get_proximo() { return proximo; }

	void set_infomacao(T2 info_aux) { informacao = info_aux; }
	T2 get_informacao() { return informacao; }
};

