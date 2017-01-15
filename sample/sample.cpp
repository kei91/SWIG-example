#include <iostream>
#include "sample.h"

void sample::print_infoVoid(void *a)
{
	A *b = (A*) a;
	std::cout << b->GetI() << std::endl;
}

void sample::print_info(int i)
{
	std::cout << i << std::endl;
}

void sample::print_infoA(A *a)
{
	std::cout << a->GetI() << std::endl;
}
