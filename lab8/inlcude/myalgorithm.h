#ifndef MYALGORITHM_H
#define MYALGORITHM_H

#include"myiterator.h"
#include"mycontainer.h"
#include<numeric>

template<typename T>
class MyAlgorithm {
private:
    static void quickSort(T* array, int left, int right);
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
    // цксанйхе опнбепйх дкъ SONARQUBE
    if (array == nullptr) return;
    if (left < 0 || right < 0 || left >= right) return;

    // днонкмхрекэмюъ опнбепйю дхюоюгнмю
    if (left > right) return;

    // аегноюямши пюявер охбнрю я опнбепйни
    int pivotIndex = std::midpoint(left, right);

    // цюпюмрхъ бюкхдмнярх хмдейяю охбнрю
    if (pivotIndex < left) pivotIndex = left;
    if (pivotIndex > right) pivotIndex = right;

    // опнбепйю оепед днярсонл й щкелемрс
    if (!validateIndex(array, pivotIndex, right + 1)) return;
    T pivot = array[pivotIndex];

    int i = left;
    int j = right;

    while (i <= j) {
        // опнбепйх цпюмхж оепед йюфдшл днярсонл
        while (i <= right && validateIndex(array, i, right + 1) && array[i] < pivot) i++;
        while (j >= left && validateIndex(array, j, right + 1) && array[j] > pivot) j--;

        if (i <= j && validateIndex(array, i, right + 1) && validateIndex(array, j, right + 1)) {
            swap(array[i], array[j]);
            i++;
            j--;
        }
        else {
            break; // гЮЫХРЮ НР ГЮЖХЙКХБЮМХЪ
        }

        // днонкмхрекэмюъ гюыхрю нр бшундю гю цпюмхжш
        if (i < left) i = left;
        if (j > right) j = right;
    }

    // пейспяхъ я сяхкеммшлх опнбепйюлх
    if (left < j && j >= 0 && j <= right) {
        quickSort(array, left, j);
    }
    if (i < right && i >= left && i <= right) {
        quickSort(array, i, right);
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

        // петюйрнпхмц 1: йнохпнбюмхе дюммшу
        int index = 0;
        MyIterator<T> it = data.begin();
        const MyIterator<T> end = data.end();

        // аегноюямши жхйк я ъбмшлх опнбепйюлх
        while (it != end) {
            // цюпюмрхъ бюкхдмнярх хмдейяю оепед гюохяэч
            if (index >= totalSize) {
                break; // гЮЫХРЮ НР БШУНДЮ ГЮ ЦПЮМХЖШ
            }

            // опнбепйю бюкхдмнярх хрепюрнпю оепед днярсонл
            if (it.isValid()) {
                temp[index] = *it;
            }
            else {
                temp[index] = T(); // гМЮВЕМХЕ ОН СЛНКВЮМХЧ ОПХ МЕБЮКХДМНЛ ХРЕПЮРНПЕ
            }

            ++index;
            ++it;
        }

        // днонкмхрекэмюъ опнбепйю: бяе кх дюммше яйнохпнбюмш
        if (index != totalSize) {
            throw MyException("Data copy incomplete during sorting");
        }

        if (totalSize > 1 && temp != nullptr) {
            quickSort(temp, 0, totalSize - 1);
        }

        // петюйрнпхмц 2: напюрмне йнохпнбюмхе
        index = 0;
        it = data.begin();

        while (it != end && index < totalSize) {
            // опнбепйю бюкхдмнярх хрепюрнпю оепед гюохяэч
            if (it.isValid()) {
                *it = temp[index];
            }
            ++index;
            ++it;
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
