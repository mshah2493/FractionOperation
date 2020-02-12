This C++ project contains implementations of the interface - Fraction. The interface comprises the following operations

• Add - F1+F2/F1+10/10+F1
• Subtract - F1-F2/F1-10/10-F1
• Multiply - F1*F2/F1*10/10*F1
• Divide - F1/F2/F1/10/10/F1
• EqualsTo - F1==F2/F1==10/10==F1
• NotEqualsTo - F1!=F2/F1!=10/10!=F1
• LessThan - F1<F2/F1<10/10<F1
• GreaterThan - F1>F2/F1>10/10>F1
• LessThanOrEqualsTo - F1<=F2/F1<=10/10<=F1
• GreaterThanOrEqualsTo - F1>=F2/F1>=10/10>=F1
• Display - displays a fraction object

Note: 

• A template (generic) type have been used to implement the fraction class and overloaded all the possible operators.

Google tests (C++) are written for unit tests.

• Test_contructor
• Test_contructor_Throw
• Test_setdenominator_Throw
• Test_Overflow_Throw
• Test_Overflow_Throw_Message
• Test_getnumerator
• Test_getdenominator
• Test_F1_Add_F2
• Test_F1_Add_Number
• Test_Number_Add_F1
• Test_F1_Subtract_F2
• Test_F1_Subtract_Number
• Test_Number_Subtract_F1
• Test_F1_Multiply_F2
• Test_Fraction_Multiply_Number
• Test_Number_Multiply_Fraction
• Test_F1_Divide_F2
• Test_F1_Divide_Number
• Test_Number_Divide_F1
• Test_F1_Equals_F2
• Test_F1_Equals_Number
• Test_Number_Equals_F1
• Test_F1_NotEquals_F2)
• Test_F1_NotEquals_Number
• Test_Number_NotEquals_F1
• Test_F1_LT_F2
• Test_F1_LT_Number
• Test_Number_LT_F1
• Test_F1_GT_F2
• Test_F1_GT_Number
• Test_Number_GT_F1
• Test_F1_GTE_F2
• Test_F1_GTE_Number
• Test_Number_GTE_F1
• Test_F1_LTE_F2
• Test_F1_LTE_Number
• Test_Number_LTE_F1

For compilation process, I have used CMake for the compilation process as it is a cross-platform tool. 
There are multiple CMakeLists.txt included in the project to process different packages. 