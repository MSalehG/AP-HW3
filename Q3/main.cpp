#include <iostream>
#include "human.h"
#include "oracle.h"

int main() {


	Human* p1{ new Human{ "ALI", "BAHADORI", 4, 3, 25, 0, 0 } };
	Human* p2{ new Human{ "BAHAR", "SHAMS", 1, 2, 22, 1, 0 } };


	Oracle o1{ "SHERVIN" };

	//married couple
	o1.marry(p1, p2);

	//creating new person
	Human* p3{ *p1 + *p2 };

	//setting the firstname of newborn
	if (p3->getGender())
		p3->setFirstName("MAHSHID");
	else
		p3->setFirstName("FARSHID");


	//increasing the age of newborn
	(*p3)++;

	p1->printChildren();

	Human* p4{ new Human{ "SHAHIN", "REZAEE", 0, 5, 58, 1, 1 } };
	Human* p5{ new Human{ "FARHAD", "BAHADORI", 0, 6, 63, 0, 1 } };


	o1.setChild(p1, p4, p5);

	if (o1.isFamily(p3, p5))
	{
		std::cout << "the population of the family of " << p4->getFirstName()
			<< " " << p4->getLastName() << " is: " << o1.getPopulationOfFamily(p4) << std::endl;
		Human** f1{ o1.getFamily(p3) };
		std::cout << "the name of each member of family: ";
		for (int i{ 0 }; i < o1.getPopulationOfFamily(p3); i++) {
			std::cout << f1[i]->getFirstName() << " ";
		}
		std::cout << std::endl;
	}


	return 0;
}
