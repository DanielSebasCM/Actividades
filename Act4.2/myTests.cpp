#define CATCH_CONFIG_MAIN
#include <iostream>
#include <fstream>
#include "activity.h"

using namespace std;
int main()
{
    int n, from, to;
    ifstream input;
    UListGraph<int> *graph;

    input.open("myInput.txt");
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

    cout << "Graph" << endl
         << graph->toString() << endl;
    cout << "Topological Sort: " << topologicalSort(graph) << endl;
    cout << "Is Bipartite: " << isBipartite(graph) << endl;
    cout << "Is Cyclic: " << isCyclic(graph) << endl;
    cout << "Is Tree: " << isTree(graph) << endl;
    delete graph;
}