#include "UListGraph.h"

template <class T>

UListGraph<T>::UListGraph(bool dir)
{
    directed = dir;
    size = 0;
}

template <class T>
UListGraph<T>::~UListGraph()
{
    vertexes.clear();
    edges.clear();
}

template <class T>
void UListGraph<T>::addEdge(T from, T to)
{
    if (!isVertex(from))
        addVertex(from);

    if (!isVertex(to))
        addVertex(to);

    edges.at(from).insert(to);

    if (!directed)
        edges.at(to).insert(from);
}

template <class T>
void UListGraph<T>::removeEdge(T from, T to)
{
    if (!isVertex(from) || !isVertex(to))
        return;

    edges.at(from).erase(to);

    if (!directed)
        edges.at(to).erase(from);
}

template <class T>
void UListGraph<T>::addVertex(T vertex)
{
    if (isVertex(vertex))
        return;

    vertexes.insert(vertex);
    edges.insert({vertex, std::set<T>()});
    size++;
}

template <class T>
void UListGraph<T>::removeVertex(T vertex)
{
    if (!isVertex(vertex))
        return;

    edges.erase(vertex);
    vertexes.erase(vertex);
    size--;
}

template <class T>
bool UListGraph<T>::isEdge(T from, T to) const
{
    if (!isVertex(from) || !isVertex(to))
        return false;

    return edges.at(from).find(to) != edges.at(from).end();
}

template <class T>
bool UListGraph<T>::isVertex(T vertex) const
{
    return vertexes.find(vertex) != vertexes.end();
}

template <class T>
std::vector<T> UListGraph<T>::getVertexes() const
{
    return std::vector(vertexes.begin(), vertexes.end());
}

template <class T>
std::vector<T> UListGraph<T>::getNeighbours(T vertex) const
{
    if (!isVertex(vertex))
        throw std::invalid_argument("Vertex does not exist");

    return std::vector<T>(edges.at(vertex).begin(), edges.at(vertex).end());
}

template <class T>
std::ostream &operator<<(std::ostream &out, UListGraph<T> &graph)
{
    for (auto vertex : graph.vertexes)
    {
        out << vertex << " -> ";

        for (auto neighbour : graph.edges.at(vertex))
            out << neighbour << " ";

        out << std::endl;
    }

    return out;
}