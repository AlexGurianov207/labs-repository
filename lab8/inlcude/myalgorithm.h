#ifndef MYALGORITHM_H
#define MYALGORITHM_H

#include"myiterator.h"
#include"mycontainer.h"

template<typename T>
class MyAlgorithm {
private:
    static void quickSortRecursive(T* array, int left, int right);
    static int partition(T* array, int left, int right);
    static void swap(T& a, T& b);
    static bool validateIndex(const T* array, int index, int size);

public:
    static MyIterator<T> find(MyContainer<T>& data, const T& value);
    static void sortContainer(MyContainer<T>& data);
};

template<typename T>
bool MyAlgorithm<T>::validateIndex(const T* array, int index, int size) {
    return array != nullptr && index >= 0 && index < size;
}

template<typename T>
MyIterator<T> MyAlgorithm<T>::find(MyContainer<T>& data, const T& value) {
    // –≈‘¿ “Œ–»Õ√ ÷» À¿ - ¡ŒÀ≈≈ ◊»“¿≈Ã€… ¬¿–»¿Õ“
    MyIterator<T> it = data.begin();
    MyIterator<T> end = data.end();

    while (it != end) {
        if (*it == value) {
            return it;
        }
        ++it;
    }
    return end;
}

template<typename T>
void MyAlgorithm<T>::swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

template<typename T>
int MyAlgorithm<T>::partition(T* array, int left, int right) {
    // ¡≈«Œœ¿—Õ€… ¬€¡Œ– ŒœŒ–ÕŒ√Œ ›À≈Ã≈Õ“¿
    if (!validateIndex(array, left, right + 1) || !validateIndex(array, right, right + 1)) {
        return left;
    }

    int pivotIndex = left + (right - left) / 2;
    if (!validateIndex(array, pivotIndex, right + 1)) {
        pivotIndex = left;
    }

    T pivot = array[pivotIndex];
    int i = left - 1;
    int j = right + 1;

    while (true) {
        // –≈‘¿ “Œ–»Õ√ ÷» ÀŒ¬ - ¡≈« ¬ÀŒ∆≈ÕÕ€’ ”—ÀŒ¬»…
        do {
            i++;
        } while (validateIndex(array, i, right + 1) && array[i] < pivot);

        do {
            j--;
        } while (validateIndex(array, j, right + 1) && array[j] > pivot);

        if (i >= j) {
            return j;
        }

        if (validateIndex(array, i, right + 1) && validateIndex(array, j, right + 1)) {
            swap(array[i], array[j]);
        }
    }
}

template<typename T>
void MyAlgorithm<T>::quickSortRecursive(T* array, int left, int right) {
    if (array == nullptr) return;
    if (left < 0 || right < 0 || left >= right) return;

    int partitionIndex = partition(array, left, right);

    if (left < partitionIndex) {
        quickSortRecursive(array, left, partitionIndex);
    }
    if (partitionIndex + 1 < right) {
        quickSortRecursive(array, partitionIndex + 1, right);
    }
}

template<typename T>
void MyAlgorithm<T>::sortContainer(MyContainer<T>& data) {
    int totalSize = data.getTotalSize();

    if (totalSize <= 0) return;
    if (totalSize > 10000) {
        throw MyException("Container too large for sorting");
    }

    T* temp = nullptr;
    try {
        temp = new T[totalSize];

        int index = 0;
        MyIterator<T> it = data.begin();
        MyIterator<T> end = data.end();

        while (it != end && index < totalSize) {
            temp[index] = *it;
            ++it;
            ++index;
        }

        if (totalSize > 1 && temp != nullptr) {
            quickSortRecursive(temp, 0, totalSize - 1);
        }

        index = 0;
        it = data.begin();
        while (it != end && index < totalSize) {
            *it = temp[index];
            ++it;
            ++index;
        }

        delete[] temp;
        temp = nullptr;
    }
    catch (...) {
        if (temp != nullptr) {
            delete[] temp;
            temp = nullptr;
        }
        throw;
    }
}


#endif 
