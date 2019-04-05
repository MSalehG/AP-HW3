#include <iostream>
#include "vec.h"
#include <stdlib.h>
#include <time.h>


int main()
{
	srand((unsigned)time(NULL));

	//These three array are created for the purpose of experimentaion
	Vec v1{}, v2{}, v3{};

	int cnt{ static_cast<int>(rand() % 5 + 1 )};

	for (int i{}; i < cnt + 1; i++)
		v1.push_back(rand() % 10 );
	v1.show();

	cnt = static_cast<int>(rand() % 7 + 1);

	for (int i{}; i < cnt + 1; i++)
		v2.push_back(rand() % 10);
	v2.show();

	cnt = static_cast<int>(rand() % 7 + 1);

	for (int i{}; i < cnt + 1; i++)
		v3.push_back(rand() % 10);
	v3.show();

	Vec v4{ v1 + v2 }, v5{ v3*v2 };

	std::cout << "The result of the addition of v1 and v2 is stored in v4 and is equal to\n";
	v4.show();

	std::cout << "The result of the multiplication of v3 and v2 is stored in v5 and is equal to\n";
	v5.show();

	if (v1 > v3)
		std::cout << "The size of v1 is bigger than the size of v3\n";

	else if (v1 == v3)
		std::cout << "The size of v1 is equal to the size of v3\n";

	else
		std::cout << "The size of v1 is smaller than the size of v3\n";

	if (v4 > v5)
		std::cout << "The size of v4 is bigger than the size of v5\n";

	else if (v4 == v5)
		std::cout << "The size of v4 is equal to the size of v5\n";

	else
		std::cout << "The size of v4 is smaller than the size of v5\n";



}



