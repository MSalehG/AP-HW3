#include <iostream>
#include <cmath>
#include <algorithm>
#include "vec.h"

Vec::Vec(int num)
{
	if (num < 0)
		std::cout << "The size of the array should be positive\n";

	else
	{
		this->size = num;

		//For calculating the current capacity
		int iter{};

		while (static_cast<int>(std::pow(2, iter)) < num)
			iter++;


		this->capacity = static_cast<int>(std::pow(2, iter));



		if (num > 0)
		{
			this->var = new int[this->capacity];

			for (int i{}; i < this->capacity; i++)
				this->var[i] = 0;

		}

		else
		{
			//If the array is empty
			this->var = nullptr;
			this->capacity = 0;
			
		}

		std::cout << "An array with size " << this->size << " and capacity of  "
			<< this->capacity << " was created " << std::endl;
	}


}

Vec::Vec(const Vec& vec)
{
	std::cout << "The copy constructor of the Vec class has been called\n";


	this->size = vec.size;
	this->capacity = vec.capacity;

	this->var = new int[this->capacity];

	for (int i{}; i < this->capacity; i++)
		this->var[i] = vec.var[i];
}

void Vec::push_back(int data)
{
	this->size++;

	//This variable stores the previous capacity 
	int temp_capacity{ this->capacity };

	int iter{};

	while (static_cast<int>(std::pow(2, iter)) < this->size)
		iter++;

	this->capacity = static_cast<int>(std::pow(2, iter));

	//If the size was increased but the capacity stayed the same
	if (this->capacity == temp_capacity)
		this->var[this->size - 1] = data;


	else
	{
		int* temp{ new int[temp_capacity] };

		if (temp_capacity != 0)
		{
			for (int i{}; i < temp_capacity; i++)
				temp[i] = this->var[i];
		}

		delete this->var;
		this->var = new int[this->capacity];

		for (int i{}; i < this->capacity; i++)
		{
			if (i < this->size - 1)
				this->var[i] = temp[i];

			else if (i == this->size - 1)
				this->var[i] = data;

			else
				this->var[i] = 0;
		}

		delete temp;
	}

	std::cout << "The push_back function was called and " << data << " was added to the end of the array and now "
		<< "the size of the array is " << this->size << " and the capacity of the array is "
		<< this->capacity << std::endl;

}

void Vec::pop_back()
{
	this->size--;

	//This variable stores the previous capacity 
	int temp_capacity{ this->capacity };

	//If there was only one data in the array
	if (this->size == 0)
		this->capacity = 0;

	else
	{

		int iter{};

		while (static_cast<int>(std::pow(2, iter)) < this->size)
			iter++;

		this->capacity = static_cast<int>(std::pow(2, iter));

	}

	//In case the capacity is the same we just make the previous end of the array 0
	if (this->capacity == temp_capacity)
		this->var[this->size +1] = 0;

	else
	{
		if (this->size != 0)
		{
			int* temp{ new int[this->capacity] };
			for (int i{}; i < this->capacity; i++)
				temp[i] = this->var[i];

			delete this->var;
			this->var = new int[this->capacity];

			for (int i{}; i < this->capacity; i++)
				this->var[i] = temp[i];

			delete temp;
		}

		else
		{
			//If there was only one data in the array
			delete this->var;
			this->var = nullptr;
		}

	}

	std::cout << "The pop_back function was called and the data number " << this->size+1 
		<< " was removed from the end of the array and now "
		<< "the size of the array is " << this->size << " and the capacity of the array is "
		<< this->capacity << std::endl;
}

Vec::Vec() : Vec{0}
{
	std::cout << "The default constructor of the Vec class has been called\n";

}

