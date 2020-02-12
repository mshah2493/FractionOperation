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
bool Fraction<T>::operator==(const Fraction<T> & fraction)
{
	return equals(fraction, EqualsTo);
}

template <class T>
bool Fraction<T>::operator==(const T number)
{
	Fraction<T> fraction(number, 1);

	return equals(fraction, EqualsTo);
}

template <class T>
bool Fraction<T>::operator!=(const Fraction<T> & fraction)
{
	return equals(fraction, NotEqualsTo);
}

template <class T>
bool Fraction<T>::operator!=(const T number)
{
	Fraction<T> fraction(number, 1);

	return equals(fraction, NotEqualsTo);
}

template <class T>
bool Fraction<T>::operator>(const Fraction<T> & fraction)
{
	return equals(fraction, GreaterThan);
}

template <class T>
bool Fraction<T>::operator>(const T number)
{
	Fraction<T> fraction(number, 1);

	return equals(fraction, GreaterThan);
}

template <class T>
bool Fraction<T>::operator<(const Fraction<T> & fraction)
{
	return equals(fraction, LessThan);
}

template <class T>
bool Fraction<T>::operator<(const T number)
{
	Fraction<T> fraction(number, 1);

	return equals(fraction, LessThan);
}

template <class T>
bool Fraction<T>::operator>=(const Fraction<T> & fraction)
{
	return equals(fraction, GreaterThanAndEqualsTo);
}

template <class T>
bool Fraction<T>::operator>=(const T number)
{
	Fraction<T> fraction(number, 1);

	return equals(fraction, GreaterThanAndEqualsTo);
}

template <class T>
bool Fraction<T>::operator<=(const Fraction<T> & fraction)
{
	return equals(fraction, LessThanAndEqualsTo);
}

template <class T>
bool Fraction<T>::operator<=(const T number)
{
	Fraction<T> fraction(number, 1);

	return equals(fraction, LessThanAndEqualsTo);
}

template <class T>
Fraction<T> operator*(const T number, const Fraction<T> & fraction_2)
{
	Fraction<T> fraction(number, 1);

	return fraction * fraction_2;
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