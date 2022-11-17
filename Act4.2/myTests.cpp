#define CATCH_CONFIG_MAIN
#include <iostream>
#include <fstream>
#include "activity.h"
using namespace std;
void auxiliar(string inputFile)
{
    char n, from, to;
    ifstream input;
    UListGraph<char> *graph;

    input.open(inputFile);
    input >> n;
    graph = new UListGraph<char>(true);

    while (1)
    {
        input >> from >> to;
        if (from == '0' && to == '0')
            break;

        graph->addEdge(from, to);
    }

    cout << inputFile << endl;
    cout << "DFS: " << endl;
    for (auto v : dfs('A', graph))
        cout << v << " ";
    cout << endl;
    cout << "BFS: " << endl;
    for (auto v : bfs('A', graph))
        cout << v << " ";
    cout << endl;
    cout << "Topological Sort: " << topologicalSort(graph) << endl;
    cout << "Is Bipartite: " << isBipartite(graph) << endl;
    cout << "Is Cyclic: " << isCyclic(graph) << endl;
    cout << "Is Tree: " << isTree(graph) << endl;
    delete graph;
}

int main()
{
    auxiliar("myInput.txt");
}