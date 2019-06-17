#include "Fraction.h"

#include <stdexcept>
#include <cstdlib>

Fraction::Fraction()
{
	numerator = 0;
	denominator = 0;
}

Fraction::Fraction(int _numerator, int _denominator)
{
	numerator = _numerator;
	denominator = _denominator;

	if (denominator == 0)
	{
		throw std::runtime_error("Divide by zero exception. Denominator cannot be zero.");
	}
	
	isNumeratorZero();
}

Fraction::~Fraction() { }

void Fraction::setnumerator(const int _numerator)
{
	numerator = _numerator;

	isNumeratorZero();
}

long Fraction::getnumerator() const
{
	return numerator;
}

void Fraction::setdenominator(const int _denominator)
{
	denominator = _denominator;

	if (denominator == 0)
	{
		throw std::runtime_error("Divide by zero exception. Denominator cannot be zero.");
	}

	isNumeratorZero();
}

long Fraction::getdenominator() const
{
	return denominator;
}

bool Fraction::isNumeratorZero()
{
	if (numerator == 0)
	{
		numerator = 0;
		denominator = 1;

		return true;
	}

	return false;
}

Fraction Fraction::operator*(const Fraction & fraction_2)
{
	return multiply(fraction_2);
}

Fraction Fraction::operator*(const int number)
{
	return multiply(number, *this);
}

Fraction operator*(const int number, const Fraction & fraction)
{
	Fraction temp_fraction;

	return temp_fraction.multiply(number, fraction);
}

Fraction Fraction::multiply(const Fraction & fraction_2)
{
	Fraction fraction;
	fraction.setnumerator(numerator * fraction_2.getnumerator());
	fraction.setdenominator(denominator * fraction_2.getdenominator());

	simplify(fraction);

	return fraction;
}

Fraction Fraction::multiply(const int & number, const Fraction & fraction_2)
{
	Fraction fraction;
	fraction.setnumerator(number * fraction_2.getnumerator());
	fraction.setdenominator(fraction_2.getdenominator());

	simplify(fraction);

	return fraction;
}

void Fraction::simplify(Fraction & fraction)
{
	if (fraction.getnumerator() == 0)
	{
		fraction.setdenominator(1);

		return;
	}

	int common = 0;

	int sign = fixSign(fraction);

	int num = std::abs(fraction.getnumerator());
	int den = std::abs(fraction.getdenominator());

	common = gcd(num, den);

	fraction.setnumerator(num / common * sign);
	fraction.setdenominator(den / common);
}

int Fraction::fixSign(Fraction & fraction)
{
	int sign = 1;
	int num = fraction.getnumerator();
	int den = fraction.getdenominator();

	if (num < 0)
	{
		fraction.setnumerator(num * -1);
		sign *= -1;
	}

	if (den < 0)
	{
		fraction.setdenominator(den * -1);
		sign *= -1;
	}

	return sign;
}

int Fraction::gcd(int num, int den)
{
	if (den == 0)
	{
		return num;
	}

	return gcd(den, num % den);
}

std::ostream & operator<<(std::ostream & os, const Fraction & fraction)
{
	if (fraction.getdenominator() == 1)
	{
		os << fraction.getnumerator();
	}
	else
	{
		os << fraction.getnumerator() << "/" << fraction.getdenominator();
	}

	return os;
}