#ifndef MENU_H
#define MENU_H

#include"myarray.h"

void showMenu();

void testIntArray();

void testDoubleArray();

void testStringArray();

void testBoolArray();

void testCharArray();

template<typename T>
void testArray() {
	int size;
	std::cout << "Enter the size:";
	std::cin >> size;
	if (std::cin.fail() || size < 0) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Error: Size must be non-negative number" << std::endl;
		return;
	}

	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	MyArray<T> myArray(size);

	if (myArray.isEmpty()) {
		std::cout << "Array is empty - no needed to input" << std::endl;
	}
	else {
		std::cout << "-----Entering array-----" << std::endl;
		std::cin >> myArray;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Error" << std::endl;
			return;
		}

		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	std::cout << "Your array:";
	std::cout << myArray << std::endl;

	std::cout << "Array size: " << myArray.getSize() << std::endl;
	std::cout << "Is empty: " << (myArray.isEmpty() ? "Yes" : "No") << std::endl;

	if (myArray.isEmpty()) {
		std::cout << "Array is empty - no elements to access to by index" << std::endl;
	}
	else {
		std::cout << "Enter the index to see element[0 - " << myArray.getIndexOfLastElement() << "]:";
		int index;
		std::cin >> index;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Error" << std::endl;
			return;
		}

		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		std::cout << "[" << index << "]:" << myArray[index] << std::endl;
	}

	MyArray<T> copyArray(myArray);
	std::cout << "Copied array:" << copyArray << std::endl;

}


#endif
