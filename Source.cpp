#include "VectorCpp.h"

int main()
{
	std::initializer_list<int> a = { 1,2,3 };
	std::initializer_list<int> b = { 4,4,4 };
	try
	{
		Vector<int, 3> vec(a);
		std::cout <<"1. vektor: "<< vec<<std::endl;
		Vector<int, 3> pom(b);
		std::cout <<"2. vektor: "<< pom<<std::endl;
		Vector<int, 3> zbir(b);
		zbir = pom + vec;
		std::cout << "Zbir: " << zbir << std::endl;
	}
	catch (std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
	}
	
	getchar();
	getchar();
}