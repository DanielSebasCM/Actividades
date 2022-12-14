#include "UMatrixGraph.h"

/**
 * @brief Construct a new UMatrixGraph<T>::UMatrixGraph object
 *
 * @tparam T Type of the names of Vertexes
 * @param cap Max number of Vertexes
 * @param dir Is the graph directed
 * Complexity: O(cap^2)
 */

template <class T>
UMatrixGraph<T>::UMatrixGraph(int cap, bool dir)
{
    capacity = cap;
    size = 0;
    directed = dir;

    vertexes.resize(capacity);
    edges.resize(capacity);

    for (int i = 0; i < capacity; i++)
        edges[i].resize(capacity, false);
}

/**
 * @brief Destroy the UMatrixGraph<T>::UMatrixGraph object
 *
 * Complexity: O(cap^2)
 */
template <class T>
UMatrixGraph<T>::~UMatrixGraph()
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
 * Complexity: O(1)
 */

template <class T>
void UMatrixGraph<T>::addEdge(T from, T to)
{
    if (!isVertex(from))
        addVertex(from);

    if (!isVertex(to))
        addVertex(to);

    int i1 = getIndexOf(from);
    int i2 = getIndexOf(to);
    edges[i1][i2] = true;

    if (!directed)
        edges[i2][i1] = true;
}

/**
 * @brief Removes an edge between two Vertexes
 *
 * @param from Source Vertex
 * @param to Destination Vertex
 *
 * Complexity: O(1)
 */
template <class T>
void UMatrixGraph<T>::removeEdge(T from, T to)
{
    if (!isVertex(from) || !isVertex(to))
        return;

    int i1 = getIndexOf(from);
    int i2 = getIndexOf(to);
    edges[i1][i2] = false;

    if (!directed)
        edges[i2][i1] = false;
}

/**
 * @brief Adds a Vertex to the graph
 *
 * @param v Name of the Vertex
 *
 * Complexity: O(1)
 */
template <class T>
void UMatrixGraph<T>::addVertex(T v)
{
    if (isVertex)
        return;

    if (size < capacity)
    {
        vertexes[size++] = v;
    }
    else
    {
        throw std::invalid_argument("Graph is full");
    }
}

/**
 * @brief Removes a Vertex from the graph
 *
 * @param v Name of the Vertex
 *
 * Complexity: O(size^2)
 */
template <class T>
void UMatrixGraph<T>::removeVertex(T v)
{
    if (!isVertex(v))
        return;

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

/**
 * @brief Checks if there is an edge between two Vertexes
 *
 * @param from Source Vertex
 * @param to Destination Vertex
 * @return true If there is an edge
 * @return false If there is no edge
 *
 * Complexity: O(1)
 */
template <class T>
bool UMatrixGraph<T>::isEdge(T from, T to) const
{
    if (!isVertex(from) || !isVertex(to))
        return false;

    int iFrom = getIndexOf(from);
    int iTo = getIndexOf(to);
    return edges[iFrom][iTo];
}

/**
 * @brief Checks if a Vertex exists in the graph
 *
 * @param v Name of the Vertex
 * @return true If the Vertex exists
 * @return false If the Vertex does not exist
 *
 * Complexity: O(size)
 */
template <class T>
bool UMatrixGraph<T>::isVertex(T v) const
{
    return vertexes.find(v) != vertexes.end();
}

/**
 * @brief Gets the index of the vector representig the Vertex in the graph
 *
 * @param v Vertex name
 * @return int index
 *
 * Complexity: O(size)
 */
template <class T>
int UMatrixGraph<T>::getIndexOf(T v) const
{
    for (int i = 0; i < size; i++)
    {
        if (vertexes[i] == v)
            return i;
    }
    return -1;
}

/**
 * @brief Returns a vector with all the Vertexes in the graph
 *
 * @return std::vector<T> Vector with all the Vertexes
 *
 * Complexity: O(1)
 */
template <class T>
std::vector<T> UMatrixGraph<T>::getVertexes() const
{
    return std::vector<T>(vertexes.begin(), vertexes.end());
    ;
}

/**
 * @brief Returns a vector with all the Vertexes adjacent to a given Vertex
 *
 * @param v Vertex name
 * @return std::vector<T> Vector with all the adjacent Vertexes
 *
 * Complexity: O(size*Edges)
 */
template <class T>
std::vector<T> UMatrixGraph<T>::getNeighbours(T v) const
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

/**
 * @brief Overload for stream printing of graphs
 *
 * @return std::ostream&
 */
template <class T>
std::ostream &operator<<(std::ostream &os, UMatrixGraph<T> &graph)
{
    os << "   ";
    for (auto v : graph.vertexes)
        os << v << " ";

    os << '\n';

    for (int i = 0; i < graph.size; i++)
    {
        os << graph.vertexes[i] << ": ";
        for (int j = 0; j < graph.size; j++)
        {
            os << graph.edges[i][j] << " ";
        }
        os << std::endl;
    }
    return os;
}
