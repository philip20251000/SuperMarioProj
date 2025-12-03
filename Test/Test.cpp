#include<iostream>

int main()
{
	int* x = new int[20];
	delete[] x;
	if (x == nullptr)
		std::cout << "1";


}