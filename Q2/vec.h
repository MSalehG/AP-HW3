#ifndef VEC_H
#define VEC_H

#include <iostream>

class Vec
{
public:
	Vec(int);

	//The copy constructor
	Vec(const Vec&);

	//The default constructor
	Vec();

	//The move constructor
	Vec(Vec&&);

	void push_back(int);
	void pop_back();

	void incSize(int num);

	int operator[](size_t);
	Vec operator+(const Vec&) const;
	Vec operator*(const Vec&) const;

	bool operator>(const Vec&) const;
	bool operator==(const Vec&) const;
	Vec& operator=(const Vec&);
	Vec& operator=(Vec&&);

	void show();

	~Vec();

	int size;
	int capacity;
	int* var;

private:

};



#endif