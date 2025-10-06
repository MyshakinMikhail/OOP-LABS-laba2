#include <iostream>
#include "BitString.h"

int main()
{
	BitString a("10101");
	BitString b("11000");

	BitString c = a.And(b);
	BitString d = a.Or(b);

	std::cout << "a: " << a.ToString() << std::endl;
	std::cout << "b: " << b.ToString() << std::endl;
	std::cout << "a AND b: " << c.ToString() << std::endl;
	std::cout << "a OR b: " << d.ToString() << std::endl;

	return 0;
}
