#ifndef SORT_H
#define SORT_H

#include <vector>
#include "barco.h"

template <class T>
void swap(std::vector<T> &v, int i, int j) {
	T aux = v[i];
	v[i] = v[j];
	v[j] = aux;
}

template <class T>
int operatorSort(std::vector<T> &v) {
	int pos;
	int count = 0;
	for(int i = v.size() - 1; i > 0; i--){
		pos = 0;
		for(int j = 1; j <= i; j++){
			if(v[pos] < v[j]){
				pos = j;
			}
		}
		if (pos != i){
			count++;
			swap(v, i, pos);
		}
	}
	return count;
}

int selectionSort(std::vector<Barco> &v) {
	int pos;
	int count = 0;
	for(int i = v.size() - 1; i > 0; i--){
		pos = 0;
		for(int j = 1; j <= i; j++){
			if(v[pos].isOlderThan(v[j])){
				pos = j;
			}
		}
		
		if (pos != i)
			swap(v, i, pos);
	}
}




#endif