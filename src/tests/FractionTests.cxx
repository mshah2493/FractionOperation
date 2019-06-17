#include<gtest/gtest.h>

#include "operations/Fraction.h"

struct FractionGTests : public testing::Test
{
	Fraction * fraction_1;
	Fraction * fraction_2;

	void SetUp()
	{
		fraction_1 = new Fraction();
		fraction_2 = new Fraction();
	}

	void TearDown()
	{
		delete fraction_1;
		delete fraction_2;
	}
};

TEST_F(FractionGTests, Test_contructor)
{
	fraction_1 = new Fraction(1, 3);

	int expected_num = 1;
	int expected_den = 3;

	ASSERT_EQ(fraction_1->getnumerator(), expected_num);
	ASSERT_EQ(fraction_1->getdenominator(), expected_den);
}

TEST_F(FractionGTests, Test_contructor_Throw)
{	
	try 
	{
		fraction_1 = new Fraction(1, 0);
	}
	catch (std::runtime_error const & err) 
	{
		EXPECT_EQ(err.what(), std::string("Divide by zero exception. Denominator cannot be zero."));
	}
}

TEST_F(FractionGTests, Test_setdenominator_Throw)
{
	try
	{
		fraction_1 = new Fraction();
		fraction_1->setdenominator(0);
	}
	catch (std::runtime_error const & err)
	{
		EXPECT_EQ(err.what(), std::string("Divide by zero exception. Denominator cannot be zero."));
	}
}

TEST_F(FractionGTests, Test_getnumerator)
{
	fraction_1->setnumerator(1);
	fraction_2->setnumerator(3);
	
	int expected_num_1 = 1;
	int expected_num_2 = 3;

	ASSERT_EQ(fraction_1->getnumerator(), expected_num_1);
	ASSERT_EQ(fraction_2->getnumerator(), expected_num_2);
}

TEST_F(FractionGTests, Test_getdenominator)
{
	fraction_1->setnumerator(1);
	fraction_2->setnumerator(3);
	fraction_1->setdenominator(2);
	fraction_2->setdenominator(4);

	int expected_den_1 = 2;
	int expected_den_2 = 4;

	ASSERT_EQ(fraction_1->getdenominator(), expected_den_1);
	ASSERT_EQ(fraction_2->getdenominator(), expected_den_2);
}

TEST_F(FractionGTests, Test_F1_Multiply_F2)
{
	Fraction f1;
	Fraction f2;
	f1.setnumerator(1);
	f1.setdenominator(2);
	f2.setnumerator(3);
	f2.setdenominator(4);

	Fraction fraction = f1 * f2;
	int resultant_num = fraction.getnumerator();
	int resultant_den = fraction.getdenominator();
	int expected_num = 3;
	int expected_den = 8;

	ASSERT_EQ(resultant_num, expected_num);
	ASSERT_EQ(resultant_den, expected_den);
}

TEST_F(FractionGTests, Test_Fraction_Multiply_Int)
{
	Fraction f;
	f.setnumerator(1);
	f.setdenominator(2);

	Fraction fraction = f * 5;
	int resultant_num = fraction.getnumerator();
	int resultant_den = fraction.getdenominator();
	int expected_num = 5;
	int expected_den = 2;

	ASSERT_EQ(resultant_num, expected_num);
	ASSERT_EQ(resultant_den, expected_den);
}

TEST_F(FractionGTests, Test_Int_Multiply_Fraction)
{
	Fraction f;
	f.setnumerator(1);
	f.setdenominator(2);

	Fraction fraction = 5 * f;
	int resultant_num = fraction.getnumerator();
	int resultant_den = fraction.getdenominator();
	int expected_num = 5;
	int expected_den = 2;

	ASSERT_EQ(resultant_num, expected_num);
	ASSERT_EQ(resultant_den, expected_den);
}

int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	
	int ret = RUN_ALL_TESTS();

	return ret;
}