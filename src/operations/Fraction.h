#include <string>
#include <iostream>

#ifndef FRACTION_H
#define FRACTION_H

class Fraction
{
	private:
		long numerator, denominator;
	
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
		// Method:    multiply - Multiply integer and an object 3 * F1 | F1 * 3
		// FullName:  Fraction::multiply
		// Access:    private 
		// Returns:   Fraction
		// Qualifier:
		// Parameter: const int &
		// Parameter: const Fraction &
		//************************************
		Fraction multiply(const int &, const Fraction &);
		
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
		// Returns:   int
		// Qualifier:
		// Parameter: Fraction & fraction
		//************************************
		int fixSign(Fraction &);

		//************************************
		// Method:    gcd - To find greatest common divisor  (gcd(2/4) = 2)
		// FullName:  Fraction::gcd
		// Access:    private 
		// Returns:   int
		// Qualifier:
		// Parameter: int
		// Parameter: int
		//************************************
		int gcd(int, int);


		//************************************
		// Method:    isNumeratorZero - Checks if numerator is zero. If it is, sets denominator to 1. 
		// FullName:  Fraction::isNumeratorZero
		// Access:    private 
		// Returns:   bool
		// Qualifier:
		//************************************
		bool isNumeratorZero();

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
		Fraction(int _numerator, int _denominator);

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
		void setnumerator(const int);

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
		// Parameter: const int - Denominator to set in a fraction
		//************************************
		void setdenominator(const int);
		
		//************************************
		// Method:    getdenominator  To get Denominator
		// FullName:  Fraction::getdenominator
		// Access:    public 
		// Returns:   int
		// Qualifier: const
		//************************************
		long getdenominator() const;

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
		// Method:    operator* To multiply Fraction to Integer object (F1 * 3)
		// FullName:  Fraction::operator* 
		// Access:    public 
		// Returns:   Fraction
		// Qualifier:
		// Parameter: const int Integer number to multiply with
		//************************************
		Fraction operator*(const int);

		//************************************
		// Method:    operator*  To multiply integer to Fraction object (3 * F1)
		// FullName:  Fraction::operator*
		// Access:    public 
		// Returns:   friend Fraction
		// Qualifier:
		// Parameter: const int number  Integer number
		// Parameter: const Fraction & fraction  Fraction object to multiply with
		//************************************
		friend Fraction operator*(const int number, const Fraction & fraction);

		//************************************
		// Method:    operator<<
		// FullName:  Fraction::operator<<
		// Access:    public 
		// Returns:   std::ostream&
		// Qualifier:
		// Parameter: std::ostream &
		// Parameter: const Fraction &
		//************************************
		friend std::ostream & operator<<(std::ostream & os, const Fraction &);
};

#endif