#ifndef HUMAN_H
#define HUMAN_H

#include <cmath>
#include <string>
#include <vector>

class Human
{
public:
	Human(std::string firstName, std::string lastName, int hairColor, int eyeColor, int age, bool gender, int numberOfChildren);
	Human();
	Human(const Human&);

	std::string getFirstName();
	std::string getLastName();
	bool getGender();
	int getHairColor();
	int getEyeColor();
	int getAge();
	bool operator>(const Human&) const;
	bool operator==(const Human&) const;

	void operator=(const Human&);

	Human* operator+(Human&);
	void operator++(int);
	bool isChildOf(Human*);
	bool isFatherOf(Human*);
	bool isMotherOf(Human*);
	void printChildren();

	void setFirstName(std::string firstName);
	void setLastName(std::string lasttName);
	void setGender(bool gender);
	void setHairColor(int hairColor);
	void setEyeColor(int eyeColor);
	int getNumberOfChildren();
	void increaseNumberOfChildren();



	Human* father;
	Human* mother;
	Human* spouse;
	Human** Children;

	~Human();

private:
	std::string firstName;
	std::string lastName;
	int hairColor;
	int eyeColor;
	int age;
	bool gender;
	int numberOfChildren;


};

#endif