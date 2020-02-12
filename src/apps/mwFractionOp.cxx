#include "operations/Fraction.h"

int main(int argc, char *argv[])
{
	Fraction<int> fraction_1(4, -12);
	Fraction<int> fraction_2(4, 6);
	Fraction<int> fraction_3(4, -12);
	Fraction<int> fraction_4(4, 7);

	std::cout << "F1 + F2 = " << fraction_1 + fraction_2 << std::endl;
	std::cout << "F1 + NUMBER = " << fraction_1 + 10 << std::endl;
	std::cout << "NUMBER + F1 = " << 10 + fraction_1 << std::endl;

	std::cout << "------------------------------------------------------------------" << std::endl;

	std::cout << "F1 - F2 = " << fraction_1 - fraction_2 << std::endl;
	std::cout << "F1 - NUMBER = " << fraction_1 - 10 << std::endl;
	std::cout << "NUMBER - F1 = " << 10 - fraction_1 << std::endl;

	std::cout << "------------------------------------------------------------------" << std::endl;

	std::cout << "F1 * F2 = " << fraction_1 * fraction_2 << std::endl;
	std::cout << "F1 * NUMBER = " << fraction_1 * 10 << std::endl;
	std::cout << "NUMBER * F1 = " << 10 * fraction_1 << std::endl;

	std::cout << "------------------------------------------------------------------" << std::endl;

	std::cout << "F1 / F2 = " << fraction_1 / fraction_2 << std::endl;
	std::cout << "F1 / NUMBER = " << fraction_1 / 10 << std::endl;
	std::cout << "NUMBER / F1 = " << 10 / fraction_1 << std::endl;

	std::cout << "------------------------------------------------------------------" << std::endl;

	std::cout << "F1 == F3 = " << std::boolalpha << (fraction_1 == fraction_3) << std::endl;
	std::cout << "F1 == NUMBER = " << std::boolalpha << (fraction_1 == 10) << std::endl;
	std::cout << "NUMBER == F3 = " << std::boolalpha << (10 == fraction_3) << std::endl;

	std::cout << "------------------------------------------------------------------" << std::endl;

	std::cout << "F1 != F3 = " << std::boolalpha << (fraction_1 != fraction_3) << std::endl;
	std::cout << "F1 != NUMBER = " << std::boolalpha << (fraction_1 != 10) << std::endl;
	std::cout << "NUMBER != F3 = " << std::boolalpha << (10 != fraction_3) << std::endl;

	std::cout << "------------------------------------------------------------------" << std::endl;

	std::cout << "F2 == F4 = " << std::boolalpha << (fraction_2 == fraction_4) << std::endl;
	std::cout << "F2 == NUMBER = " << std::boolalpha << (fraction_2 == 10) << std::endl;
	std::cout << "NUMBER == F4 = " << std::boolalpha << (10 == fraction_4) << std::endl;

	std::cout << "------------------------------------------------------------------" << std::endl;

	std::cout << "F2 != F4 = " << std::boolalpha << (fraction_2 != fraction_4) << std::endl;
	std::cout << "F2 != NUMBER = " << std::boolalpha << (fraction_2 != 10) << std::endl;
	std::cout << "NUMBER != F4 = " << std::boolalpha << (10 != fraction_4) << std::endl;

	std::cout << "------------------------------------------------------------------" << std::endl;

	std::cout << "F1 > F3 = " << std::boolalpha << (fraction_1 > fraction_3) << std::endl;
	std::cout << "F1 > NUMBER = " << std::boolalpha << (fraction_1 > 10) << std::endl;
	std::cout << "NUMBER > F3 = " << std::boolalpha << (10 > fraction_3) << std::endl;

	std::cout << "------------------------------------------------------------------" << std::endl;

	std::cout << "F1 < F3 = " << std::boolalpha << (fraction_1 < fraction_3) << std::endl;
	std::cout << "F1 < NUMBER = " << std::boolalpha << (fraction_1 < 10) << std::endl;
	std::cout << "NUMBER < F3 = " << std::boolalpha << (10 < fraction_3) << std::endl;

	std::cout << "------------------------------------------------------------------" << std::endl;

	std::cout << "F2 >= F4 = " << std::boolalpha << (fraction_2 >= fraction_4) << std::endl;
	std::cout << "F2 >= NUMBER = " << std::boolalpha << (fraction_2 >= 10) << std::endl;
	std::cout << "NUMBER >= F4 = " << std::boolalpha << (10 >= fraction_4) << std::endl;

	std::cout << "------------------------------------------------------------------" << std::endl;

	std::cout << "F2 <= F4 = " << std::boolalpha << (fraction_2 <= fraction_4) << std::endl;
	std::cout << "F2 <= F4 = " << std::boolalpha << (fraction_2 <= 10) << std::endl;
	std::cout << "F2 <= F4 = " << std::boolalpha << (10 <= fraction_4) << std::endl;

	std::cout << "------------------------------------------------------------------" << std::endl;

	try
	{
		Fraction f(4, 0);
	}
	catch (std::runtime_error & e)
	{
		std::cerr << "Exception : " << e.what() << std::endl;

		return 1;
	}

	std::cout << "------------------------------------------------------------------" << std::endl;

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