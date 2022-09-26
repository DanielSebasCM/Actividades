// =================================================================
//
// File: main.cpp
// Author:
// Date:
//
// =================================================================
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "barco.h"
#include <algorithm>
using namespace std;

int main(int argc, char* argv[]) {
	ifstream inputFile;
    ofstream outputFile;

    if (argc != 3){
        cout << "Uso: " << argv[0] << " Input.txt Output.txt";
        return -1;
    }

    inputFile.open(argv[1]);
    if (inputFile.fail()) {
        cout << "No se pudo abrir el archivo de entrada.";
        return -1;
    }

    outputFile.open(argv[2]);
    if (outputFile.fail()){
        cout << "No se pudo abrir el archivo de salida.";
        return -1;
    } 

	int N;
	std::string find, date, time, UBI;
	char entrada;

	inputFile >> N >> find;

	vector<Barco> Barcos(N);

	for(int i = 0; i < N; i++){
		inputFile >> date >> time >> entrada >> UBI;
		Barcos[i] = Barco(date, time, entrada, UBI);
	}

	std::sort(Barcos.begin(), Barcos.end());

	for (int i = 0; i < N; i++)
		if(Barcos[i].get_UBI().substr(0, 3) == find)
			outputFile << Barcos[i] << '\n';
	return 0;
}

