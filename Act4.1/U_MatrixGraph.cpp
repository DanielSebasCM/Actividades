#include "U_MatrixGraph.h"

template <class T>
UnweightedMatrixGraph<T>::UnweightedMatrixGraph(int cap, bool dir)
{
    capacity = cap;
    size = 0;
    directed = dir;
    vertexes.resize(capacity);
    edges.resize(capacity);
    for (int i = 0; i < capacity; i++)
    {
        edges[i].resize(capacity, false);
    }
}

template <class T>
UnweightedMatrixGraph<T>::~UnweightedMatrixGraph()
{
    vertexes.clear();
    edges.clear();
}

template <class T>
void UnweightedMatrixGraph<T>::addEdge(T v1, T v2)
{
    if (!isVertex(v1) || !isVertex(v2))
        throw std::invalid_argument("Vertex not found");

    int i1 = getIndexOf(v1);
    int i2 = getIndexOf(v2);
    edges[i1][i2] = true;

    if (!directed)
        edges[i2][i1] = true;
}

template <class T>
void UnweightedMatrixGraph<T>::removeEdge(T v1, T v2)
{
    if (!isVertex(v1) || !isVertex(v2))
        throw std::invalid_argument("Vertex not found");

    int i1 = getIndexOf(v1);
    int i2 = getIndexOf(v2);
    edges[i1][i2] = false;

    if (!directed)
        edges[i2][i1] = false;
}

template <class T>
void UnweightedMatrixGraph<T>::addVertex(T v)
{
    if (size < capacity)
    {
        vertexes[size++] = v;
    }
    else
    {
        throw std::invalid_argument("Graph is full");
    }
}

template <class T>
void UnweightedMatrixGraph<T>::removeVertex(T v)
{
    if (!isVertex(v))
        throw std::invalid_argument("Vertex not found");

    int index = getIndexOf(v);
    for (int i = index; i < size - 1; i++)
        vertexes[i] = vertexes[i + 1];

    size--;

    for (int i = index; i < size; i++)
        for (int j = 0; j < size; j++)
            edges[i][j] = edges[i + 1][j];

    for (int i = index; i < size; i++)
        for (int j = 0; j < size; j++)
            edges[j][i] = edges[j][i + 1];
}

template <class T>
bool UnweightedMatrixGraph<T>::isEdge(T v1, T v2) const
{
    if (!isVertex(v1) || !isVertex(v2))
        throw std::invalid_argument("Vertex not found");

    int i1 = getIndexOf(v1);
    int i2 = getIndexOf(v2);
    return edges[i1][i2];
}

template <class T>
bool UnweightedMatrixGraph<T>::isVertex(T v) const
{
    for (int i = 0; i < size; i++)
    {
        if (vertexes[i] == v)
            return true;
    }
    return false;
}

template <class T>
int UnweightedMatrixGraph<T>::getIndexOf(T v) const
{
    for (int i = 0; i < size; i++)
    {
        if (vertexes[i] == v)
            return i;
    }
    return -1;
}

template <class T>
std::vector<T> UnweightedMatrixGraph<T>::getVertexes() const
{
    return vertexes;
}

template <class T>
std::vector<T> UnweightedMatrixGraph<T>::getNeighbours(T v) const
{
    if (!isVertex(v))
        throw std::invalid_argument("Vertex not found");

    std::vector<T> neighbours;
    int index = getIndexOf(v);
    for (int i = 0; i < size; i++)
    {
        if (edges[index][i])
            neighbours.push_back(vertexes[i]);
    }
    return neighbours;
}

template <class T>
std::set<T> UnweightedMatrixGraph<T>::dfs(T v) const
{
    if (!isVertex(v))
        throw std::invalid_argument("Vertex not found");

    std::set<T> visited;
    std::stack<T> toSearch;
    toSearch.push(v);

    T current;
    while (!toSearch.empty())
    {
        current = toSearch.top();
        toSearch.pop();
        if (visited.find(current) == visited.end())
        {
            std::cout << vertexes[getIndexOf(current)] << " ";
            visited.insert(current);
            for (auto elem : getNeighbours(current))
                toSearch.push(elem);
        }
    }
    std::cout << std::endl;

    return visited;
}

template <class T>
std::set<T> UnweightedMatrixGraph<T>::bfs(T v) const
{
    if (!isVertex(v))
        throw std::invalid_argument("Vertex not found");

    std::set<T> visited;
    std::queue<T> toSearch;
    toSearch.push(v);

    T current;
    while (!toSearch.empty())
    {
        current = toSearch.front();
        toSearch.pop();
        if (visited.find(current) == visited.end())
        {
            std::cout << vertexes[getIndexOf(current)] << " ";
            visited.insert(current);
            for (auto elem : getNeighbours(current))
                toSearch.push(elem);
        }
    }
    std::cout << std::endl;

    return visited;
}

template <class T>
std::ostream &operator<<(std::ostream &os, UnweightedMatrixGraph<T> &graph)
{
    for (int i = 0; i < graph.size; i++)
    {
        os << graph.vertexes[i] << ": ";
        for (int j = 0; j < graph.size; j++)
        {
            if (graph.edges[i][j])
                os << graph.vertexes[j] << " ";
        }
        os << std::endl;
    }
    return os;
}
