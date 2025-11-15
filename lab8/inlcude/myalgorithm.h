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
    // ÓÑÈËÅÍÍÛÅ ÏĞÎÂÅĞÊÈ
    if (array == nullptr) return;
    if (left < 0 || right < 0 || left >= right) return;

    // ÏĞÎÂÅĞÈÒÜ ÂÀËÈÄÍÎÑÒÜ ÄÈÀÏÀÇÎÍÀ
    if (left > right) return;

    int pivotIndex = left + (right - left) / 2;  // Áîëåå áåçîïàñíûé ğàñ÷åò

    // ÏĞÎÂÅĞÈÒÜ ÂÀËÈÄÍÎÑÒÜ ÈÍÄÅÊÑÀ ÏÈÂÎÒÀ
    if (pivotIndex < left || pivotIndex > right) {
        pivotIndex = left;
    }

    T pivot = array[pivotIndex];

    int i = left;
    int j = right;

    while (i <= j) {
        // ÏĞÎÂÅĞßÒÜ ÃĞÀÍÈÖÛ Â ÊÀÆÄÎÉ ÈÒÅĞÀÖÈÈ
        if (i < left || i > right || j < left || j > right) break;

        // ÈÑÏÎËÜÇÎÂÀÒÜ <= è >= ÄËß ÈÇÁÅÆÀÍÈß ÇÀÖÈÊËÈÂÀÍÈß
        while (i <= right && array[i] < pivot) i++;
        while (j >= left && array[j] > pivot) j--;

        if (i <= j) {
            // ÄÎÏÎËÍÈÒÅËÜÍÀß ÏĞÎÂÅĞÊÀ ÏÅĞÅÄ ÎÁÌÅÍÎÌ
            if (i >= left && i <= right && j >= left && j <= right) {
                swap(array[i], array[j]);
            }
            i++;
            j--;

            // ÇÀÙÈÒÀ ÎÒ ÁÅÑÊÎÍÅ×ÍÎÃÎ ÖÈÊËÀ
            if (i > right || j < left) break;
        }
    }

    // ĞÅÊÓĞÑÈß Ñ ÏĞÎÂÅĞÊÎÉ ÂÀËÈÄÍÎÑÒÈ ÃĞÀÍÈÖ
    if (left < j && j >= 0 && j < right) {
        quickSort(array, left, j);
    }
    if (i < right && i >= left && i <= right) {
        quickSort(array, i, right);
    }
}

template<typename T>
void MyAlgorithm<T>::sortContainer(MyContainer<T>& data) {
    int totalSize = data.getTotalSize();

    if (totalSize <= 0 || totalSize > 10000) { // Îãğàíè÷åíèå ğàçìåğà
        return;
    }

    T* temp = nullptr;
    try {
        // ßâíàÿ ïğîâåğêà ğàçìåğà äëÿ SonarQube
        if (totalSize <= 0 || totalSize > 10000) {
            throw MyException("Invalid container size for sorting");
        }

        temp = new T[totalSize];

        // Êîïèğóåì ñ ïğîâåğêàìè
        int index = 0;
        for (auto it = data.begin(); it != data.end() && index < totalSize; ++it) {
            temp[index] = *it;
            index++;
        }

        // Ñîğòèğóåì
        if (totalSize > 0) {
            MyAlgorithm::quickSort(temp, 0, totalSize - 1);
        }

        // Êîïèğóåì îáğàòíî
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
