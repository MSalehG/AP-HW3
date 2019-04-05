#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include "oracle.h"
#include "human.h"

Oracle::Oracle(std::string Name) : Human{Name, "", 0, 0, 0, 0, 0}
{
	this->Name = Name;
	this->populationOfFamily = 0;
	std::cout << "A new Oracle by the name of " << Name << " was created\n";

}

Oracle::Oracle() : Oracle("NAMELESS ORACLE")
{
	std::cout << "The default constructor for the Oracle class was called \n";
}

bool Oracle::marry(Human* H1, Human* H2)
{
	//Check if they're of legal age and if they're not previously married to each other
	if ((H1->getAge() > 18) && (H2->getAge() > 18) && (H1->spouse == nullptr && H1->spouse != H2)
		&& (H2->spouse == nullptr && H2->spouse != H1)) {
		
		std::cout << H1->getFirstName() << " and " << H2->getFirstName()
			<< " can get married \n";
		H1->spouse = H2;
		H2->spouse = H1;
		return true;
	}

	std::cout << H1->getFirstName() << " and " << H2->getFirstName()
		<< " can not get married \n";
	return false;
}

bool Oracle::isFamily(Human* H1, Human* H2)
{

	//Checking if the lastName of these humans or the last name of their parents or their spouses are the same 
	if (H1->getLastName() == H2->getLastName())
	{
		std::cout << H1->getFirstName() << " " << H1->getLastName()
			<< " and " << H2->getFirstName()
			<< " " << H2->getLastName() << " are related " << std::endl;
		return true;
	}

	if ((H1->father != nullptr) && (H2->father != nullptr))
	{
		if ((H1->father)->getLastName() == (H2->father)->getLastName())
		{
			std::cout << H1->getFirstName() << " " << H1->getLastName()
				<< " and " << H2->getFirstName()
				<< " " << H2->getLastName() << " are related " << std::endl;
			return true;
		}
	}

	if ((H1->father != nullptr) && (H2->mother != nullptr))
	{
		if ((H1->father)->getLastName() == (H2->mother)->getLastName())
		{
			std::cout << H1->getFirstName() << " " << H1->getLastName()
				<< " and " << H2->getFirstName()
				<< " " << H2->getLastName() << " are related " << std::endl;
			return true;
		}
	}

	if ((H1->mother != nullptr) && (H2->father != nullptr))
	{
		if ((H1->mother)->getLastName() == (H2->father)->getLastName())
		{
			std::cout << H1->getFirstName() << " " << H1->getLastName()
				<< " and " << H2->getFirstName()
				<< " " << H2->getLastName() << " are related " << std::endl;
			return true;
		}
	}

	if ((H2->mother != nullptr) && (H2->mother != nullptr))
	{
		if ((H1->mother)->getLastName() == (H2->mother)->getLastName())
		{
			std::cout << H1->getFirstName() << " " << H1->getLastName()
				<< " and " << H2->getFirstName()
				<< " " << H2->getLastName() << " are related " << std::endl;
			return true;
		}
	}

	if ((H1->father != nullptr) && (H2->father == nullptr))
	{
		if ((H1->father)->getLastName() == H2->getLastName())
		{
			std::cout << H1->getFirstName() << " " << H1->getLastName()
				<< " and " << H2->getFirstName()
				<< " " << H2->getLastName() << " are related " << std::endl;
			return true;
		}
	}

	if ((H1->mother != nullptr) && (H2->mother == nullptr))
	{
		if ((H1->mother)->getLastName() == H2->getLastName())
		{
			std::cout << H1->getFirstName() << " " << H1->getLastName()
				<< " and " << H2->getFirstName()
				<< " " << H2->getLastName() << " are related " << std::endl;
			return true;
		}
	}

	if ((H2->father != nullptr) && (H1->father == nullptr))
	{
		if (H1->getLastName() == (H2->father)->getLastName())
		{
			std::cout << H1->getFirstName() << " " << H1->getLastName()
				<< " and " << H2->getFirstName()
				<< " " << H2->getLastName() << " are related " << std::endl;
			return true;
		}
	}

	if ((H2->mother != nullptr) && (H1->mother == nullptr))
	{
		if (H1->getLastName() == (H2->mother)->getLastName())
		{
			std::cout << H1->getFirstName() << " " << H1->getLastName()
				<< " and " << H2->getFirstName()
				<< " " << H2->getLastName() << " are related " << std::endl;
			return true;
		}
	}

	if ((H1->spouse != nullptr) && (H2->spouse != nullptr))
	{
		if ((H1->spouse)->getLastName() == (H2->spouse)->getLastName() || (H1->spouse)->getLastName() == H2->getLastName() ||
			(H1->spouse)->getLastName() == H2->getLastName())
		{
			std::cout << H1->getFirstName() << " " << H1->getLastName()
				<< " and " << H2->getFirstName()
				<< " " << H2->getLastName() << " are related " << std::endl;
			return true;
		}
	}

	if ((H1->spouse != nullptr))
	{
		if ((H1->spouse)->getLastName() == H2->getLastName())
		{
			std::cout << H1->getFirstName() << " " << H1->getLastName()
				<< " and " << H2->getFirstName()
				<< " " << H2->getLastName() << " are related " << std::endl;
			return true;
		}
	}

	if ((H2->spouse != nullptr))
	{
		if ((H2->spouse)->getLastName() == H1->getLastName())
		{
			std::cout << H1->getFirstName() << " " << H1->getLastName()
				<< " and " << H2->getFirstName()
				<< " " << H2->getLastName() << " are related " << std::endl;
			return true;
		}
	}

	if ((H1->father != nullptr) && (H1->spouse != nullptr))
	{
		if ((H1->spouse)->getLastName() == (H2->father)->getLastName())
		{
			std::cout << H1->getFirstName() << " " << H1->getLastName()
				<< " and " << H2->getFirstName()
				<< " " << H2->getLastName() << " are related " << std::endl;
			return true;
		}
	}

	std::cout << H1->getFirstName() << " " << H1->getLastName()
		<< " and " << H2->getFirstName()
		<< " " << H2->getLastName() << " are not related " << std::endl;
	return false;
}

