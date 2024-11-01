#pragma once
#include <iostream>
#include<algorithm>
#include<stdexcept>
using namespace std; 

template<class T >
class DArray
{
private:
    size_t capacity;
    size_t size;
    T* arr;


    // HELPER FUNCTION 
    
    // Resize function
    void resize(size_t newCapacity)
    {
        T* ptr = new T[newCapacity];
        for (size_t i = 0; i < size; i++)
        {
            ptr[i] = arr[i];
        }
        delete[] arr;
        arr = ptr;
        capacity = newCapacity;
    }

public:
    DArray(size_t newcapacity = 2) : size(0), capacity(newcapacity)
    {
        arr = new T[capacity];
    }

    ~DArray()
    {
        delete[] arr;
    }
    // Copy Constructor
    DArray(const DArray& object2)
    {
        size = object2.size;
        capacity = object2.capacity;
        arr = new T[capacity];
        for (size_t i = 0; i <= size; ++i)
        {
            arr[i] = object2.arr[i];
        }
    }
    // Assignment Operator 
    DArray& operator=(const DArray& object2)
    {
        if (*this == object2)
            return *this;
        delete[] arr;
        size = object2.size;
        capacity = object2.capacity;
        arr = new T[capacity];
        for (size_t i = 0; i <= size; ++i)
        {
            arr[i] = object2.arr[i];
        }
        return (*this);
    }
    // OverlOading Operator 
    T& operator[](size_t index)
    {
        if (size > 0 && index < size)
        {
            return arr[index];
        }
        throw out_of_range("Index out of range");
    }

    // Append function
    void append(T newelement)
    {
        if (size >= capacity)
        {
            resize(2 * capacity);
        }
        arr[++size] = newelement;
    }

    // Insert function
    void insert(T newelement , size_t index )
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
            arr[i] = arr[i - 1];
        }
        arr[index] = newelement;
        size++;
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
            arr[i] = arr[i + 1];
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

    // GEtSize 
    size_t getSize()
    {
        return size; 
    }


    // ifFave 
    
    // Reverse the array
    void reverse()
    {
        size_t start = 0, end = size - 1;

        while (start < end)
        {
            T temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
            start++;
            end--;
        }
    }

    


};
