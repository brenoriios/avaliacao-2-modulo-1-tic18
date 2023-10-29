#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Data {
	int dia, mes, ano;
	public:
	
	/*
	O m�todo abaixo retornar� -1 se d1 � anterior a d2
	Retornar� 0 se d1 = d2
	Retornar� +1 se d1 � posterior a d2
	*/	
	static int compara(Data d1, Data d2) { 
		return 0;
	}
	
	Data (int _dia, int _mes, int _ano) {
		dia = _dia;
		mes = _mes;
		ano = _ano;
	}
	string toString() {
		string ret = "";
		ret.append(to_string(dia));
		ret.append("/");
		ret.append(to_string(mes));
		ret.append("/");
		ret.append(to_string(ano));
		return ret;
	}
};

class Lista {
	public:
	virtual void entradaDeDados() =0;
	virtual void mostraMediana() =0;
	virtual void mostraMenor() =0;
	virtual void mostraMaior() =0;
	virtual void listarEmOrdem() =0;
	virtual void listaNElementos(int n) =0;
};

class ListaNomes : public Lista {
	vector<string> lista;
	
	public:
	
	/*
	O método abaixo pergunta ao usuário quantos
	elementos vão existir na lista e depois
	solicita a digitação de cada um deles
	*/	
	void entradaDeDados() {
		string _nome;
		int _qtdElementos;
		cout << "Quantos elementos vão existir na lista?" << endl;
		cin >> _qtdElementos;

		for(int i = 0; i < _qtdElementos; i++){
			cout << "Digite o nome " << (i + 1) << endl;
			getline(cin >> ws, _nome);
			lista.push_back(_nome);
		}
		cout << "-----------------" << endl;
	}
		
	void mostraMediana() {
		vector<string> _auxLista = this->lista;
		float meio;

		sort(_auxLista.begin(), _auxLista.end());

		meio = floor(((_auxLista.size() + 1) / 2.0) - 1);

		cout << "Aqui vai mostrar a mediana da lista de strings" << endl;
		cout << _auxLista.at(meio) << endl;
		cout << "-----------------" << endl;
	}
	
	void mostraMenor() {
		vector<string> _auxLista = this->lista;

		sort(_auxLista.begin(), _auxLista.end());
		
		cout << "Aqui vai mostrar o primeiro nome alfabeticamente" << endl;
		cout << _auxLista.front() << endl;
		cout << "-----------------" << endl;
	}

	void mostraMaior() {
		vector<string> _auxLista = this->lista;

		sort(_auxLista.begin(), _auxLista.end());

		cout << "Aqui vai mostrar o ultimo nome alfabeticamente" << endl;
		cout << _auxLista.back() << endl;
		cout << "-----------------" << endl;
	}

	void listarEmOrdem(){
		vector<string> _auxLista = this->lista;

		sort(_auxLista.begin(), _auxLista.end());

		cout << "Aqui vai mostrar todos os nomes da lista ordenados alfabeticamente" << endl;
		for(auto nome: _auxLista){
			cout << nome << endl;
		}
		cout << "-----------------" << endl;
	}

	void listaNElementos(int n){
		cout << "Aqui vai mostrar os " << n << " primeiros nomes da lista" << endl;
		for(int i = 0; i < n; i++){
			cout << (i + 1) << ". " << this->lista.at(i) << endl;
		}
		cout << "-----------------" << endl;
	}
};

class ListaDatas  {
	vector<Data> lista;
	
	public:
		
	/*
	O m�todo abaixo pergunta ao usu�rios quantos
	elementos v�o existir na lista e depois
	solicita a digita��o de cada um deles
	*/	
	void entradaDeDados() {
		
	}
	
	void mostraMediana() {
		cout << "Aqui vai mostrar a mediana da lista de datas" << endl;
	}
	
	void mostraMenor() {
		cout << "Aqui vai mostrar a primeira data cronologicamente" << endl;
	}
	void mostraMaior() {
		cout << "aqui vai mostrar a ultima data cronologicamente" << endl;
	}
};

class ListaSalarios  {
	vector<float> lista;
	
	public:
	
	/*
	O m�todo abaixo pergunta ao usu�rios quantos
	elementos v�o existir na lista e depois
	solicita a digita��o de cada um deles
	*/	
	void entradaDeDados() {
		
	}
			
	void mostraMediana() {
		cout << "Aqui vai mostrar a mediana da lista de salarios" << endl;
	}
	
	void mostraMenor() {
		cout << "Aqui vai mostrar o menor dos salarios" << endl;
	}
	void mostraMaior() {
		cout << "aqui vai mostrar o maior dos salarios" << endl;
	}
};


class ListaIdades  {
	vector<int> lista;
	
	public:
		
		/*
	O m�todo abaixo pergunta ao usu�rios quantos
	elementos v�o existir na lista e depois
	solicita a digita��o de cada um deles
	*/	
	void entradaDeDados() {
		
	}
	
	void mostraMediana() {
		cout << "Aqui vai mostrar a mediana da lista de idades" << endl;
	}
	
	void mostraMenor() {
		cout << "Aqui vai mostrar a menor das idades" << endl;
	}
	void mostraMaior() {
		cout << "aqui vai mostrar a maior das idades" << endl;
	}
};
 
int main () {
	vector<Lista*> listaDeListas;
	
	ListaNomes listaNomes;
	listaNomes.entradaDeDados();
	listaDeListas.push_back(&listaNomes);
	
	ListaDatas listaDatas;
	listaDatas.entradaDeDados();
	listaDeListas.push_back(&listaDatas);
	
	ListaSalarios listaSalarios;
	listaSalarios.entradaDeDados();
	listaDeListas.push_back(&listaSalarios);
	
	ListaIdades listaIdades;
	listaIdades.entradaDeDados();
	listaDeListas.push_back(&listaIdades);
	
	for (Lista* l : listaDeListas) {
		int _n;

		l->mostraMediana();
		l->mostraMenor();
		l->mostraMaior();
		l->listarEmOrdem();

		cout << "Quantos elementos você quer mostrar?" << endl;
		cin >> _n;
		l->listaNElementos(_n);
	}
	
}
    

