#include <stdexcept>
#include <cstdlib>

template <class T>
Fraction<T>::Fraction()
{
	numerator = 0;
	denominator = 0;
}

template <class T>
Fraction<T>::Fraction(T _numerator, T _denominator)
{
	numerator = _numerator;
	denominator = _denominator;

	if (denominator == 0)
	{
		throw std::runtime_error("Divide by zero exception. Denominator cannot be zero.");
	}

	isNumeratorZero();
}

template <class T>
Fraction<T>::~Fraction() { }

template <class T>
void Fraction<T>::setnumerator(const T _numerator)
{
	numerator = _numerator;

	isNumeratorZero();
}

template <class T>
long Fraction<T>::getnumerator() const
{
	return numerator;
}

template <class T>
void Fraction<T>::setdenominator(const T _denominator)
{
	denominator = _denominator;

	if (denominator == 0)
	{
		throw std::runtime_error("Divide by zero exception. Denominator cannot be zero.");
	}

	isNumeratorZero();
}

template <class T>
long Fraction<T>::getdenominator() const
{
	return denominator;
}

template <class T>
bool Fraction<T>::isNumeratorZero()
{
	if (numerator == 0)
	{
		numerator = 0;
		denominator = 1;

		return true;
	}

	return false;
}

template <class T>
Fraction<T> Fraction<T>::operator+(const Fraction & right_fraction)
{
	return add(right_fraction);
}

template <class T>
Fraction<T> Fraction<T>::operator-(const Fraction & right_fraction)
{
	return subtract(right_fraction);
}

template <class T>
Fraction<T> Fraction<T>::operator*(const Fraction & right_fraction)
{
	return multiply(right_fraction);
}

template <class T>
Fraction<T> Fraction<T>::operator/(const Fraction & right_fraction)
{
	return divide(right_fraction);
}

template <class T>
Fraction<T> Fraction<T>::operator+(const T number)
{
	Fraction fraction(number, 1);

	return add(fraction);
}

template <class T>
Fraction<T> Fraction<T>::operator-(const T number)
{
	Fraction fraction(number, 1);

	return subtract(fraction);
}

template <class T>
Fraction<T> Fraction<T>::operator*(const T number)
{
	Fraction fraction(number, 1);

	return multiply(fraction);
}

template <class T>
Fraction<T> Fraction<T>::operator/(const T number)
{
	Fraction fraction(number, 1);

	return divide(fraction);
}

template <class T>
Fraction<T> operator*(const T number, const Fraction<T> & fraction_2)
{
	Fraction<T> fraction(number, 1);

	return fraction * fraction_2;
}

template <class T>
Fraction<T> Fraction<T>::add(const Fraction & right_fraction)
{
	Fraction result;

	if (!isOperationOverflowed(right_fraction, 1))
	{
		result.setnumerator(numerator * right_fraction.getdenominator() + denominator * right_fraction.getnumerator());
		result.setdenominator(denominator * right_fraction.getdenominator());
	}
	else
	{
		throw std::range_error("A value of the addition is smaller or bigger than the min-max values.");
	}

	simplify(result);

	return result;
}

template <class T>
Fraction<T> Fraction<T>::subtract(const Fraction & right_fraction)
{
	Fraction result;

	if (!isOperationOverflowed(right_fraction, 1))
	{
		result.setnumerator(numerator * right_fraction.getdenominator() - denominator * right_fraction.getnumerator());
		result.setdenominator(denominator * right_fraction.getdenominator());
	}
	else
	{
		throw std::range_error("A value of the subtraction is smaller or bigger than the min-max values.");
	}

	simplify(result);

	return result;
}

template <class T>
Fraction<T> Fraction<T>::multiply(const Fraction & right_fraction)
{
	Fraction result;

	if (!isOperationOverflowed(right_fraction, 1))
	{
		result.setnumerator(numerator * right_fraction.getnumerator());
		result.setdenominator(denominator * right_fraction.getdenominator());
	}
	else
	{
		throw std::range_error("A value of the multiplipcation is smaller or bigger than the min-max values.");
	}

	simplify(result);

	return result;
}

template <class T>
Fraction<T> Fraction<T>::divide(const Fraction & right_fraction)
{
	Fraction result;

	if (!isOperationOverflowed(right_fraction, 1))
	{
		result.setnumerator(numerator * right_fraction.getdenominator());
		result.setdenominator(denominator * right_fraction.getnumerator());
	}
	else
	{
		throw std::range_error("A value of the division is smaller or bigger than the min-max values.");
	}

	simplify(result);

	return result;
}

/*
template <class T>
Fraction<T> Fraction<T>::multiply(const T & number, const Fraction & fraction_2)
{
	Fraction<T> fraction;

	if (!isOperationOverflowed(fraction_2, number))
	{
		fraction.setnumerator(number * fraction_2.getnumerator());
		fraction.setdenominator(fraction_2.getdenominator());
	}
	else
	{
		throw std::range_error("A value of the multiplipcation is smaller or bigger than the min-max values.");
	}

	simplify(fraction);

	return fraction;
}
*/

template <class T>
void Fraction<T>::simplify(Fraction & fraction)
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

template <class T>
T Fraction<T>::fixSign(Fraction & fraction)
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

template <class T>
T Fraction<T>::gcd(T num, T den)
{
	if (den == 0)
	{
		return num;
	}

	return gcd(den, num % den);
}

template <class T>
bool Fraction<T>::isOperationOverflowed(const Fraction & fraction, T number)
{
	return false;
}

template <class T>
std::ostream & operator<<(std::ostream & os, const Fraction<T> & fraction)
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