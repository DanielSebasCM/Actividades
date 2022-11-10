#include "UListGraph.h"

template <class T>
/**
 * @brief Construct a new UListGraph<T>::UListGraph object
 *
 * @param dir Is the graph directed?
 */
UListGraph<T>::UListGraph(bool dir)
{
    directed = dir;
    size = 0;
}

/**
 * @brief Destroy the UListGraph<T>::UListGraph object
 *
 */
template <class T>
UListGraph<T>::~UListGraph()
{
    vertexes.clear();
    edges.clear();
}

/**
 * @brief Adds an edge between two Vertexes
 *
 * @param from Source Vertex
 * @param to Destination Vertex
 *
 * Complexity: O(log(size))
 */
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

/**
 * @brief Removes an edge between two Vertexes
 *
 * @param from Source Vertex
 * @param to Destination Vertex
 *
 * Complexity: O(log(size))
 */
template <class T>
void UListGraph<T>::removeEdge(T from, T to)
{
    if (!isVertex(from) || !isVertex(to))
        return;

    edges.at(from).erase(to);

    if (!directed)
        edges.at(to).erase(from);
}

/**
 * @brief Adds a Vertex to the graph
 *
 * @param v Vertex to be added
 *
 * Complexity: O(log(size))
 */
template <class T>
void UListGraph<T>::addVertex(T vertex)
{
    if (isVertex(vertex))
        return;

    vertexes.insert(vertex);
    edges.insert({vertex, std::set<T>()});
    size++;
}

/**
 * @brief Removes a Vertex from the graph
 *
 * @param v Vertex to be removed
 *
 * Complexity: O(log(size))
 */
template <class T>
void UListGraph<T>::removeVertex(T vertex)
{
    if (!isVertex(vertex))
        return;

    edges.erase(vertex);
    vertexes.erase(vertex);
    size--;
}

/**
 * @brief Checks if a Vertex is in the graph
 *
 * @param v Vertex to be checked
 * @return true If the Vertex is in the graph
 * @return false If the Vertex is not in the graph
 *
 * Complexity: O(log(size))
 */
template <class T>
bool UListGraph<T>::isEdge(T from, T to) const
{
    if (!isVertex(from) || !isVertex(to))
        return false;

    return edges.at(from).find(to) != edges.at(from).end();
}

/**
 * @brief Checks if a Vertex is in the graph
 *
 * @param v Vertex to be checked
 * @return true If the Vertex is in the graph
 * @return false If the Vertex is not in the graph
 *
 * Complexity: O(log(size))
 */
template <class T>
bool UListGraph<T>::isVertex(T vertex) const
{
    return vertexes.find(vertex) != vertexes.end();
}

/**
 * @brief Returns the Vertexes in the graph
 *
 * @return std::set<T> Vertexes in the graph
 *
 * Complexity: O(size)
 */
template <class T>
std::vector<T> UListGraph<T>::getVertexes() const
{
    return std::vector(vertexes.begin(), vertexes.end());
}

/**
 * @brief Returns the Vertexes adjacent to a Vertex
 *
 * @param v Vertex to be checked
 * @return std::set<T> Vertexes adjacent to v
 *
 * Complexity: O(Edges)
 */
template <class T>
std::vector<T> UListGraph<T>::getNeighbours(T vertex) const
{
    return std::vector<T>(edges.at(vertex).begin(), edges.at(vertex).end());
}

/**
 * @brief Overload for stream printing of graphs
 *
 * @return std::ostream&
 */
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