void Oracle::setChild(Human* H1, Human* H2, Human* H3)
{

	H1->father = H3;
	H1->mother = H2;

	std::cout << H1->getFirstName() << " " << H1->getLastName()
		<< " is now the child of " << H2->getFirstName()
		<< " " << H2->getLastName() << " and " << H3->getFirstName() << " "
		<< H3->getLastName() << std::endl;

	//If they previously had children
	if (H2->Children != nullptr && H3->Children != nullptr)
	{
		Human** H4{ new Human*[H2->getNumberOfChildren()] }, **H5{ new Human*[H3->getNumberOfChildren()] };
		for (int i{}; i < H2->getNumberOfChildren(); i++) {
			H4[i] = H2->Children[i];
			H5[i] = H3->Children[i];
		}

		delete[] H2->Children;
		delete[] H3->Children;

		//Moifying the numberOfChildren and Children of the parents
		H2->increaseNumberOfChildren();
		H2->Children = new Human*[H2->getNumberOfChildren()];
		H3->increaseNumberOfChildren();
		H3->Children = new Human*[H3->getNumberOfChildren()];

		//Refilling the Children of the parents with previous children
		for (int i{}; i < H2->getNumberOfChildren() - 1; i++) {
			H2->Children[i] = H4[i];
			H3->Children[i] = H5[i];
		}

		//Adding newborn to the Children of the parents
		H2->Children[H2->getNumberOfChildren()] = H1;
		H3->Children[H3->getNumberOfChildren()] = H1;

		H2->spouse = H3;
		H3->spouse = H2;

		H4 = nullptr;
		H5 = nullptr;
	}

	//If they did not have children before
	else
	{
		//We create the array of size 1 and put the child in the Children of both of the parents
		H2->Children = new Human*;
		H3->Children = new Human*;

		H2->Children[0] = H1;
		H3->Children[0] = H1;

		H2->spouse = H3;
		H3->spouse = H2;
	}

}

