#include "operations/Fraction.h"

int main(int argc, char *argv[])
{
	Fraction fraction_1(4, -12);
	Fraction fraction_2(4, 6);
	
	Fraction fraction = fraction_1 * 1;
	std::cout << "First Resultant Fraction = " << fraction << std::endl;

	fraction = fraction_2 * 2;
	std::cout << "Second Resultant Fraction = " << fraction << std::endl;

	fraction = fraction_1 * fraction_2;
	std::cout << "Third Resultant Fraction = " << fraction << std::endl;

	try
	{
		Fraction fraction_3(4, 0);
	}
	catch (std::runtime_error & e)
	{
		std::cerr << "Exception : " << e.what() << std::endl;

		return 1;
	}

	Fraction fraction_4;

	try
	{
		fraction_4.setdenominator(0);
	}
	catch (std::runtime_error & e)
	{
		std::cerr << "Exception : " << e.what() << std::endl;

		return 1;
	}
	
    return 0;
}