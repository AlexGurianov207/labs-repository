#ifndef MYARRAY_H
#define MYARRAY_H

#include <iostream>
#include <stdexcept>

template <typename T>
class MyArray {
 private:
  T* data = nullptr;
  int size;

 public:
  MyArray();
  explicit MyArray(int newSize);
  MyArray(const MyArray& other);
  MyArray(MyArray&& other) noexcept;

  MyArray& operator=(const MyArray& other);
  MyArray& operator=(MyArray&& other) noexcept;

  T& operator[](int index);
  const T& operator[](int index) const;

  friend std::istream& operator>>(std::istream& inputStream, MyArray& myArray) {
    for (size_t i = 0; i < myArray.size; i++) {
      inputStream >> myArray.data[i];
    }
    return inputStream;
  }

  friend std::ostream& operator<<(std::ostream& outputStream,
                                  const MyArray& myArray) {
    if (myArray.isEmpty()) {
      outputStream << "[Empty array]\n";
      return outputStream;
    }
    for (size_t i = 0; i < myArray.size; i++) {
      outputStream << myArray.data[i] << " ";
    }
    return outputStream;
  }

  int getIndexOfLastElement() const;
  int getSize() const;
  bool isEmpty() const;
  bool isValidIndex(int index) const;

  ~MyArray();
};

template <typename T>
MyArray<T>::MyArray() : size(0) {}

template <typename T>
MyArray<T>::MyArray(int newSize) : size(newSize) {
  if (size > 0) {
    data = new T[size];
    for (size_t i = 0; i < size; i++) {
      data[i] = T();
    }
  } else
    size = 0;
}

template <typename T>
MyArray<T>::MyArray(const MyArray& other) : size(other.size) {
  if (size > 0) {
    data = new T[size];
    for (size_t i = 0; i < size; i++) {
      data[i] = other.data[i];
    }
  }
}

template <typename T>
MyArray<T>::~MyArray() {
  delete[] data;
}

template <typename T>
MyArray<T>::MyArray(MyArray&& other) noexcept
    : size(other.size), data(other.data) {
  other.data = nullptr;
  other.size = 0;
}

template <typename T>
MyArray<T>& MyArray<T>::operator=(const MyArray& other) {
  if (this != &other) {
    delete[] data;
    size = other.size;
    if (size > 0) {
      data = new T[size];
      for (size_t i = 0; i < size; i++) {
        data[i] = other.data[i];
      }
    } else
      data = nullptr;
  }
  return *this;
}

template <typename T>
T& MyArray<T>::operator[](int index) {
  if (isEmpty()) {
    std::cout
        << "Error.Array is empty.The element is assigned the default value:";
    static T defaultValue = T();
    return defaultValue;
  }
  if (!(isValidIndex(index))) {
    static T defaultValue = T();
    std::cout << "Error:going beyond the array boundary.The element is "
                 "assigned the default value:";
    return defaultValue;
  } else {
    return data[index];
  }
}

template <typename T>
MyArray<T>& MyArray<T>::operator=(MyArray&& other) noexcept {
  if (this != &other) {
    delete[] data;
    size = other.size;
    data = other.data;
    other.data = nullptr;
    other.size = 0;
  }
  return *this;
}

template <typename T>
const T& MyArray<T>::operator[](int index) const {
  if (isEmpty()) {
    std::cout
        << "Error.Array is empty.The element is assigned the default value:";
    static T defaultValue = T();
    return defaultValue;
  }
  if (!(isValidIndex(index))) {
    static T defaultValue = T();
    std::cout << "Error:going beyond the array boundary.The element is "
                 "assigned the default value:";
    return defaultValue;
  } else {
    return data[index];
  }
}

template <typename T>
int MyArray<T>::getIndexOfLastElement() const {
  return size > 0 ? size - 1 : 0;
}

template <typename T>
int MyArray<T>::getSize() const {
  return size;
}

template <typename T>
bool MyArray<T>::isEmpty() const {
  return size == 0;
}

template <typename T>
bool MyArray<T>::isValidIndex(int index) const {
  return index < size && index >= 0;
}

#endif
