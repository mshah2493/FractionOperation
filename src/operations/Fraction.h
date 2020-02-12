#include <string>
#include <iostream>
#include <stdexcept>
#include <cstdlib>

#ifndef FRACTION_H
#define FRACTION_H

template <class T>
class Fraction
{
	private:
		T numerator, denominator;

		const enum OpEnum
		{
			EqualsTo,
			NotEqualsTo,
			GreaterThan,
			LessThan,
			GreaterThanAndEqualsTo,
			LessThanAndEqualsTo
		};

		//************************************
		// Method:    add - add two objects F1+F2
		// FullName:  Fraction::add
		// Access:    private 
		// Returns:   Fraction
		// Qualifier:
		// Parameter: const Fraction &
		//************************************
		Fraction add(const Fraction &);

		//************************************
		// Method:    subtract - subtract two objects F1-F2
		// FullName:  Fraction::subtract
		// Access:    private 
		// Returns:   Fraction
		// Qualifier:
		// Parameter: const Fraction &
		//************************************
		Fraction subtract(const Fraction &);

		//************************************
		// Method:    multiply - Multiply two objects F1*F2
		// FullName:  Fraction::multiply
		// Access:    private 
		// Returns:   Fraction
		// Qualifier:
		// Parameter: const Fraction &
		//************************************
		Fraction multiply(const Fraction &);

		//************************************
		// Method:    divide - divide two objects F1/F2
		// FullName:  Fraction::divide
		// Access:    private 
		// Returns:   Fraction
		// Qualifier:
		// Parameter: const Fraction &
		//************************************
		Fraction divide(const Fraction &);

		//************************************
		// Method:    equals - compare two fraction objects
		// FullName:  Fraction::equals
		// Access:    private 
		// Returns:   bool
		// Qualifier:
		// Parameter: const Fraction &
		//************************************
		bool equals(const Fraction &, const OpEnum &);
		
		//************************************
		// Method:    simplify - To simplify fraction (2/4 = 1/2)
		// FullName:  Fraction::simplify
		// Access:    private 
		// Returns:   void
		// Qualifier:
		// Parameter: Fraction &
		//************************************
		void simplify(Fraction &);

		//************************************
		// Method:    fixSign - To fix sign of integer if negative (1/-2 = -1/2)
		// FullName:  Fraction::fixSign 
		// Access:    private 
		// Returns:   T
		// Qualifier:
		// Parameter: Fraction & fraction
		//************************************
		T fixSign(Fraction &);

		//************************************
		// Method:    gcd - To find greatest common divisor  (gcd(2/4) = 2)
		// FullName:  Fraction::gcd
		// Access:    private 
		// Returns:   T
		// Qualifier:
		// Parameter: T
		// Parameter: T
		//************************************
		T gcd(T, T);


		//************************************
		// Method:    isNumeratorZero - Checks if numerator is zero. If it is, sets denominator to 1. 
		// FullName:  Fraction::isNumeratorZero
		// Access:    private 
		// Returns:   bool
		// Qualifier:
		//************************************
		bool isNumeratorZero();

		//************************************
		// Method:    isOperationOverflowed - Checks if an operation (addition/multiplication/subtraction/division) is overflowed. 
		// FullName:  Fraction::isOperationOverflowed
		// Access:    private 
		// Returns:   bool
		// Qualifier:
		// Parameter: Fraction
		//************************************
		bool isOperationOverflowed(const Fraction &, T);

	public:
		
		//************************************
		// Method:    Fraction (constructor)
		// FullName:  Fraction::Fraction
		// Access:    public 
		// Returns:   
		// Qualifier:
		//************************************
		Fraction();

		//************************************
		// Method:    Fraction Constructor of Fraction
		// FullName:  Fraction::Fraction
		// Access:    public 
		// Returns:   
		// Qualifier:
		// Parameter: int _numerator Numerator in a fraction
		// Parameter: int _denominator Denominator in a fraction 
		//************************************
		Fraction(T _numerator, T _denominator);

		//************************************
		// Method:    ~Fraction Destructor of Fraction
		// FullName:  Fraction::~Fraction
		// Access:    public 
		// Returns:   
		// Qualifier:
		//************************************
		~Fraction();

		//************************************
		// Method:    setnumerator  To set denominator
		// FullName:  Fraction::setnumerator
		// Access:    public 
		// Returns:   void
		// Qualifier:
		// Parameter: const int Numerator in a fraction
		//************************************
		void setnumerator(const T);

		//************************************
		// Method:    getnumerator To get numerator
		// FullName:  Fraction::getnumerator
		// Access:    public 
		// Returns:   int
		// Qualifier: const
		//************************************
		long getnumerator() const;
		
		//************************************
		// Method:    setdenominator To set Denominator
		// FullName:  Fraction::setdenominator
		// Access:    public 
		// Returns:   void
		// Qualifier:
		// Parameter: const T - Denominator to set in a fraction
		//************************************
		void setdenominator(const T);
		
