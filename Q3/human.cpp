#include <iostream>
#include <cmath>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "human.h"

Human::Human(std::string firstName, std::string lastName, int hairColor, int eyeColor, int age, bool gender, int numberOfChildren)
{
	this->firstName = firstName;
	this->lastName = lastName;

	std::cout << "A new person by the name of " << firstName << " " << lastName << " was created \n";

	this->hairColor = hairColor;
	this->eyeColor = eyeColor;
	this->age = age;
	this->gender = gender;
	this->numberOfChildren = numberOfChildren;

	this->father = nullptr;
	this->mother = nullptr;
	this->spouse = nullptr;

	this->Children = nullptr;

}

Human::Human() : Human("", "", 0, 0, 0, 0, 0)
{
	std::cout << "The default constructor for the Human class was called \n";

}

Human::Human(const Human& human)
{
	std::cout << "The copy constructor for the Human class was called \n";

	this->firstName = human.firstName;
	this->lastName = human.lastName;
	this->hairColor = human.hairColor;
	this->eyeColor = human.eyeColor;
	this->age = human.age;
	this->gender = human.gender;
	this->numberOfChildren = human.numberOfChildren;

	this->father = human.father;
	this->mother = human.mother;
	this->spouse = human.spouse;

	this->Children = new Human*[this->numberOfChildren];

	for (int i{}; i < this->numberOfChildren; i++)
		this->Children[i] = human.Children[i];

}

std::string Human::getFirstName()
{
	return this->firstName;
}

void Human::setFirstName(std::string firstName)
{
	this->firstName = firstName;
	std::cout << "The firstname of the person is set to " << firstName << std::endl;

}

std::string Human::getLastName()
{
	return this->lastName;
}

void Human::setLastName(std::string lastName)
{
	this->lastName = lastName;
	std::cout << "The lastname of the newborn child is set to " << lastName << std::endl;

}

bool Human::getGender()
{
	return this->gender;
}

void Human::setGender(bool gender)
{
	this->gender = gender;

	if (gender == true)
		std::cout << "The gender of the newborn child is female" << std::endl;
	else
		std::cout << "The gender of the newborn child male" << std::endl;
}

int Human::getHairColor()
{
	return this->hairColor;

}

void Human::setHairColor(int hairColor)
{
	this->hairColor = hairColor;
	std::cout << "The haircolor of the newborn child is set to " << hairColor << std::endl;

}

int Human::getEyeColor()
{
	return this->eyeColor;
}

void Human::setEyeColor(int eyeColor)
{
	this->eyeColor = eyeColor;
	std::cout << "The eyecolor of the newborn child is set to " << eyeColor << std::endl;

}

int Human::getAge()
{
	return this->age;
}

bool Human::operator>(const Human& human) const
{
	if (this->age > human.age)
		return true;
	else
		return false;
}

bool Human::operator==(const Human& human) const
{
	//Equal only if all the characteristics of the human are the same
	if ((this->firstName == human.firstName) && (this->lastName == human.lastName) &&
		(this->hairColor == human.hairColor) && (this->eyeColor == human.eyeColor) &&
		(this->age == human.age) && (this->gender == human.gender) &&
		(this->numberOfChildren == human.numberOfChildren) && (this->father == human.father) &&
		(this->mother == human.mother))
		return true;
	else
		return false;
}

void Human::operator=(const Human& human)
{
	if (*this == human)
		return;

	this->firstName = human.firstName;
	this->lastName = human.lastName;
	this->hairColor = human.hairColor;
	this->eyeColor = human.eyeColor;
	this->age = human.age;
	this->gender = human.gender;
	this->numberOfChildren = human.numberOfChildren;

	this->father = human.father;
	this->mother = human.mother;
	this->spouse = human.spouse;

	//First deleting the previous children then putting the Children of human in
	delete[] this->Children;
	this->Children = new Human*[this->numberOfChildren];

	for (int i{}; i < this->numberOfChildren; i++)
		this->Children[i] = human.Children[i];
}

