
#ifndef MAXHEAP_H
#define MAXHEAP_H

#include <vector>
#include <climits>
#include <sstream>

typedef unsigned int uint;

template <class T>
class MaxHeap
{
private:
    std::vector<T> hvec;

    uint parent(uint child) const { return (child - 1) / 2; }
    uint left(uint parent) const { return (parent * 2) + 1; }
    uint right(uint parent) const { return (parent * 2) + 2; }

    void swap(uint, uint);

public:
    MaxHeap() {}

    uint size() const;
    bool empty() const;

    void heapify(uint);

    T top() const;
    void push(T);
    void pop();

    std::string toString() const;
};

template <class T>
void MaxHeap<T>::swap(uint i, uint j)
{
    T temp = hvec[i];
    hvec[i] = hvec[j];
    hvec[j] = temp;
}

template <class T>
uint MaxHeap<T>::size() const
{
    return hvec.size();
}

template <class T>
bool MaxHeap<T>::empty() const
{
    return hvec.empty();
}

template <class T>
void MaxHeap<T>::heapify(uint i)
{
    uint le = left(i);
    uint ri = right(i);
    uint smallest = i;

    if (le < hvec.size() && hvec[le] > hvec[i])
        smallest = le;

    if (ri < hvec.size() && hvec[ri] > hvec[smallest])
        smallest = ri;

    if (i != smallest)
    {
        swap(i, smallest);
        heapify(smallest);
    }
}

template <class T>
T MaxHeap<T>::top() const
{
    if (empty())
        return INT_MAX;

    else
        return hvec[0];
}

template <class T>
void MaxHeap<T>::push(T val)
{
    hvec.push_back(val);
    uint pos = hvec.size() - 1;
    while (pos > 0 && val > hvec[parent(pos)])
    {
        swap(pos, parent(pos));
        pos = parent(pos);
    }
}

template <class T>
void MaxHeap<T>::pop()
{
    if (empty())
        return;

    hvec[0] = hvec[hvec.size() - 1];
    hvec.pop_back();
    heapify(0);
}

template <class T>
std::string MaxHeap<T>::toString() const
{
    std::stringstream aux;
    for (auto element : hvec)
    {
        aux << element << " ";
    }
    return aux.str();
}

#endif