void Vec::incSize(int num)
{
	//Storing the current size and capacity
	int temp_size{ this->size }, temp_capacity{ this->capacity };

	this->size = num;

	//For calculating the current capacity
	int iter{};

	while (static_cast<int>(std::pow(2, iter)) < num)
		iter++;

	this->capacity = static_cast<int>(std::pow(2, iter));

	if (this->capacity > temp_capacity)
	{
		//Storing the current data in the array
		int* temp{ new int[this->size] };

		for (int i{}; i < this->size; i++)
			temp[i] = this->var[i];

		//Resizing the array
		delete this->var;
		this->var = new int[this->capacity];

		for (int i{}; i < this->capacity; i++)
		{
			if (i < temp_size)
				this->var[i] = temp[i];

			else
				this->var[i] = 0;
		}

		delete temp;
	}

	std::cout << "The size of this array was increased to " << num
		<< " by 0 padding\n";
}


//This operator was created to ease indexing the array
int Vec::operator[](size_t i) {
	return this->var[i];
}


Vec Vec::operator+(const Vec& vec) const
{
	//Since we will need to change the arrays we create substitue arrays to work on them 
	Vec v1{ *this }, v2{ vec }, sum{ std::max(this->size, vec.size) };

	//If the sizes are different we padd the smaller one with zeroes so that they would have the same size
	if (v1.size > v2.size)
	{
		v2.incSize(v1.size);

		for (int i{}; i < v1.size; i++)
			sum.var[i] = v1.var[i] + v2.var[i];
	}

	else if (v1.size < v2.size)
	{
		v1.incSize(v2.size);

		for (int i{}; i < v2.size; i++)
			sum.var[i] = v1.var[i] + v2.var[i];
	}

	else
	{
		for (int i{}; i < this->size; i++)
			sum.var[i] = v1.var[i] + v2.var[i];
	}

	return sum;


}


Vec Vec::operator*(const Vec& vec) const
{
	//Since we will need to change the arrays we create substitue arrays to work on them 
	Vec v1{ *this }, v2{ vec }, pro{ std::max(this->size, vec.size) };

	//If the sizes are different we padd the smaller one with zeroes so that they would have the same size
	if (v1.size > v2.size)
	{
		v2.incSize(v1.size);

		for (int i{}; i < v1.size; i++)
			pro.var[i] = v1.var[i] * v2.var[i];
	}

	else if (v1.size < v2.size)
	{
		v1.incSize(v2.size);

		for (int i{}; i < v2.size; i++)
			pro.var[i] = v1.var[i] * v2.var[i];
	}

	else
	{
		for (int i{}; i < this->size; i++)
			pro.var[i] = v1.var[i] * v2.var[i];
	}

	return pro;
}

bool Vec::operator>(const Vec& vec) const
{
	if (this->size > vec.size)
		return true;

	else
		return false;

}

bool Vec::operator==(const Vec& vec) const
{
	if (this->size == vec.size)
		return true;

	else
		return false;
}


Vec& Vec::operator=(const Vec& vec)
{
	std::cout << "= Operator copy version\n";

	if (this == &vec)
		return *this;

	this->size = vec.size;
	this->capacity = vec.capacity;

	delete this->var;
	this->var = new int[this->capacity];

	for (int i{}; i < this->capacity; i++)
		this->var[i] = vec.var[i];

	return *this;

}


Vec& Vec::operator=(Vec&& vec)
{
	std::cout << "= Operator move version\n";

	if (this == &vec)
		return *this;

	this->size = vec.size;
	this->capacity = vec.capacity;

	delete this->var;
	this->var = vec.var;

	vec.var = nullptr;
	return *this;

}


void Vec::show()
{
	std::cout << "The size of this array is " << this->size 
		<< " and the data in this array are :\n";

	for (int i{}; i < this->size; i++)
		std::cout << this->var[i] << "	";

	std::cout << std::endl;
}


Vec::Vec(Vec&& vec)
{
	std::cout << "The move constructor of the Vec class has been called\n";

	this->size = vec.size;
	this->capacity = vec.capacity;

	//deleting the current array and stealing the array of the Rvalue vec
	this->var = vec.var;

	//Since the array of the vec was stolen we set its pointer to nullptr
	vec.var = nullptr;
}


Vec::~Vec()
{
	std::cout << "The destructor of the Vec class was called\n";

	if (this->var != nullptr)
		delete this->var;
}
