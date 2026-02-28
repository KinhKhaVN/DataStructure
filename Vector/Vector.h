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
    Vector(const Vector & other);
    ~Vector();

    void fill(const T & value);
    template <class Iterator>
    void assign(Iterator start, Iterator end);
    void clear();

    T * getData();
    T & at(size_t index);
    const T & at(size_t index) const ;
    T & front();
    const T & front() const ;
    T & back();
    const T & back() const ;
    T * begin();
    T * end();

    void push_back(const T & value);
    void pop_back();
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
Vector<T>::Vector(const Vector & other)
{
  capacity = other.capacity;
  size = other.size;
  data = (T*) malloc(capacity * sizeof(T));
  fill(other.data[0]);
}


template <class T>
void Vector<T>::fill(const T &value)
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
  return data[index];

}

template <class T>
const T & Vector<T>::at(size_t index) const
{
  return data[index];
}

template <class T>
T & Vector<T>::back()
{
  return data[size - 1];
}

template <class T>
const T & Vector<T>::back() const
{
  return data[size - 1];
}

template <class T>
T & Vector<T>::front()
{
  return data[0];
}

template <class T>
const T & Vector<T>::front() const
{
  return data[0];
}

template <class T>
T * Vector<T>::begin()
{
  return &data[0];
}

template <class T>
T * Vector<T>::end()
{
  return &data[size];
}

template <class T>
void Vector<T>::clear()
{
  fill(0);
  size = 0;
}

template <class T>
T * Vector<T>::getData()
{
  return data;
}

template <class T>
void Vector<T>::push_back(const T & value)
{
  if (size == capacity)
  {
    size_t newCapacity = capacity + 2;
    T* newData = (T *) malloc(newCapacity);

    FOR(i, size)
      newData[i] = data[i];

    capacity = newCapacity;
    data = newData;
    free(newData);
  }

  data[size] = value;
  size++;
}

#endif
