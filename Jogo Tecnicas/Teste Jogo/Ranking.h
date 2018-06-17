#include <string>	
#pragma once
using namespace std;
class Ranking
{
private:
	int pontos;
	string nome;

public:
	Ranking();
	virtual ~Ranking();
	bool podeSalvar(Ranking rank);
	void salvar(Ranking rank);

};

