#include "my_vector.h"
MyVector::MyVector()
{
    _sz = 0;
    _cp = 2;
    _data = new int[_cp];
}

MyVector::MyVector(std::size_t init_capacity) 
{
    _data = new int[init_capacity];
    _sz = 0;
    _cp = init_capacity;
}

MyVector::~MyVector() 
{
    delete [] _data;

}

void MyVector::newMemory(std::size_t new_cp) 
{
    int *_t = new int[new_cp];
    for (std::size_t index = 0; index < new_cp && index < _sz; index++)
    {
        _t[index] = _data[index];
    }
    delete [] _data;
    _data = _t;
}

 void MyVector::set(std::size_t index, int value) 
{
    _data[index] = value;
}

int MyVector::get(std::size_t index) const
{
    return _data[index];
}

std::size_t MyVector::size() const
{
    return _sz;
}

std::size_t MyVector::capacity() const
{
    return _cp;
}

void MyVector::reserve(std::size_t new_capacity) 
{
    if (_cp < new_capacity)
    {
        newMemory(new_capacity);
        _cp = new_capacity;
    }
}

void MyVector::resize(std::size_t bnew_size) //??
{
   /* if (bnew_size <= _sz)
    {
        for (std::size_t index = _sz; index >= bnew_size; ++index)
            erase(index);
        _sz = bnew_size;
    }
    else
    {
        newMemory(bnew_size);
        for (std::size_t index = _sz - 1; index < bnew_size; ++index)
        {
          push_back(0);
        }
    }*/
    reserve(bnew_size);
    for (; _sz < bnew_size; _sz++)
        _data[_sz] = 0;

    _cp = bnew_size;
}

void MyVector::push_back(int value) 
{
    if (_sz >= _cp)
        reserve(_cp * 2);
    
    _data[_sz++] = value;
}

void MyVector::insert(std::size_t index, int value) {
    if (_sz >= _cp)
        reserve(_cp * 2);
    for (std::size_t ind = _sz++; ind > index; --ind)
    {
        _data[ind] = _data[ind - 1]; 
    }
    _data[index] = value;

}

void MyVector::erase(std::size_t index) 
{
    --_sz;
    for(std::size_t ind = index; ind < _sz; ++ind)
    {
        _data[ind] = _data[ind + 1];
    }
}