#ifndef ULISTGRAPH_H
#define ULISTGRAPH_H

#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <iostream>
#include <fstream>
#include "UGraph.h"

template <class T>
class UListGraph : public UGraph<T>
{
public:
    UListGraph(bool dir = false);
    ~UListGraph();

    void addEdge(T, T);
    void removeEdge(T, T);
    void addVertex(T);
    void removeVertex(T);
    bool isEdge(T, T) const;
    bool isVertex(T) const;

    std::vector<T> getVertexes() const;
    std::vector<T> getNeighbours(T) const;

    template <class U>
    friend std::ostream &operator<<(std::ostream &, UListGraph<U> &);

private:
    int size;
    bool directed;
    std::set<T> vertexes;
    std::map<T, std::set<T>> edges;
};
#endif