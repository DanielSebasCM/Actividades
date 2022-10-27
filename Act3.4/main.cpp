// =================================================================
//
// File: main.cpp
// Author:
// Date:
//
// =================================================================
#include <iostream>
#include <fstream>
#include "MinHeap.h"
int main(int argc, char *argv[])
{
	std::ifstream inputFile;
	std::ofstream outputFile;

	if (argc != 3)
	{
		std::cout << "Uso: " << argv[0] << " Input.txt Output.txt";
		return -1;
	}

	inputFile.open(argv[1]);
	if (inputFile.fail())
	{
		std::cout << "No se pudo abrir el archivo de entrada.";
		return -1;
	}

	outputFile.open(argv[2]);
	if (outputFile.fail())
	{
		std::cout << "No se pudo abrir el archivo de salida.";
		return -1;
	}

	int N, elem;
	inputFile >> N;

	MinHeap<int> heap;
	for (int i = 0; i < N; i++)
	{
		inputFile >> elem;
		heap.push(elem);
	}

	int acum = 0;
	int temp;
	while (heap.size() > 1)
	{
		temp = heap.pop() + heap.pop() - 1;
		heap.push(temp);
		acum += temp;
	}
	outputFile << acum << std::endl;
}
