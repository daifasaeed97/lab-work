#include<iostream>
using namespace std;
template <typename Type>
class List
{
protected:
    Type* arr;
    int maxSize;
    int currentSize;

public:
    // Parameterized constructor
    List(int size = 10)
    {
        maxSize = size;
        currentSize = 0;
        arr = new Type[maxSize];
    }

    // Copy constructor
    List(const List<Type>& other)
    {
        maxSize = other.maxSize;
        currentSize = other.currentSize;

        arr = new Type[maxSize];

        for (int i = 0; i < currentSize; i++)
        {
            arr[i] = other.arr[i];
        }
    }

    
    virtual void addElementAtFirstIndex(Type element) = 0;
    virtual void addElementAtLastIndex(Type element) = 0;
    virtual Type removeElementFromEnd() = 0;
    virtual void removeElementFromStart() = 0;

    // Virtual destructor
    virtual ~List()
    {
        delete[] arr;
    }
};

