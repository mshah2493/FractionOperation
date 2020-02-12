template <class T>
Fraction<T> Fraction<T>::add(const Fraction & right_fraction)
{
	T n = numerator * right_fraction.getdenominator() + denominator * right_fraction.getnumerator();
	T d = denominator * right_fraction.getdenominator();
	Fraction<T> result(n, d);

	if (!isBoundriesOkay(result, right_fraction, Add))
	{
		throw std::range_error("A value of the addition is smaller or bigger than the min-max values.");
	}

	simplify(result);

	return result;
}

template <class T>
Fraction<T> Fraction<T>::subtract(const Fraction & right_fraction)
{
	T n = numerator * right_fraction.getdenominator() - denominator * right_fraction.getnumerator();
	T d = denominator * right_fraction.getdenominator();
	Fraction<T> result(n, d);

	if (!isBoundriesOkay(result, right_fraction, Subtract))
	{
		throw std::range_error("A value of the subtraction is smaller or bigger than the min-max values.");
	}

	simplify(result);

	return result;
}

template <class T>
Fraction<T> Fraction<T>::multiply(const Fraction & right_fraction)
{
	T n = numerator * right_fraction.getnumerator();
	T d = denominator * right_fraction.getdenominator();
	Fraction<T> result(n, d);

	if (!isBoundriesOkay(result, right_fraction, Multiply))
	{
		throw std::range_error("A value of the multiplipcation is smaller or bigger than the min-max values.");
	}

	simplify(result);

	return result;
}

template <class T>
Fraction<T> Fraction<T>::divide(const Fraction & right_fraction)
{
	T n = numerator * right_fraction.getdenominator();
	T d = denominator * right_fraction.getnumerator();
	Fraction<T> result(n, d);

	if (!isBoundriesOkay(result, right_fraction, Divide))
	{
		throw std::range_error("A value of the division is smaller or bigger than the min-max values.");
	}

	simplify(result);

	return result;
}

template <class T>
bool Fraction<T>::equals(const Fraction & right_fraction, const OpEnum & op)
{
	bool result = false;

	switch(op)
	{
		case EqualsTo:
			if (numerator == right_fraction.numerator && denominator == right_fraction.denominator)
				result = true;
			break;

		case NotEqualsTo:
			if (numerator != right_fraction.numerator || denominator != right_fraction.denominator)
				result = true;
			break;
		case GreaterThan:
			if ((numerator / denominator) > (right_fraction.numerator / right_fraction.denominator))
				result = true;
			break;
		case LessThan:
			if ((numerator / denominator) < (right_fraction.numerator / right_fraction.denominator))
				result = true;
			break;
		case GreaterThanAndEqualsTo:
			if ((numerator / denominator) >= (right_fraction.numerator / right_fraction.denominator))
				result = true;
			break;
		case LessThanAndEqualsTo:
			if ((numerator / denominator) <= (right_fraction.numerator / right_fraction.denominator))
				result = true;
			break;
		default:
			break;
	}

	return result;
}

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
bool Fraction<T>::isBoundriesOkay(const Fraction & result, const Fraction & right_fraction, const OpEnum & op)
{
	bool isOkay = true;

	switch (op)
	{
		case Add:
			if (result.getnumerator() - numerator * right_fraction.getdenominator() != denominator * right_fraction.getnumerator()
				||
				result.getdenominator() / denominator != right_fraction.getdenominator()
				)
			{
				isOkay = false;
			}
			break;
		case Subtract:
			if ((result.getnumerator() + denominator * right_fraction.getnumerator()) != (numerator * right_fraction.getdenominator())
				||
				result.getdenominator() / denominator != right_fraction.getdenominator()
				)
			{
				isOkay = false;
			}
			break;
		case Multiply:
			if (result.getnumerator() / numerator != right_fraction.getnumerator()
				||
				result.getdenominator() / denominator != right_fraction.getdenominator())
			{
				isOkay = false;
			}
			break;
		case Divide:
			if (result.getnumerator() / numerator != right_fraction.getdenominator()
				|| 
				result.getdenominator() / denominator!= right_fraction.getnumerator()
				)
			{
				isOkay = false;
			}
			break;
		default:
			break;
	}

	return isOkay;
}