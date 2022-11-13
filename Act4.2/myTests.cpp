#define CATCH_CONFIG_MAIN
#include <iostream>
#include <fstream>
#include "activity.h"
using namespace std;
void run(string inputFile)
{
    int n, from, to;
    ifstream input;
    UListGraph<int> *graph;

    input.open(inputFile);
    input >> n;
    graph = new UListGraph<int>(n);

    while (1)
    {
        input >> from >> to;
        if (!from && !to)
        {
            break;
        }
        graph->addEdge(from, to);
    }

    cout << inputFile << endl;
    cout << "Topological Sort: " << topologicalSort(graph) << endl;
    cout << "Is Bipartite: " << isBipartite(graph) << endl;
    cout << "Is Cyclic: " << isCyclic(graph) << endl;
    cout << "Is Tree: " << isTree(graph) << endl;
    delete graph;
}

int main()
{
    run("input1.txt");
    run("input2.txt");
    run("input3.txt");
    run("input4.txt");
    return 0;
}