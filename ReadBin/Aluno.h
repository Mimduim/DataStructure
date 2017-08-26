#ifndef ALUNO_H_
#define ALUNO_H_

#include <iostream>
using namespace std;
class Aluno {
public:
	int matricula;
	char nome[60];
	int idade;
	char sexo;
public:

	void print();
	void NovoAluno();
}
;

void Aluno::NovoAluno() {

	cout<<" Declare os atributos do aluno a ser adicionado:\n";

	cout << "\nDigite Matricula : " << endl;
	cin >> matricula;

	cout << "\nDigite Nome : " << endl;
	cin.ignore();
	gets(nome);

	cout << "\nDigite a Idade : " << endl;
	//cin.ignore();
	cin >> idade;

	cout << "\nDigite o Sexo : " << endl;
	cin.ignore();
	cin >> sexo;
	cin.ignore();
}


void Aluno::print() {
	cout << "Matricula: " << matricula << endl;
	cout << "Nome: " << nome << endl;
	cout << "Idade: " << idade << endl;
	cout << "Sexo: " << sexo << endl;

}

#endif /* ALUNO_H_ */
