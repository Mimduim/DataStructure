/*
 * Nome: Paulo Henrique Rodrigues
 * RA: 0022012
 * Trabalho Prático II
 * incompleto ^^
 */
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include <conio.h>
#include "Aluno.h"
using namespace std;

//Metodo que grava objetos
void Grava() {

	Aluno obj;
	int op = 0;
	ofstream ObjectWriter("Dado.dat",ios_base::out | ios_base::app | ios_base::binary);

	if (ObjectWriter.good()) {

		do {
			obj.NovoAluno(); // lê do teclado
			ObjectWriter.write((char *) &obj, sizeof(Aluno));
			cout << "\nInserir outro aluno 1.Sim / 2.Nao ";
			cin >> op;
		} while (op != 2);   // fim se 'n'

		ObjectWriter.close();
	} else {
		cout << "Falha ao gravar no  arquivo!" << endl;
	}
}



void Programa() {

	fstream ObjectReader("Dado.dat",ios_base::in | ios_base::out | ios_base::binary);
	Aluno obj;
	int aux = 0, aux1 = 0, op = 0;


	if (ObjectReader.good()) {

		// Menu inicial
		cout << "\n1.Listar registros \t2.Adicionar registros \t3.Pesquisar registros"<< endl;
		cin >> aux1;
		if (aux1 == 1) {
			cout << "\nListando registros... \n"<< endl;
			ObjectReader.seekg(0, ios::end);
			long ind = (ObjectReader.tellg()) / sizeof(Aluno);

			// Laço para imprimir todos os objeto do arquivo
			for (int i = 1; i <= ind; i++) {
				int post = (i - 1) * sizeof(Aluno);
				ObjectReader.seekg(post);
				ObjectReader.read((char *) &obj, sizeof(Aluno));
				obj.print();
				cout << "\n";
			}
		}
		//Gravando novo objeto no arquivo
		else if (aux1 == 2)
				Grava();

		else
			cout << "\nPesquisando registros... "<< endl;

		//Inicia a leitura a partir do inicio do arquivo e conta todos os objetos ate o fim do arquivo
		ObjectReader.seekg(0, ios::end);
		//Variavel long recebe a quantidade de objetos dentro do arquivo
		long nrec = (ObjectReader.tellg()) / sizeof(Aluno);
		// Exibe a quantidade de objetos na tela
		cout << "\nNumero de registros : " << nrec;
		cout << "\n\nInsira o numero do registro  para exibir aluno:"<< endl;
		cin >> nrec;
		int posicao = (nrec - 1) * sizeof(Aluno);
		ObjectReader.seekg(posicao);
		ObjectReader.read((char *) &obj, sizeof(Aluno));
		obj.print();

		// Metodos para modificação de atributos do objeto Aluno
		cout<< "\n1.Modificar matricula \n2.Modificar nome \n3.Modificar idade \n4.Modificar sexo \n5.Sair"<< endl;
		cin >> aux;

		if (aux == 1) {
			// Modifica matrícula
			cout << "\nDeclare a nova matricula: \n" << endl;
			cin >> obj.matricula;
			ObjectReader.seekp(posicao);
			ObjectReader.write((char *) &obj, sizeof(Aluno));
			cout << "\nModificado.. " << endl;
			obj.print();

		}

		 else if (aux == 2){
		 //Modifica nome
		 cout << "\nDeclare o novo nome: " << endl;
		 cin.ignore();
		 gets(obj.nome);
		 ObjectReader.seekp(posicao);
		 ObjectReader.write((char *) &obj, sizeof(Aluno));
		 cout << "\nModificado.. " << endl;
		 obj.print();
		 //break;
		 }

		else if (aux == 3) {
			//Modifica idade
			cout << "\nDeclare a nova idade: " << endl;
			cin >> obj.idade;
			ObjectReader.seekp(posicao);
			ObjectReader.write((char *) &obj, sizeof(Aluno));
			cout << "\nModificado.. " << endl;
			obj.print();
			//break;
		}

		else if (aux == 4) {
			//Modifica sexo
			cout << "\nDeclare o novo sexo: " << endl;
			cin.ignore();
			cin >> obj.sexo;
			ObjectReader.seekp(posicao);
			ObjectReader.write((char *) &obj, sizeof(Aluno));
			cout << "\nModificado.. " << endl;
			obj.print();
			//break;
		}

		else if (aux == 5) {
			exit(1);
		}

		ObjectReader.close();
	} else
		cout << "Falha ao abrir arquivo!" << endl;

	cout << "\nDeseja retornar ao menu inicial? 1.Sim / 2.Nao" << endl;
	cin >> op;
	if (op == 1)
		Programa();
	else
		exit(1);

}

int main() {

	Programa();

	return 0;
}

