#ifndef ORACLE_H
#define ORACLE_H

#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include "human.h"

class Oracle : public Human
{
public:
	Oracle(std::string Name);
	Oracle();
	bool marry(Human*, Human*);
	bool isFamily(Human*, Human*);
	void setChild(Human*, Human*, Human*);
	Human** getFamily(Human*);
	int getPopulationOfFamily(Human*);

	~Oracle();

private:
	std::string Name;
	int populationOfFamily;
};


#endif