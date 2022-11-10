#include "UMatrixGraph.cpp"
#include "UListGraph.cpp"

int main(int argc, char *argv[])
{
    UListGraph<char> graph(true);
    graph.addVertex('A');
    graph.addVertex('B');
    graph.addVertex('C');
    graph.addVertex('D');
    graph.addVertex('E');
    graph.addEdge('A', 'B');
    graph.addEdge('A', 'C');
    graph.addEdge('B', 'C');
    graph.addEdge('B', 'D');
    graph.addEdge('C', 'D');
    graph.addEdge('C', 'E');
    graph.addEdge('D', 'E');
    graph.dfs('B');
    std::cout << std::endl;
    graph.bfs('B');
    std::cout << std::endl;
    std::cout << graph;
    return 0;
}