		//************************************
		// Method:    getdenominator  To get Denominator
		// FullName:  Fraction::getdenominator
		// Access:    public 
		// Returns:   int
		// Qualifier: const
		//************************************
		long getdenominator() const;

		//************************************
		// Method:    operator+  To add two Fraction objects (F1 + F2)
		// FullName:  Fraction::operator+
		// Access:    public 
		// Returns:   Fraction
		// Qualifier:
		// Parameter: const Fraction & Fraction object to add with
		//************************************
		Fraction operator+(const Fraction &);

		//************************************
		// Method:    operator-  To subtract two Fraction objects (F1 - F2)
		// FullName:  Fraction::operator-
		// Access:    public 
		// Returns:   Fraction
		// Qualifier:
		// Parameter: const Fraction & Fraction
		//************************************
		Fraction operator-(const Fraction &);

		//************************************
		// Method:    operator*  To multiply two Fraction objects (F1 * F2)
		// FullName:  Fraction::operator*
		// Access:    public 
		// Returns:   Fraction
		// Qualifier:
		// Parameter: const Fraction & Fraction object to multiply with
		//************************************
		Fraction operator*(const Fraction &);

		//************************************
		// Method:    operator/ To divide two Fraction objects (F1 / F2)
		// FullName:  Fraction::operator/
		// Access:    public 
		// Returns:   Fraction
		// Qualifier:
		// Parameter: const Fraction & Fraction
		//************************************
		Fraction operator/(const Fraction &);

		//************************************
		// Method:    operator+ To add Fraction to Integer object (F1 + 3)
		// FullName:  Fraction::operator+ 
		// Access:    public 
		// Returns:   Fraction
		// Qualifier:
		// Parameter: const int Integer number
		//************************************
		Fraction operator+(const T);

		//************************************
		// Method:    operator- To subtract Fraction to Integer object (F1 - 3)
		// FullName:  Fraction::operator- 
		// Access:    public 
		// Returns:   Fraction
		// Qualifier:
		// Parameter: const int Integer number
		//************************************
		Fraction operator-(const T);

		//************************************
		// Method:    operator* To multiply Fraction to Integer object (F1 * 3)
		// FullName:  Fraction::operator* 
		// Access:    public 
		// Returns:   Fraction
		// Qualifier:
		// Parameter: const int Integer number to multiply with
		//************************************
		Fraction operator*(const T);

		//************************************
		// Method:    operator/ To divide Fraction to Integer object (F1 / 3)
		// FullName:  Fraction::operator/
		// Access:    public 
		// Returns:   Fraction
		// Qualifier:
		// Parameter: const int Integer number
		//************************************
		Fraction operator/(const T);

		//************************************
		// Method:    operator==  To compare Fraction objects (F1 == F2)
		// FullName:  Fraction::operator==
		// Access:    public 
		// Returns:   bool
		// Qualifier:
		// Parameter: const Fraction &
		//************************************
		bool operator==(const Fraction &);

		//************************************
		// Method:    operator==  To compare Fraction object to a number (F1 == 3)
		// FullName:  Fraction::operator==
		// Access:    public 
		// Returns:   bool
		// Qualifier:
		// Parameter: const T number
		//************************************
		bool operator==(const T);

		//************************************
		// Method:    operator!= (F1 != F2)
		// FullName:  Fraction::operator!=
		// Access:    public 
		// Returns:   bool
		// Qualifier:
		// Parameter: const Fraction &
		//************************************
		bool operator!=(const Fraction &);

		//************************************
		// Method:    operator!=  (F1 != 3)
		// FullName:  Fraction::operator!=
		// Access:    public 
		// Returns:   bool
		// Qualifier:
		// Parameter: const T number
		//************************************
		bool operator!=(const T);

		//************************************
		// Method:    operator> (F1 > F2)
		// FullName:  Fraction::operator>
		// Access:    public 
		// Returns:   bool
		// Qualifier:
		// Parameter: const Fraction &
		//************************************
		bool operator>(const Fraction&);

		//************************************
		// Method:    operator> (F1 > 3)
		// FullName:  Fraction::operator>
		// Access:    public 
		// Returns:   bool
		// Qualifier:
		// Parameter: const T number
		//************************************
		bool operator>(const T);

		//************************************
		// Method:    operator< (F1 < F2)
		// FullName:  Fraction::operator<
		// Access:    public 
		// Returns:   bool
		// Qualifier:
		// Parameter: const Fraction &
		//************************************
		bool operator<(const Fraction &);

		//************************************
		// Method:    operator< (F1 < 3)
		// FullName:  Fraction::operator<
		// Access:    public 
		// Returns:   bool
		// Qualifier:
		// Parameter: const T number
		//************************************
		bool operator<(const T);