Human* Human::operator+(Human& human)
{
	srand((unsigned)time(NULL)); //This command makes the random numbers generated in each run of the program different


	if (this == human.spouse)
	{
		//We use H1 and H2 to store the current Children of the parents
		Human** H1{ new Human*[this->numberOfChildren] }, **H2{ new Human*[human.numberOfChildren] };
		for (int i{}; i < this->numberOfChildren; i++) {
			H1[i] = this->Children[i];
			H2[i] = human.Children[i];
		}

		delete[] this->Children;
		delete[] human.Children;
		
		//Moifying the numberOfChildren and Children of the parents
		this->numberOfChildren++;
		this->Children = new Human*[this->numberOfChildren];
		human.numberOfChildren++;
		human.Children = new Human*[human.numberOfChildren];

		//Creating a new human with default settings!
		Human* newborn{ new Human{"NEWBORN", "BABY", 0, 0, 0, 0, 0} };
		std::cout << "A new baby has been born to " << this->firstName << " and "
			<< human.firstName << std::endl;

		//Randomly setting the gender of the newborn to either male or famale
		if (rand() % 2 == 0)
			newborn->setGender(true);
		else
			newborn->setGender(false);

		//Randomly setting the hairColor of the newborn to either father or mother's hairColor
		if (rand() % 2 == 0)
			newborn->setHairColor(human.hairColor);
		else
			newborn->setHairColor(this->hairColor);

		//Randomly setting the eyeColor of the newborn to either father or mother's eyeColor
		if (rand() % 2 == 0)
			newborn->setEyeColor(human.eyeColor);
		else
			newborn->setEyeColor(this->eyeColor);

		//Setting the lastName of the newborn to the lastName of the father
		if (this->gender == false)
			newborn->setLastName(this->lastName);
		else
			newborn->setLastName(human.lastName);

		//Figuring out mother and father and assigning them
		if (this->gender == true)
		{
			newborn->mother = this;
			newborn->father = &human;
		}
		else
		{
			newborn->mother = &human;
			newborn->father = this;
		}

		//Refeilling the Children of the parents with previous children
		for (int i{}; i < this->numberOfChildren - 1; i++) {
			this->Children[i] = H1[i];
			human.Children[i] = H2[i];
		}

		//Adding newborn to the Children of the parents
		this->Children[this->numberOfChildren - 1] = newborn;
		human.Children[human.numberOfChildren - 1] = newborn;


		H1 = nullptr;
		H2 = nullptr;

		return newborn;

	}

	//If they're not married return empty
	else
	{
		std::cout << "These two humans are not married and can not have children \n";
		return nullptr;
	}
}

void Human::operator++(int)
{
	(this->age)++;
	std::cout << "The age of " << this->firstName  << " " << this->lastName << " went up by 1\n";
}


bool Human::isChildOf(Human* human)
{
	//If we find the pointer of human inside the Children of *this return true else return false
	for (int i{}; i < human->numberOfChildren; i++)
	{
		if (this == (human->Children)[i])
		{
			std::cout << this->firstName << " is the child of " << human->firstName << std::endl;
			return true;
		}

	}

	std::cout << this->firstName << " is not the child of " << human->firstName << std::endl;
	return false;
}

bool Human::isFatherOf(Human* human)
{
	//Checks if *this is male
	if (this->gender == true)
		return false;

	else if (human->father == this)
	{
		std::cout << this->firstName << " is the father of " << human->firstName << std::endl;
		return true;
	}

	std::cout << this->firstName << " is not the father of " << human->firstName << std::endl;
	return false;
}

bool Human::isMotherOf(Human* human)
{
	//Checks if *this is female
	if (this->gender == false)
		return false;

	else if (human->mother == this)
	{
		std::cout << this->firstName << " is the father of " << human->firstName << std::endl;
		return true;
	}

	std::cout << this->firstName << " is not the mother of " << human->firstName << std::endl;
	return false;
}

void Human::printChildren()
{
	if (this->numberOfChildren == 0 || this->Children == nullptr)
		std::cout << this->firstName << " does not have any children\n";
	else
	{
		std::cout << "The children of " << this->firstName << " are\n";

		for (int i{}; i < this->numberOfChildren; i++) {
			
			std::cout << i+1 << "- " << (this->Children)[i]->firstName << " "
				<< (this->Children)[i]->lastName << "\n";
		}
	}
}

int Human::getNumberOfChildren()
{
	return (this->numberOfChildren);
}

void Human::increaseNumberOfChildren()
{
	(this->numberOfChildren)++;
}

Human::~Human()
{
	std::cout << "The destructor of the Human class is called\n";
	if (this->Children != nullptr)
		delete[] this->Children;
}

