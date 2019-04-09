#include <iostream>
#include <cmath>
#include "maxheap.h"

void max_heapify(int* arr, int n, int s, int i)
{
	int temp{};

	//Checking the left child of the parent
	if (2 * i + 1 <= s - 1)
	{
		int left{ 2 * i + 1 };
		if (arr[i] < arr[left])
		{
			temp = arr[i];
			arr[i] = arr[left];
			arr[left] = temp;
		}
	}

	//Checking the right child of the parent
	if (2 * i + 2 <= s - 1)
	{
		int right{ 2 * i + 2};
		if (arr[i] < arr[right])
		{
			temp = arr[i];
			arr[i] = arr[right];
			arr[right] = temp;
		}
	}

}


void build_max_heap(int* arr, int n, int s)
{
	//Starting from the second last row up the root of the tree
	int cnt{ static_cast<int>(n / 2) };

	for (int i{ cnt - 1 }; i >= 0; i--)
		for (int j{ cnt - 1 }; j >= 0; j--)
			max_heapify(arr, n, s, j);
}


Maxheap::Maxheap(int* arr, int s)
{
	//For calculating the current capacity
	int iter{};

	while (static_cast<int>(std::pow(2, iter)) <= s)
		iter++;

	this->height = s;
	this->capacity = static_cast<int>(std::pow(2, iter)) - 1;

	this->keys = new int[this->height];

	for (int i{}; i < s; i++)
		this->keys[i] = arr[i];

	build_max_heap(this->keys, this->capacity, this->height);

}

Maxheap::Maxheap(int i)
{
	this->capacity = 1;
	this->keys[0] = i;
	this->height = 1;
}

Maxheap::Maxheap()
{
	std::cout << "The default constructor for the Maxheap class was called \n";
	this->keys = nullptr;
	this->capacity = 0;
	this->height = 0;

}

Maxheap::Maxheap(const Maxheap& m)
{
	this->capacity = m.capacity;
	this->height = m.height;

	this->keys = new int[this->height];

	for (int i{}; i < this->height; i++)
		this->keys[i] = m.keys[i];
}


void Maxheap::add(int node)
{
	this->height++;
	int iter{};

	while (static_cast<int>(std::pow(2, iter)) <= this->height)
		iter++;

	if (static_cast<int>(std::pow(2, iter)) > this->capacity)
		this->capacity = static_cast<int>(std::pow(2, iter)) - 1;

	if (this->keys != nullptr)
	{
		//To store the previous heap while we modify the heap
		int* temp{ new int[this->height - 1] };

		for (int i{}; i < this->height - 1; i++)
			temp[i] = this->keys[i];

		delete this->keys;

		this->keys = new int[this->height];
		for (int i{}; i < this->height - 1; i++)
			this->keys[i] = temp[i];

		this->keys[this->height - 1] = node;
		build_max_heap(this->keys, this->capacity, this->height);
	}

	//If we just added the first node
	else
	{
		this->keys = new int;
		this->keys[this->height - 1] = node;
	}

}

void Maxheap::Delete()
{
	//The total number of nodes in decreased by one 
	this->height--;
	int iter{};

	while (static_cast<int>(std::pow(2, iter)) <= this->height)
		iter++;

	if (static_cast<int>(std::pow(2, iter)) < this->capacity)
		this->capacity = static_cast<int>(std::pow(2, iter)) - 1;

	//We store all the current numbers except the maximum which is to be deleted
	int* temp{ new int[this->height] };

	for (int i{}; i < this->height; i++)
		temp[i] = this->keys[i+1];

	delete this->keys;

	this->keys = new int[this->height];
	for (int i{}; i < this->height; i++)
		this->keys[i] = temp[i];

	//We heapify the new tree
	build_max_heap(this->keys, this->capacity, this->height);

}

int Maxheap::Max()
{
	//The root of the tree which is the maximum
	return this->keys[0];
}

int Maxheap::getHeight()
{
	int iter{};

	while (static_cast<int>(std::pow(2, iter)) <= this->height)
		iter++;

	//Since we do not count the root of the tree as a row
	return iter - 1;
}

int Maxheap::heapHeight()
{
	return this->height;
}

std::ostream& operator<<(std::ostream& os, Maxheap& m)
{
	int iter{}, cnt{}, index{};

	while (static_cast<int>(std::pow(2, iter)) <= m.heapHeight())
		iter++;

	for (int i{}; i < iter; i++)
	{
		cnt = static_cast<int>(std::pow(2, i));
		for (int j{}; j < cnt; j++)
		{
			os << m.keys[index++] << " ,";
			if (index == m.heapHeight())
				break;

		}
		os << std::endl;
		if (index == m.heapHeight())
			return os;
	}

	return os;
}

int Maxheap::Parent(int node)
{
	if (node % 2 == 0)
		return this->keys[(node / 2) - 1];

	else
		return this->keys[static_cast<int>(node / 2)];
}

int Maxheap::LeftChild(int node)
{
	return this->keys[(2 * node + 1)];
}

int Maxheap::RightChild(int node)
{
	return this->keys[(2 * node + 2)];
}

int Maxheap::operator[](int node)
{
	return this->keys[node];
}



void Maxheap::Heapsort()
{
	build_max_heap(this->keys, this->capacity, this->height);
}

void Maxheap::printArray()
{
	std::cout << "The structure of the heap is illustrated below :\n";

	//iter is to index the rows of the tree, cnt is to index to column of the said row and index is to index the number of node
	int iter{}, cnt{}, index{};

	//calculating the number of rows
	while (static_cast<int>(std::pow(2, iter)) <= this->height)
		iter++;

	for (int i{}; i < iter; i++)
	{
		cnt = static_cast<int>(std::pow(2, i));
		for (int j{}; j < cnt; j++)
		{
			std::cout << this->keys[index++] << " ,";

			//if we have reached the end of the tree
			if (index == this->height)
				break;

		}
		std::cout << std::endl;
		if (index == this->height)
			return;
	}
}



Maxheap::~Maxheap()
{
	delete this->keys;
}