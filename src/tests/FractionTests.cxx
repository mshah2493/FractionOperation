#include<gtest/gtest.h>

#include "operations/Fraction.h"

struct FractionGTests : public testing::Test
{
	std::shared_ptr<Fraction<int>> fraction_1;
	std::shared_ptr<Fraction<int>> fraction_2;

	void SetUp()
	{
		fraction_1 = std::make_shared<Fraction<int>>();
		fraction_2 = std::make_shared<Fraction<int>>();

		fraction_1->setnumerator(1);
		fraction_2->setnumerator(3);
		fraction_1->setdenominator(2);
		fraction_2->setdenominator(4);
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
		fraction_1->setdenominator(0);
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

	ASSERT_EQ(fraction_1->getnumerator(), expected_num_1);
	ASSERT_EQ(fraction_2->getnumerator(), expected_num_2);
}

TEST_F(FractionGTests, Test_getdenominator)
{
	int expected_den_1 = 2;
	int expected_den_2 = 4;

	ASSERT_EQ(fraction_1->getdenominator(), expected_den_1);
	ASSERT_EQ(fraction_2->getdenominator(), expected_den_2);
}

TEST_F(FractionGTests, Test_F1_Add_F2)
{
	Fraction<int> fraction = *fraction_1.get() + *fraction_2.get();
	int resultant_num = fraction.getnumerator();
	int resultant_den = fraction.getdenominator();
	int expected_num = 5;
	int expected_den = 4;

	ASSERT_EQ(resultant_num, expected_num);
	ASSERT_EQ(resultant_den, expected_den);
}

TEST_F(FractionGTests, Test_F1_Add_Number)
{
	Fraction<int> fraction = *fraction_1.get() + 1;
	int resultant_num = fraction.getnumerator();
	int resultant_den = fraction.getdenominator();
	int expected_num = 3;
	int expected_den = 2;

	ASSERT_EQ(resultant_num, expected_num);
	ASSERT_EQ(resultant_den, expected_den);
}

TEST_F(FractionGTests, Test_Number_Add_F1)
{
	Fraction<int> fraction = 1 + *fraction_1.get();
	int resultant_num = fraction.getnumerator();
	int resultant_den = fraction.getdenominator();
	int expected_num = 3;
	int expected_den = 2;

	ASSERT_EQ(resultant_num, expected_num);
	ASSERT_EQ(resultant_den, expected_den);
}

TEST_F(FractionGTests, Test_F1_Subtract_F2)
{
	Fraction<int> fraction = *fraction_1.get() - *fraction_2.get();
	int resultant_num = fraction.getnumerator();
	int resultant_den = fraction.getdenominator();
	int expected_num = -1;
	int expected_den = 4;

	ASSERT_EQ(resultant_num, expected_num);
	ASSERT_EQ(resultant_den, expected_den);
}

TEST_F(FractionGTests, Test_F1_Subtract_Number)
{
	Fraction<int> fraction = *fraction_1.get() - 1;
	int resultant_num = fraction.getnumerator();
	int resultant_den = fraction.getdenominator();
	int expected_num = -1;
	int expected_den = 2;

	ASSERT_EQ(resultant_num, expected_num);
	ASSERT_EQ(resultant_den, expected_den);
}

TEST_F(FractionGTests, Test_Number_Subtract_F1)
{
	Fraction<int> fraction = 1 - *fraction_1.get();
	int resultant_num = fraction.getnumerator();
	int resultant_den = fraction.getdenominator();
	int expected_num = 1;
	int expected_den = 2;

	ASSERT_EQ(resultant_num, expected_num);
	ASSERT_EQ(resultant_den, expected_den);
}

TEST_F(FractionGTests, Test_F1_Multiply_F2)
{	
	Fraction<int> fraction = *fraction_1.get() * *fraction_2.get();
	int resultant_num = fraction.getnumerator();
	int resultant_den = fraction.getdenominator();
	int expected_num = 3;
	int expected_den = 8;

	ASSERT_EQ(resultant_num, expected_num);
	ASSERT_EQ(resultant_den, expected_den);
}

TEST_F(FractionGTests, Test_Fraction_Multiply_Number)
{
	Fraction<int> fraction = *fraction_1.get() * 5;
	int resultant_num = fraction.getnumerator();
	int resultant_den = fraction.getdenominator();
	int expected_num = 5;
	int expected_den = 2;

	ASSERT_EQ(resultant_num, expected_num);
	ASSERT_EQ(resultant_den, expected_den);
}

TEST_F(FractionGTests, Test_Number_Multiply_Fraction)
{
	Fraction<int> fraction = 5 * *fraction_1.get();
	int resultant_num = fraction.getnumerator();
	int resultant_den = fraction.getdenominator();
	int expected_num = 5;
	int expected_den = 2;

	ASSERT_EQ(resultant_num, expected_num);
	ASSERT_EQ(resultant_den, expected_den);
}

TEST_F(FractionGTests, Test_F1_Divide_F2)
{
	Fraction<int> fraction = *fraction_1.get() / *fraction_2.get();
	int resultant_num = fraction.getnumerator();
	int resultant_den = fraction.getdenominator();
	int expected_num = 2;
	int expected_den = 3;

	ASSERT_EQ(resultant_num, expected_num);
	ASSERT_EQ(resultant_den, expected_den);
}

TEST_F(FractionGTests, Test_F1_Divide_Number)
{
	Fraction<int> fraction = *fraction_1.get() / 2;
	int resultant_num = fraction.getnumerator();
	int resultant_den = fraction.getdenominator();
	int expected_num = 1;
	int expected_den = 4;

	ASSERT_EQ(resultant_num, expected_num);
	ASSERT_EQ(resultant_den, expected_den);
}

TEST_F(FractionGTests, Test_Number_Divide_F1)
{
	Fraction<int> fraction = 1 / *fraction_1.get();
	int resultant_num = fraction.getnumerator();
	int resultant_den = fraction.getdenominator();
	int expected_num = 2;
	int expected_den = 1;

	ASSERT_EQ(resultant_num, expected_num);
	ASSERT_EQ(resultant_den, expected_den);
}

TEST_F(FractionGTests, Test_F1_Equals_F2)
{
	fraction_2->setnumerator(1);
	fraction_2->setdenominator(2);
	ASSERT_TRUE(*fraction_1.get() == *fraction_2.get());
}

TEST_F(FractionGTests, Test_F1_Equals_Number)
{
	ASSERT_FALSE(*fraction_1.get() == 3);
}

TEST_F(FractionGTests, Test_Number_Equals_F1)
{
	ASSERT_FALSE(3 == *fraction_1.get());
}

TEST_F(FractionGTests, Test_F1_NotEquals_F2)
{
	ASSERT_TRUE(*fraction_1.get() != *fraction_2.get());
}

TEST_F(FractionGTests, Test_F1_NotEquals_Number)
{
	ASSERT_TRUE(*fraction_1.get() != 3);
}

TEST_F(FractionGTests, Test_Number_NotEquals_F1)
{
	ASSERT_TRUE(3 != *fraction_1.get());
}

TEST_F(FractionGTests, Test_F1_LT_F2)
{
	ASSERT_FALSE(*fraction_1.get() < *fraction_2.get());
}

TEST_F(FractionGTests, Test_F1_LT_Number)
{
	ASSERT_TRUE(*fraction_1.get() < 3);
}

TEST_F(FractionGTests, Test_Number_LT_F1)
{
	ASSERT_FALSE(3 < *fraction_1.get());
}

TEST_F(FractionGTests, Test_F1_GT_F2)
{
	ASSERT_FALSE(*fraction_1.get() > *fraction_2.get());
}

TEST_F(FractionGTests, Test_F1_GT_Number)
{
	ASSERT_FALSE(*fraction_1.get() > 3);
}

TEST_F(FractionGTests, Test_Number_GT_F1)
{
	ASSERT_TRUE(3 > *fraction_1.get());
}

TEST_F(FractionGTests, Test_F1_GTE_F2)
{
	ASSERT_TRUE(*fraction_1.get() >= *fraction_2.get());
}

TEST_F(FractionGTests, Test_F1_GTE_Number)
{
	ASSERT_FALSE(*fraction_1.get() >= 3);
}

TEST_F(FractionGTests, Test_Number_GTE_F1)
{
	ASSERT_TRUE(3 >= *fraction_1.get());
}

TEST_F(FractionGTests, Test_F1_LTE_F2)
{
	ASSERT_TRUE(*fraction_1.get() <= *fraction_2.get());
}

TEST_F(FractionGTests, Test_F1_LTE_Number)
{
	ASSERT_TRUE(*fraction_1.get() <= 3);
}

TEST_F(FractionGTests, Test_Number_LTE_F1)
{
	ASSERT_FALSE(3 <= *fraction_1.get());
}

int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	
	int ret = RUN_ALL_TESTS();

	return ret;
}