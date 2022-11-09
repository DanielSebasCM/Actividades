#ifndef UGRAPH_H
#define UGRAPH_H

#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <iostream>

template <class T>
class UGraph
{
public:
    virtual void addEdge(T, T) = 0;
    virtual void removeEdge(T, T) = 0;
    virtual void addVertex(T) = 0;
    virtual void removeVertex(T) = 0;
    virtual bool isEdge(T, T) const = 0;
    virtual bool isVertex(T) const = 0;

    std::vector<T> getVertexes() const = 0;
    std::vector<T> getNeighbours(T) const = 0;

    std::set<T> dfs(T) const;
    std::set<T> bfs(T) const;

private:
    int size;
    int capacity;
    bool directed;
    std::vector<T> vertexes;
    std::vector<std::vector<bool>> edges;
};

#endif