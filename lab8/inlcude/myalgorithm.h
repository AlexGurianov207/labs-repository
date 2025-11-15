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
    // ДОБАВИТЬ ПРОВЕРКИ ГРАНИЦ
    if (left < 0 || right < 0 || left >= right) return;

    // ПРОВЕРИТЬ ВАЛИДНОСТЬ УКАЗАТЕЛЯ
    if (array == nullptr) return;

    // ПРОВЕРИТЬ ИНДЕКС ПИВОТА
    int pivotIndex = (right + left) / 2;
    if (pivotIndex < left || pivotIndex > right) {
        pivotIndex = left;  // Использовать левую границу как запасной вариант
    }

    T pivot = array[pivotIndex];

    int i = left;
    int j = right;

    while (i <= j) {
        // ДОБАВИТЬ ПРОВЕРКИ ГРАНИЦ В ЦИКЛАХ
        while (i <= right && array[i] < pivot) i++;
        while (j >= left && array[j] > pivot) j--;

        if (i <= j) {
            // ПРОВЕРИТЬ ИНДЕКСЫ ПЕРЕД ОБМЕНОМ
            if (i >= left && i <= right && j >= left && j <= right) {
                swap(array[i], array[j]);
            }
            i++;
            j--;
        }
    }

    // РЕКУРСИЯ С ПРОВЕРКОЙ ГРАНИЦ
    if (left < j) quickSort(array, left, j);
    if (i < right) quickSort(array, i, right);
}

template<typename T>
void MyAlgorithm<T>::sortContainer(MyContainer<T>& data) {
    int totalSize = data.getTotalSize();

    if (totalSize <= 0 || totalSize > 10000) { // Ограничение размера
        return;
    }

    T* temp = nullptr;
    try {
        // Явная проверка размера для SonarQube
        if (totalSize <= 0 || totalSize > 10000) {
            throw MyException("Invalid container size for sorting");
        }

        temp = new T[totalSize];

        // Копируем с проверками
        int index = 0;
        for (auto it = data.begin(); it != data.end() && index < totalSize; ++it) {
            temp[index] = *it;
            index++;
        }

        // Сортируем
        if (totalSize > 0) {
            MyAlgorithm::quickSort(temp, 0, totalSize - 1);
        }

        // Копируем обратно
        index = 0;
        for (auto it = data.begin(); it != data.end() && index < totalSize; ++it) {
            *it = temp[index];
            index++;
        }

        delete[] temp;
        temp = nullptr;
    }
    catch (...) {
        if (temp != nullptr) {
            delete[] temp;
        }
        throw;
    }
}

#endif 
