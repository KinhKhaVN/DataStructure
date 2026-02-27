#ifndef VECTOR_H
#define VECTOR_H

#include <cstdio>
#include <cstring>
#include <iostream>
#include <cstdlib>
#include <new>
#include <stdexcept>

#define DEFAULT_CAPACITY 5
#define FOR(i, size) for (size_t i = (0); i < (size); i++)

template <class T>
class Vector
{
  public:
    size_t capacity;
    size_t size;
    T * data;
  public:
    Vector();
    Vector(T & value);
    Vector(const T & value);
    Vector(size_t n, T value);
    Vector(Vector & other);
    Vector(const Vector & other);
    ~Vector();

    void fill(T value);
    template <class Iterator>
    void assign(Iterator start, Iterator end);
    T & at(size_t index);
    T & at(size_t index) const ;
    T & front();
    T & front() const ;
    T & back();
    T & back() const ;
    T * begin();
    T * end();
    void Info();
    void Print();

    Vector& operator = (T & value);
    Vector& operator = (const T & value);

};

template <class T>
Vector<T>::~Vector()
{
  free(data);
}

template <class T>
Vector<T>::Vector()
{
  size = 0;
  capacity = DEFAULT_CAPACITY;
  data = (T*) malloc(capacity * sizeof(T));
  fill(0);
}

template <class T>
Vector<T>::Vector(size_t n, T value)
{
  capacity = n + 2;
  size = n;
  data = (T*) malloc(capacity * sizeof(T));
  fill(value);
}

template <class T>
Vector<T>::Vector(Vector & other)
{
  capacity = other.capacity;
  size = other.size;
  data = (T*) malloc(capacity * sizeof(T));
  fill(other.data[0]);
}

template <class T>
Vector<T>::Vector(const Vector & other)
{
  capacity = other.capacity;
  size = other.size;
  data = (T*) malloc(capacity * sizeof(T));
  fill(other.data[0]);
}


template <class T>
void Vector<T>::fill(T value)
{
  FOR(i, size)
    data[i] = value;
}


template <class T>
template <class Iterator>
void Vector<T>::assign(Iterator start, Iterator end)
{
  size_t i = 0;

  for (Iterator it = start; it != end; it++)
    data[i++] = *it;
}

template <class T>
void Vector<T>::Info()
{
  std::cout << "Capacity: " << capacity << '\n';
  std::cout << "Size: " << size << '\n';
}

template <class T>
void Vector<T>::Print()
{
  FOR(i, size)
    std::cout << data[i] << " ";

  putchar('\n');
}

template <class T>
T & Vector<T>::at(size_t index)
{
  try {

    if (index >= size)
      throw "Out of range!";
    return data[index];

  } catch (const char * error) {

    std::cerr << "Error: " << error << '\n';
    std::cerr << "Index: " << index << '\n';
    return -1;
  }
}

template <class T>
T & Vector<T>::back()
{
  try {
    return data[size - 1];
  } catch (std::bad_alloc error) {
    std::cerr << error.what() << '\n';
  }
}

template <class T>
T & Vector<T>::front()
{
  try {
    return data[0];
  } catch (std::bad_alloc error) {
    std::cerr << error.what() << '\n';
  }
}


template <class T>
T * Vector<T>::begin()
{
  try {
    return &data[0];
  } catch (std::bad_alloc error) {
    std::cerr << error.what() << '\n';
  }
}

template <class T>
T * Vector<T>::end()
{
  try {
    return &data[size - 1];
  } catch (std::bad_alloc error) {
    std::cerr << error.what() << '\n';
  }
}



#endif
