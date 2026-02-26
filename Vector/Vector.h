#ifndef VECTOR_H
#define VECTOR_H

#include <cstdio>
#include <cstring>
#include <iostream>
#include <cstdlib>

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
    void Info();
    void Print();

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



#endif
