#include<gtest/gtest.h>

#include "operations/Fraction.h"

struct FractionGTests : public testing::Test
{
	Fraction<int> fraction_1;
	Fraction<int> fraction_2;

	void SetUp()
	{
		fraction_1.setnumerator(1);
		fraction_2.setnumerator(3);
		fraction_1.setdenominator(2);
		fraction_2.setdenominator(4);
	}

	void TearDown()
	{ }
};

TEST_F(FractionGTests, Test_contructor)
{
	Fraction<int> fraction(1, 3);

	int expected_num = 1;
	int expected_den = 3;

	ASSERT_EQ(fraction.getnumerator(), expected_num);
	ASSERT_EQ(fraction.getdenominator(), expected_den);
}

TEST_F(FractionGTests, Test_contructor_Throw)
{	
	try 
	{
		Fraction<int> fraction(1, 0);
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
		fraction_1.setdenominator(0);
	}
	catch (std::runtime_error const & err)
	{
		EXPECT_EQ(err.what(), std::string("Divide by zero exception. Denominator cannot be zero."));
	}
}

TEST_F(FractionGTests, Test_getnumerator)
{	
	int expected_num_1 = 1;
	int expected_num_2 = 3;

	ASSERT_EQ(fraction_1.getnumerator(), expected_num_1);
	ASSERT_EQ(fraction_2.getnumerator(), expected_num_2);
}

TEST_F(FractionGTests, Test_getdenominator)
{
	int expected_den_1 = 2;
	int expected_den_2 = 4;

	ASSERT_EQ(fraction_1.getdenominator(), expected_den_1);
	ASSERT_EQ(fraction_2.getdenominator(), expected_den_2);
}

TEST_F(FractionGTests, Test_F1_Multiply_F2)
{	
	Fraction<int> fraction = fraction_1 * fraction_2;
	int resultant_num = fraction.getnumerator();
	int resultant_den = fraction.getdenominator();
	int expected_num = 3;
	int expected_den = 8;

	ASSERT_EQ(resultant_num, expected_num);
	ASSERT_EQ(resultant_den, expected_den);
}

TEST_F(FractionGTests, Test_Fraction_Multiply_Int)
{
	Fraction<int> fraction = fraction_1 * 5;
	int resultant_num = fraction.getnumerator();
	int resultant_den = fraction.getdenominator();
	int expected_num = 5;
	int expected_den = 2;

	ASSERT_EQ(resultant_num, expected_num);
	ASSERT_EQ(resultant_den, expected_den);
}

TEST_F(FractionGTests, Test_Int_Multiply_Fraction)
{
	Fraction<int> fraction = 5 * fraction_1;
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