#include "U_MatrixGraph.cpp"

int main(int argc, char *argv[])
{
    UnweightedMatrixGraph<char> graph(5, true);
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