#include <iostream>
using namespace std;

class DynamicArray
{
private:
    int _capacity;
    int _count;
    int *_data;
    bool *_setData;

public:
    DynamicArray(int capacity)
    {
        _capacity = capacity;
        _data = new int[capacity];
        _setData = new bool[capacity];
        _count = 0;
    }

    int get(int i)
    {
        return _data[i];
    }

    void set(int i, int n)
    {
        if (!isValueSet(i))
        {
            _setData[i] = true;
            _count++;
        }
        _data[i] = n;
    }

    bool isValueSet(int i)
    {
        return _setData[i];
    }

    void pushback(int n)
    {
        if (_count == _capacity)
        {
            resize();
        }

        set(_count, n);
    }

    int popback()
    {
        int val = get(_count - 1);

        int *temp = _data;
        _data = new int[_count - 1];
        for (int i = 0; i < _count - 1; i++)
        {
            _data[i] = temp[i];
        }
        delete[] temp;

        _count--;

        return val;
    }

    void resize()
    {
        int *temp = _data;
        _data = new int[_capacity * 2];
        for (int i = 0; i < _capacity; i++)
        {
            _data[i] = temp[i];
        }
        delete[] temp;

        _capacity = _capacity * 2;

        cout << "RESIZED TO: " << _capacity << endl;
    }

    int getSize()
    {
        return _count;
    }

    int getCapacity()
    {
        return _capacity;
    }

    void print()
    {
        int *temp = _data;
        cout << "[" << " ";
        for (int i = 0; i < _capacity; i++)
        {
            cout << *temp++ << " ";
        }
        cout << "]" << " ";
    }

    int *copyData(int newSize, int copyTo)
    {
        int *temp = new int{newSize};
        for (int i = 0; i < copyTo; i++)
        {
            temp[i] = _data[i];
        }
        return temp;
    }
};