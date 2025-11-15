#ifndef MYALGORITHM_H
#define MYALGORITHM_H

#include"myiterator.h"
#include"mycontainer.h"

template<typename T>
class MyAlgorithm {
private:
	static void quickSort(T* array, int left, int right);

	static void swap(T& a, T& b);

public:
	static MyIterator<T> find(MyContainer<T>& data, const T& value);

	static void sortContainer(MyContainer<T>& data);
};

template<typename T>
MyIterator<T> MyAlgorithm<T>::find(MyContainer<T>& data, const T& value) {
	for (auto it = data.begin(); it != data.end(); ++it) {
		if (*it == value) {
			return it;
		}
	}
	return data.end();
}

template<typename T>
void MyAlgorithm<T>::swap(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}

template<typename T>
void MyAlgorithm<T>::quickSort(T* array, int left, int right) {
	if (left >= right)return;

	T pivot = array[(right + left) / 2];

	int i = left;
	int j = right;

	while (i <= j) {
		while (array[i] < pivot)i++;
		while (array[j] > pivot)j--;

		if (i <= j) {
			swap(array[i], array[j]);
			i++;
			j--;
		}
	}
	quickSort(array, left, j);
	quickSort(array, i, right);
}

template<typename T>
void MyAlgorithm<T>::sortContainer(MyContainer<T>& data) {
	int totalSize = data.getTotalSize();

	if (totalSize == 0)return;

	T* temp = new T[totalSize];

	int index = 0;
	for (auto it = data.begin(); it != data.end(); ++it) {
		temp[index++] = *it;
	}

	MyAlgorithm::quickSort(temp, 0, totalSize - 1);

	index = 0;
	for (auto it = data.begin(); it != data.end(); ++it) {
		*it = temp[index++];
	}

	delete[] temp;
}

#endif 