		//************************************
		// Method:    operator>= (F1 >= F2)
		// FullName:  Fraction::operator>=
		// Access:    public 
		// Returns:   bool
		// Qualifier:
		// Parameter: const Fraction &
		//************************************
		bool operator>=(const Fraction&);

		//************************************
		// Method:    operator>= (F1 >= 3)
		// FullName:  Fraction::operator>=
		// Access:    public 
		// Returns:   bool
		// Qualifier:
		// Parameter: const T number
		//************************************
		bool operator>=(const T);

		//************************************
		// Method:    operator<= (F1 <= F2)
		// FullName:  Fraction::operator<=
		// Access:    public 
		// Returns:   bool
		// Qualifier:
		// Parameter: const Fraction &
		//************************************
		bool operator<=(const Fraction&);

		//************************************
		// Method:    operator<= (F1 <= 3)
		// FullName:  Fraction::operator<=
		// Access:    public 
		// Returns:   bool
		// Qualifier:
		// Parameter: const T number
		//************************************
		bool operator<=(const T);
		
		//************************************
		// Method:    operator+ (3 + F1)
		// FullName:  Fraction::operator+
		// Access:    public 
		// Returns:   friend Fraction
		// Qualifier:
		// Parameter: const T number
		// Parameter: const Fraction &
		//************************************
		template<typename T> friend Fraction operator+(T, const Fraction &);

		//************************************
		// Method:    operator- (3 - F1)
		// FullName:  Fraction::operator-
		// Access:    public 
		// Returns:   friend Fraction
		// Qualifier:
		// Parameter: const T number
		// Parameter: const Fraction &
		//************************************
		template<typename T> friend Fraction operator-(T, const Fraction &);

		//************************************
		// Method:    operator*  To multiply integer to Fraction object (3 * F1)
		// FullName:  Fraction::operator*
		// Access:    public 
		// Returns:   friend Fraction
		// Qualifier:
		// Parameter: const T number
		// Parameter: const Fraction &
		//************************************
		template<typename T> friend Fraction operator*(T, const Fraction &);

		//************************************
		// Method:    operator/ (3 / F1)
		// FullName:  Fraction::operator/
		// Access:    public 
		// Returns:   friend Fraction
		// Qualifier:
		// Parameter: const T number
		// Parameter: const Fraction &
		//************************************
		template<typename T> friend Fraction operator/(T, const Fraction &);

		//************************************
		// Method:    operator== (3 == F1)
		// FullName:  Fraction::operator==
		// Access:    public 
		// Returns:   friend Fraction
		// Qualifier:
		// Parameter: const T number
		// Parameter: const Fraction &
		//************************************
		template<typename T> friend Fraction operator==(T, const Fraction &);

		//************************************
		// Method:    operator!= (3 != F1)
		// FullName:  Fraction::operator!=
		// Access:    public 
		// Returns:   friend Fraction
		// Qualifier:
		// Parameter: const T number
		// Parameter: const Fraction &
		//************************************
		template<typename T> friend Fraction operator!=(T, const Fraction &);

		//************************************
		// Method:    operator< (3 < F1)
		// FullName:  Fraction::operator<
		// Access:    public 
		// Returns:   friend Fraction
		// Qualifier:
		// Parameter: const T number
		// Parameter: const Fraction &
		//************************************
		template<typename T> friend Fraction operator<(T, const Fraction &);


		//************************************
		// Method:    operator> (3 > F1)
		// FullName:  Fraction::operator>
		// Access:    public 
		// Returns:   friend Fraction
		// Qualifier:
		// Parameter: const T number
		// Parameter: const Fraction &
		//************************************
		template<typename T> friend Fraction operator>(T, const Fraction &);

		//************************************
		// Method:    operator<= (3 <= F1)
		// FullName:  Fraction::operator<=
		// Access:    public 
		// Returns:   friend Fraction
		// Qualifier:
		// Parameter: const T number
		// Parameter: const Fraction &
		//************************************
		template<typename T> friend Fraction operator<=(T, const Fraction &);

		//************************************
		// Method:    operator>= (3 >= F1)
		// FullName:  Fraction::operator>=
		// Access:    public 
		// Returns:   friend Fraction
		// Qualifier:
		// Parameter: const T number
		// Parameter: const Fraction &
		//************************************
		template<typename T> friend Fraction operator>=(T, const Fraction &);

		//************************************
		// Method:    operator<<
		// FullName:  Fraction::operator<<
		// Access:    public 
		// Returns:   std::ostream&
		// Qualifier:
		// Parameter: std::ostream &
		// Parameter: const Fraction &
		//************************************
		template<typename T> friend std::ostream & operator<<(std::ostream &, const Fraction &);
};

#endif

#include "operations/Fraction.cxx"
#include "operations/Operators-impl.cxx"