// =================================================================
//
// File: main.cpp
// Author:
// Date:
//
// =================================================================
#include <iostream>
#include <fstream>
#include <string>
#include <map>

int main(int argc, char *argv[])
{
	std::ifstream inputFile;
	std::ofstream outputFile;

	if (argc != 3)
		std::cout << "Forma de uso: " << argv[0]
				  << "input.txt ouput.txt" << std::endl;

	inputFile.open(argv[1]);
	if (inputFile.fail())
		std::cout << "No se puede abrir el archivo" << std::endl;

	outputFile.open(argv[2]);
	if (outputFile.fail())
		std::cout << "No se puede abrir el archivo de salida" << std::endl;

	int m, n;
	inputFile >> m >> n;

	std::map<std::string, int> dict;
	for (int i = 0; i < m; i++)
	{
		std::string word;
		int weight;
		inputFile >> word >> weight;
		dict[word] = weight;
	}

	for (int i = 0; i < n; i++)
	{
		std::string word;
		int weight = 0;
		while (inputFile >> word)
		{
			if (word == ".")
				break;
			weight += dict[word];
		}
		outputFile << weight << std::endl;
	}
}