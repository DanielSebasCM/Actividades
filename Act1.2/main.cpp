// =================================================================
//
// File: main.cpp
// Author: Daniel Cajas - A01708637
// Date:30/08/2022
//
// =================================================================
#include <iostream>
#include <string>

#include <fstream>

#include <vector>
#include "header.h"
#include "search.h"
#include "bubble.h"
#include "selection.h"
#include "insertion.h"

using namespace std;

int main(int argc, char* argv []) {

    ifstream inputFile;
    ofstream outputFile;

    if (argc != 3)
    {
        cout << "Uso: " << argv[0] << " Input.txt Output.txt";
        return -1;
    }

    inputFile.open(argv[1]);
    if (inputFile.fail())
    {
        cout << "No se pudo abrir el archivo de entrada.";
        return -1;
    }

    outputFile.open(argv[2]);
    if (outputFile.fail())
    {
        cout << "No se pudo abrir el archivo de salida.";
        return -1;
    }

/* 	inputFile.open("input1.txt");
	outputFile.open("output1.txt"); */
	int N, N2, num;
    inputFile >> N;

	// Vector donde se almacenaran los numeros
    vector<int> nums(N);

	// Lectura de los numeros
    for (int i = 0; i < N; i++) {
		inputFile >> num;
        nums[i] = num;
    }

	// Diferentes algoritmos de ordenamientos
	int bubble_comp, selection_comp, insertion_comp;

	vector<int> disordered = nums;
	bubble_comp = bubbleSort(nums);
	nums = disordered;
	selection_comp = selectionSort(nums);
	nums = disordered;
	insertion_comp = insertionSort(nums);

	outputFile << bubble_comp << ' ' 
			   << selection_comp << ' ' 
			   << insertion_comp << '\n' << '\n';


	inputFile >> N2;
	std::pair<int, int> result;
 	for (int i = 0; i < N2; i++) {
		inputFile >> num;
		result = sequentialSearch(nums, num);
		outputFile << result.first << ' '
				   << result.second << ' ';
		result = binarySearch(nums, num);
		outputFile << result.second << '\n';
    } 

	inputFile.close();
	outputFile.close();
}