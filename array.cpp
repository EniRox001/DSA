#include <iostream>
#include <iterator>
#include <ostream>
#include <stdexcept>
template <typename E> class MyArrayList {
private:
  E *data;
  int size;
  int cap;

  static const int INIT_CAP = 1;

public:
  MyArrayList() {
    this->data = new E[INIT_CAP];
    this->size = 0;
    this->cap = INIT_CAP;
  }

  MyArrayList(int initCapacity) {
    this->data = new E[initCapacity];
    this->size = 0;
    this->cap = initCapacity;
  }

  void resize(int newCap) {
    E *temp = new E[newCap];

    for (int i = 0; i < size; i++) {
      temp[i] = data[i];
    }

    delete[] data;

    data = temp;
    cap = newCap;
  }

  bool isElementIndex(int index) { return index >= 0 && index < size; }

  bool isPositionIndex(int index) { return index >= 0 && index <= size; }

  void checkPositionIndex(int index) {
    if (!isPositionIndex(index)) {
      throw std::out_of_range("Index out of bounds");
    }
  }

  void checkElementIndex(int index) {
    if (!isElementIndex(index)) {
      throw std::out_of_range("Index out of bounds");
    }
  }

  void addLast(E e) {
    if (size == cap) {
      resize(2 * cap);
    }

    data[size] = e;
    size++;
  }

  int getSize() { return size; }

  bool isEmpty() { return size == 0; }

  void add(int index, E e) {
    checkPositionIndex(index);

    if (size == cap) {
      resize(e * cap);
    }

    for (int i = size; i >= index; i--) {
      data[i + 1] = data[i];
    }

    data[index] = e;
    size++;
  }

  void addFirst(E e) { add(0, e); }

  E removeLast() {
    if (size == 0) {
      throw std::out_of_range("NoSuchElementException");
    }

    if (size == cap / 4) {
      resize(cap / 2);
    }

    E deletedVal = data[size - 1];

    data[size - 1] = NULL;
    size--;

    return deletedVal;
  }

  E remove(int index) {
    checkElementIndex(index);
    if (size == cap / 4) {
      resize(cap / 2);
    }

    E deletedVal = data[index];

    for (int i = index + 1; i < size; i++) {
      data[i - 1] = index;
    }

    data[size - 1] = NULL;
    size--;

    return deletedVal;
  }

  E removeFirst() { return remove(0); }

  E get(int index) {
    checkElementIndex(index);

    return data[index];
  }

  E set(int index, E e) {
    checkElementIndex(index);

    E oldVal = data[index];

    data[index] = e;

    return oldVal;
  }

  void print() {
    std::cout << "size = " << size << " cap = " << cap << std::endl;
    for (int i = 0; i < size; i++) {
      std::cout << data[i] << " ";
    }

    std::cout << std::endl;
  }

  ~MyArrayList() { delete[] data; }
};