Human** Oracle::getFamily(Human* human)
{
	//To keep track of the current size of the family
	int current_size{};

	//The number of the children of the human him/herself
	int selfNumOfChildren{ (*human).getNumberOfChildren() };

	//Used in the while loops to index the children
	int iter1{}, iter2{};

	//Used to make sure we do not access memory that's already NULL
	bool flag{ true };
	Human** H3{ nullptr }, **H4{ nullptr };

	if (human->spouse == nullptr)
		flag = false;

	if (human->spouse != nullptr)
	{
		H3 = new Human*[selfNumOfChildren + 1];
		H4 = new Human*[selfNumOfChildren + 1];
		current_size = selfNumOfChildren + 1;
		H3[0] = H4[0] = human->spouse;

		for (int i{ 1 }; i < selfNumOfChildren + 1; i++)
			H3[i] = H4[i] = human->Children[i - 1];
	}

	if (flag)
	{
		if ((human->spouse)->father != nullptr)
		{
			//We delete then resize H1 to accomodate the current data of family
			delete[] H3;
			int sppNumOfChildren{ (human->spouse)->father->getNumberOfChildren() };
			H3 = new Human*[current_size + sppNumOfChildren + 1];


			for (int i{}; i < current_size; i++)
				H3[i] = H4[i];

			iter1 = iter2 = 0;

			while (iter1 < sppNumOfChildren)
			{
				if (human->spouse != (human->spouse)->father->Children[iter1++])
					H3[current_size + iter2++] = (human->spouse)->father->Children[iter1 - 1];

			}

			H3[current_size + iter2++] = (human->spouse)->father;
			H3[current_size + iter2++] = (human->spouse)->mother;
			current_size += sppNumOfChildren + 1;
		}
	}

	flag = true;
	if (human->father == nullptr)
		flag = false;

	if (human->father != nullptr)
	{
		//We delete then resize H2 to accomodate the current H1 data
		delete[] H4;
		H4 = new Human*[current_size];

		for (int i{}; i < current_size; i++)
			H4[i] = H3[i];

		//We delete then resize H1 to accomodate the current data of family
		delete[] H3;
		int spNumOfChildren{ human->father->getNumberOfChildren() };
		H3 = new Human*[current_size + spNumOfChildren + 1];

		for (int i{}; i < current_size; i++)
			H3[i] = H4[i];

		iter1 = iter2 = 0;

		while (iter1 < spNumOfChildren)
		{
			if (human != human->father->Children[iter1++])
				H3[current_size + iter2++] = human->father->Children[iter1 - 1];

		}

		H3[current_size + iter2++] = human->father;
		H3[current_size + iter2++] = human->mother;
		current_size += spNumOfChildren + 1;
	}

	if (flag)
	{
		if ((human->father)->father != nullptr)
		{
			//We delete then resize H2 to accomodate the current H1 data
			delete[] H4;
			H4 = new Human*[current_size];

			for (int i{}; i < current_size; i++)
				H4[i] = H3[i];

			//We delete then resize H1 to accomodate the current data of family
			delete[] H3;
			int ppNumOfChildren{ (human->father)->father->getNumberOfChildren() };
			H3 = new Human*[current_size + ppNumOfChildren + 1];

			for (int i{}; i < current_size; i++)
				H3[i] = H4[i];

			iter1 = iter2 = 0;

			while (iter1 < ppNumOfChildren)
			{
				if (human->father != (human->father)->father->Children[iter1++])
					H3[current_size + iter2++] = (human->father)->father->Children[iter1 - 1];

			}

			H3[current_size + iter2++] = (human->father)->father;
			H3[current_size + iter2++] = (human->father)->mother;
			current_size += ppNumOfChildren + 1;
		}
	}

	flag = true;
	if (human->father == nullptr)
		flag = false;

	if (flag)
	{
		if ((human->mother)->father != nullptr)
		{
			//We delete then resize H2 to accomodate the current H1 data
			delete[] H4;
			H4 = new Human*[current_size];

			for (int i{}; i < current_size; i++)
				H4[i] = H3[i];

			//We delete then resize H1 to accomodate the current data of family
			delete[] H3;
			int ppNumOfChildren{ (human->mother)->father->getNumberOfChildren() };
			H3 = new Human*[current_size + ppNumOfChildren + 1];

			for (int i{}; i < current_size; i++)
				H3[i] = H4[i];

			iter1 = iter2 = 0;

			while (iter1 < ppNumOfChildren)
			{
				if (human->mother != (human->mother)->father->Children[iter1++])
					H3[current_size + iter2++] = (human->mother)->father->Children[iter1 - 1];

			}

			H3[current_size + iter2++] = (human->mother)->father;
			H3[current_size + iter2++] = (human->mother)->mother;
			current_size += ppNumOfChildren + 1;
		}
	}

	if (human->Children != nullptr)
	{
		//We repeat the process for all of his/her children
		for (int j{}; j < selfNumOfChildren; j++)
		{
			//We delete then resize H2 to accomodate the current H1 data
			delete[] H4;
			H4 = new Human*[current_size];

			for (int i{}; i < current_size; i++)
				H4[i] = H3[i];

			//We delete then resize H1 to accomodate the current data of family
			delete[] H3;
			int scNumOfChildren{ (human->Children[j])->getNumberOfChildren() };
			H3 = new Human*[current_size + scNumOfChildren + 1];

			for (int i{}; i < current_size; i++)
				H3[i] = H4[i];

			iter1 = iter2 = 0;

			while (iter1 < scNumOfChildren)
				H3[current_size + iter2++] = (human->Children[j])->Children[iter1++];

			H3[current_size + iter2++] = (human->Children[j])->spouse;
			current_size += scNumOfChildren + 1;
		}
	}

	this->populationOfFamily = current_size;

	if (this->populationOfFamily > 0)
	{
		delete[] H4;
		return H3;
	}


	else
	{
		delete[] H4;
		return nullptr;
	}


}

int Oracle::getPopulationOfFamily(Human* human)
{
	//Running getFamily function so that we also find the size of the family in it and store it in the populationOfFamily variable
	Human** ptemp{ this->getFamily(human) };
	delete[] ptemp;
	return this->populationOfFamily;

}

Oracle::~Oracle()
{
	std::cout << "The destructor of the Oracle calss has been called\n";
}
