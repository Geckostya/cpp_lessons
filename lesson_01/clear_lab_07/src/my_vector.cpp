#include "my_vector.h"
MyVector::MyVector()
{
	this->_sz = 0;
	this->_cp = 2;
	this->_data = new int[this->_cp];
}

MyVector::MyVector(std::size_t init_capacity) 
{
	this->_data = new int[init_capacity];
	this->_sz = 0;
	this->_cp = init_capacity;
}

MyVector::~MyVector() 
{
	delete [] _data;

}

void MyVector::newMemory(std::size_t new_cp) 
{
    int *_t = new int[new_cp];
    for (size_t index = 0; index < new_cp || index < this->_sz; index++)
    {
    	_t[index] = this->_data[index];
    }
    delete [] _data;
	_data = _t;
}

 void MyVector::set(std::size_t index, int value) 
{
    this->_data[index] = value;
}

const int MyVector::get(std::size_t index) 
{
    return this->_data[index];
}

const std::size_t MyVector::size() 
{
	return this->_sz;
}

const std::size_t MyVector::capacity() 
{
	return this->_cp;
}

void MyVector::reserve(std::size_t new_capacity) 
{
    if (this->_cp < new_capacity)
    {
    	newMemory(new_capacity);
        this->_cp = new_capacity;
    }
}

void MyVector::resize(std::size_t bnew_size) 
{
	if (bnew_size <= this->_sz)
	{
		for (int index = this->_sz; index >= bnew_size; ++index)
		    erase(index);
		this->_sz = bnew_size;
	}
	else
	{
		newMemory(bnew_size);
		for (int index = this->_sz - 1; index < bnew_size; ++index)
		{
		  push_back(0);
		}
	}
}

void MyVector::push_back(int value) 
{
	if (this->_cp > this->_sz)
	{
	    this->_data[++this->_sz] = value;
	}
	else 
	{
        reserve(this->_cp * 2);
	}
}

void MyVector::insert(std::size_t index, int value) {
    if (this->_sz++ == this->_cp)
    	reserve(this->_cp * 2);
    for (int ind = index; ind < this->_sz; ++ind)
    {
    	int i = this->_data[ind];
    	this->_data[ind] = value;
    	value = i;
    }
}

void MyVector::erase(std::size_t index) 
{
	--this->_sz;
    for(int ind = index; ind < this->_sz; ++ind)
    {
    	this->_data[ind] = this->_data[ind + 1];
    }
}