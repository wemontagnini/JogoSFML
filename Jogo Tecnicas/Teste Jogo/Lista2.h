#pragma once

template <class T1>
class Lista2
{
private:
	template <class T2>
	class Elemento2
	{
	private:
		Elemento <T2> *proximo;
		T2 informacao;
	public:
		Elemento() { proximo = nullptr; info = nullptr; }
		virtual ~Elemento();

		void setProximo(Elemento<T2> *proximo_aux) { proximo = proximo_aux; }
		Elemento<T2> *get_proximo() { return proximo; }

		void set_infomacao(T2 info_aux) { informacao = info_aux; }
		T2 get_informacao() { return informacao; }
	};
	Elemento<T1> * primeiro;
	Elemento<T1> * ultimo;
	int tamanho;

public:
	Lista() { primeiro = nullptr; ultimo = nullptr; tamanho = 0; }
	virtual ~Lista();

	void set_primeiro(Elemento<T1> *primeiro_aux) { primeiro = primeiro_aux; }
	Elemento<T1> * get_primeiro() { return primeiro; }

	T1 get_infoPrimeiro() { return primeiro->get_informacao(); }
	
	void set_ultimo(Elemento<T1> * ultimo_aux) { ultimo = ultimo_aux; }
	Elemento<T1> get_ultimo() { return ultimo; }

	void set_tamanho(int t_aux) { tamanho = t_aux; }
	int get_tamanho() { return tamanho; }

	void incluir(T1 i)
	{
		Elemento <T1> * novo = new Elemento<T1>;
		novo.set_infomacao(i);
		if (get_primeiro() == nullptr)
		{
			set_primeiro(novo);
			get_primeiro().set_proximo(nullptr);
			set_ultimo(novo);
			tamanho++;
		}
		else
		{
			get_ultimo().get_proximo(novo);
			set_ultimo(novo);
			tamanho++;
		}
	}
	void excluir_inicio()
	{
		if (get_primeiro() != nullptr)
		{
			Elemento <T1> * aux = get_primeiro();
			set_primeiro(get_primeiro()->get_proximo());
			delete aux.get_informacao;
			delete aux;
			tam--;
		}
	}
};

