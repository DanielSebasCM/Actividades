#ifndef U_MATRIXGRAPH_H
#define U_MATRIXGRAPH_H

#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <iostream>

template <class T>
class UnweightedMatrixGraph
{
public:
    UnweightedMatrixGraph(int, bool dir = false);
    ~UnweightedMatrixGraph();

    void addEdge(T, T);
    void removeEdge(T, T);
    void addVertex(T);
    void removeVertex(T);
    bool isEdge(T, T) const;
    bool isVertex(T) const;

    int getIndexOf(T) const;

    std::vector<T> getVertexes() const;
    std::vector<T> getNeighbours(T) const;

    std::set<T> dfs(T) const;
    std::set<T> bfs(T) const;

    template <class U>
    friend std::ostream &operator<<(std::ostream &, UnweightedMatrixGraph<U> &);

private:
    int size;
    int capacity;
    bool directed;
    std::vector<T> vertexes;
    std::vector<std::vector<bool>> edges;
};
#endif