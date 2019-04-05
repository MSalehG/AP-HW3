#ifndef MXHEAP
#define MXHEAP

#include <iostream>

class Maxheap;
void max_heapify(int*, int, int, int);
void build_max_heap(int*, int, int);
std::ostream& operator<<(std::ostream&, Maxheap&);

class Maxheap
{
public:
	Maxheap(int*, int);
	Maxheap(int);
	Maxheap();
	Maxheap(const Maxheap&);

	void add(int);
	void Delete();
	int Max();
	int getHeight();
	int Parent(int);
	int RightChild(int);
	int LeftChild(int);

	int heapHeight();

	int operator[](int);
	//void operator[](size_t, operator+(int));


	void Heapsort();
	void printArray();

	int* keys;
	int capacity;

	~Maxheap();

private:
	int height;


};





















#endif
