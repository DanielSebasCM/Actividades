#ifndef U_MATRIXGRAPH_H
#define U_MATRIXGRAPH_H

#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <iostream>
#include <fstream>
#include "UGraph.h"

template <class T>
class UMatrixGraph : public UGraph<T>
{
public:
    UMatrixGraph(int, bool dir = false);
    ~UMatrixGraph();

    void loadGraph(int, std::ifstream &);

    void addEdge(T, T);
    void removeEdge(T, T);
    void addVertex(T);
    void removeVertex(T);
    bool isEdge(T, T) const;
    bool isVertex(T) const;

    std::vector<T> getVertexes() const;
    std::vector<T> getNeighbours(T) const;

    std::set<T> dfs(T) const;
    std::set<T> bfs(T) const;

    template <class U>
    friend std::ostream &operator<<(std::ostream &, UMatrixGraph<U> &);

private:
    int size;
    int capacity;
    bool directed;
    std::vector<T> vertexes;
    std::vector<std::vector<bool>> edges;

    int getIndexOf(T) const;
};
#endif