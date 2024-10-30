#pragma once
#include <iostream>
using namespace std; 

template<class T >
class Array
{
private:
    size_t capacity;
    size_t size;
    T* dcArr;

    // Resize function
    void resize(size_t newCapacity)
    {
        T* ptr = new T[newCapacity];
        for (size_t i = 0; i < size; i++)
        {
            ptr[i] = Array[i];
        }
        delete[] Array;
        Array = ptr;
        capacity = newCapacity;
    }

public:
    DcArray(size_t capacity) : size(0), capacity(capacity)
    {
        Array = new T[capacity];
    }

    ~DcArray()
    {
        delete[] Array;
    }

    // Append function
    void append(T element)
    {
        if (size >= capacity)
        {
            resize(2 * capacity);
        }
        Array[size++] = element;
    }

    // Insert function
    void insert(size_t index, T newelement)
    {
        if (index >= size)
        {
            cout << "Index Out Of Range\n";
            return;
        }

        if (size >= capacity)
        {
            resize(2 * capacity);
        }

        for (size_t i = size; i > index; i--)
        {
            Array[i] = dcArr[i - 1];
        }
        Array[index] = element;
        size++;
    }
    // Update function
    void update(size_t index, T newElement)
    {
        if (index >= size)
        {
            cout << "Index Out Of Range\n"; 
        }
        Array[index] = newElement;
    }


    // Remove last element
    void remove()
    {
        if (size > 0)
            size--;
    }

    // Delete element at a specific index
    void Delete(size_t index)
    {
        if (index >= size) return;

        for (size_t i = index; i < size - 1; i++)
        {
            Array[i] = dcArr[i + 1];
        }
        size--;
        if (size <= capacity / 4)
        {
            resize(capacity / 2);
        }
    }

    // Clear all elements
    void clear()
    {
        size = 0;
        resize(2);
    }

    // Reverse the array
    void reverse()
    {
        size_t start = 0, end = size - 1;

        while (start < end)
        {
            T temp = Array[start];
            Array[start] = Array[end];
            Array[end] = temp;
            start++;
            end--;
        }
    }


};
