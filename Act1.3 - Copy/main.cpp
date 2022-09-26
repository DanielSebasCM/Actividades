// =================================================================
//
// File: main.cpp
// Author:
// Date:
//
// =================================================================

#include <iomanip>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "barco.h"
#include "sort.h"

int main(int argc, char* argv[]) {
	std::ifstream inputFile;
    std::ofstream outputFile;


    // Checks that the program is run properly and files could be open
    if (argc != 3){
        std::cout << "Uso: " << argv[0] << " Input.txt Output.txt";
        return -1;
    }

    inputFile.open(argv[1]);
    if (inputFile.fail()) {
        std::cout << "No se pudo abrir el archivo de entrada.";
        return -1;
    }

    outputFile.open(argv[2]);
    if (outputFile.fail()){
        std::cout << "No se pudo abrir el archivo de salida.";
        return -1;
    } 

	int N, minuto, hora, dia, mes, anio;
	std::string find, date, time, UBI;
	char entrada;

	inputFile >> N >> find;

	std::vector<Barco> Barcos(N);

	for(int i = 0; i < N; i++){
		inputFile >> date >> time >> entrada >> UBI;

       	dia = (date[0]-'0')*10 + (date[1]-'0');
        mes = (date[3]-'0')*10 + (date[4]-'0');
        anio = (date[6]-'0')*10 + (date[7]-'0');

        hora = (time[0]-'0')*10 + time[1]-'0';
        minuto = (time[3]-'0')*10 + time[4]-'0';
		
        Barcos[i] = Barco(dia, mes, anio, hora, minuto, entrada, UBI);
	}

	selectionSort(Barcos);

	for (int i = 0; i < N; i++){
        std::string ubi = Barcos[i].UBI;
        std ::string primeros_tres = ubi.substr(0, 3);
		if(primeros_tres == find){
			outputFile << std::setfill('0');
            outputFile << std::setw(2) << Barcos[i].dia << "-";
            outputFile << std::setw(2) << Barcos[i].mes << "-";
            outputFile << std::setw(2) << Barcos[i].anio << " ";
            outputFile << std::setw(2) << Barcos[i].hora << ":";
            outputFile << std::setw(2) << Barcos[i].minuto << " ";
            outputFile << Barcos[i].entrada << " " << Barcos[i].UBI << '\n';
        }
    }
	return 0;
}

