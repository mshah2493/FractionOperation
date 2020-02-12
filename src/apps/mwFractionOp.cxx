#include "operations/Fraction.h"

int main(int argc, char *argv[])
{
	Fraction<int> fraction_1(4, -12);
	Fraction<int> fraction_2(4, 6);
	Fraction<int> fraction_3(4, -12);
	Fraction<int> fraction_4(4, 7);
	Fraction<int> fraction;

	fraction = fraction_1 + fraction_2;
	std::cout << "F1 + F2 = " << fraction << std::endl;

	fraction = fraction_1 + 1;
	std::cout << "F + NUMBER = " << fraction << std::endl;

	fraction = fraction_1 - fraction_2;
	std::cout << "F1 - F2 = " << fraction << std::endl;

	fraction = fraction_1 * 10;
	std::cout << "F1 * NUMBER = " << fraction << std::endl;

	fraction = fraction_1 * fraction_2;
	std::cout << "F1 * F2 = " << fraction << std::endl;

	fraction = 10 * fraction_2;
	std::cout << "NUMBER * F2 = " << fraction << std::endl;

	fraction = fraction_1 / fraction_2;
	std::cout << "F1 / F2 = " << fraction << std::endl;

	std::cout << "F1 == F3 = " << (fraction_1 == fraction_3) << std::endl;

	std::cout << "F1 != F3 = " << (fraction_1 != fraction_3) << std::endl;

	std::cout << "F2 == F4 = " << (fraction_2 == fraction_4) << std::endl;

	std::cout << "F2 != F4 = " << (fraction_2 != fraction_4) << std::endl;

	std::cout << "F1 > F3 = " << (fraction_1 > fraction_3) << std::endl;

	std::cout << "F1 < F3 = " << (fraction_1 < fraction_3) << std::endl;

	std::cout << "F2 >= F4 = " << (fraction_2 >= fraction_4) << std::endl;

	std::cout << "F2 <= F4 = " << (fraction_2 <= fraction_4) << std::endl;

	try
	{
		Fraction f(4, 0);
	}
	catch (std::runtime_error & e)
	{
		std::cerr << "Exception : " << e.what() << std::endl;

		return 1;
	}

	try
	{
		fraction_1.setdenominator(0);
	}
	catch (std::runtime_error & e)
	{
		std::cerr << "Exception : " << e.what() << std::endl;

		return 1;
	}
	
    return 0;
}