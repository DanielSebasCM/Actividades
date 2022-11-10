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
    void loadGraph(int, std::ifstream &);

    virtual void addEdge(T, T) = 0;
    virtual void removeEdge(T, T) = 0;
    virtual void addVertex(T) = 0;
    virtual void removeVertex(T) = 0;
    virtual bool isEdge(T, T) const = 0;
    virtual bool isVertex(T) const = 0;

    virtual std::vector<T> getVertexes() const = 0;
    virtual std::vector<T> getNeighbours(T) const = 0;

    std::set<T> dfs(T) const;
    std::set<T> bfs(T) const;

private:
    int size;
    bool directed;
};

/**
 * @brief Returns a set with all the vertexes in the graph and prints the
 *        vectors in depth first order from an starting vertex
 *
 * @param v Starting vertex name
 * @return std::set<T>
 *
 * Complexity: O(size^2)
 */
template <class T>
std::set<T> UGraph<T>::dfs(T v) const
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
            std::cout << current << " ";
            visited.insert(current);
            for (auto elem : getNeighbours(current))
                toSearch.push(elem);
        }
    }
    std::cout << std::endl;

    return visited;
}

/**
 * @brief Returns a set with all the vertexes in the graph and prints the
 *        vectors in breadth first order from an starting vertex
 *
 * @param v Starting vertex name
 * @return std::set<T>
 *
 * Complexity: O(size^2)
 */
template <class T>
std::set<T> UGraph<T>::bfs(T v) const
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
            std::cout << current << " ";
            visited.insert(current);
            for (auto elem : getNeighbours(current))
                toSearch.push(elem);
        }
    }
    std::cout << std::endl;

    return visited;
}

/**
 * @brief Loads a graph from a file
 *
 * @tparam T Type of the names of Vertexes
 * @param cap Max number of Vertexes
 * @param file File to load from
 */
template <class T>
void UGraph<T>::loadGraph(int n, std::ifstream &inputFile)
{
    size = n;
    int iFrom, iTo;

    inputFile >> iFrom >> iTo;

    while (iFrom && iTo)
    {
        inputFile >> iFrom >> iTo;
        addEdge(iFrom, iTo);
    }
}

#endif