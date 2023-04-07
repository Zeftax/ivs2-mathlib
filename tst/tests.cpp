/*!
	\file tests.cpp
	\brief A collection of test for the math functions.
	\author Zdenek Borovec
	\author Tomas Krejci
	\author Jan Lozrt
	\author Jakub Mitrenga
	\copyright GNU GPLv3
*/

#include <stdexcept>

#include "gtest/gtest.h"
#include "ivs-math.hpp"

TEST(AddTest, BasicTests)
{
	ASSERT_EQ(add(0, 0), 0);

	ASSERT_EQ(add(0, 1), 1);
	ASSERT_EQ(add(1, 0), 1);

	ASSERT_EQ(add(0, -1), -1);
	ASSERT_EQ(add(-1, 0), -1);

	ASSERT_EQ(add(5, 10), 15);
	ASSERT_EQ(add(-10, -5), -15);

	ASSERT_EQ(add(7, 3.5), 10.5);
	ASSERT_EQ(add(-45.5, 5), -40.5);
	ASSERT_EQ(add(-12.5, -3.1), -15.6);

	ASSERT_NE(add(1, 10.23456), 11);
	ASSERT_NE(add(-10, -10), 10);
	ASSERT_NE(add(-15, -15), -15);
};

TEST(SubtractTest, BasicTests)
{
	ASSERT_EQ(subtract(0, 0), 0);

	ASSERT_EQ(subtract(0, 1), -1);
	ASSERT_EQ(subtract(1, 0), 1);

	ASSERT_EQ(subtract(0, -1), 1);
	ASSERT_EQ(subtract(-1, 0), -1);

	ASSERT_EQ(subtract(5, 10), -5);
	ASSERT_EQ(subtract(-10, -5), -5);

	ASSERT_EQ(subtract(7, 3.5), 3.5);
	ASSERT_EQ(subtract(-45.5, 5), -50.5);
	ASSERT_EQ(subtract(-12.5, -3.1), -9.4);

	ASSERT_NE(subtract(1, 10.23456), 9);
	ASSERT_NE(subtract(-10, -10), 10);
	ASSERT_NE(subtract(-15, -15), -15);
};

TEST(MultiplyTest, BasicTests)
{
	ASSERT_EQ(multiply(0, 0), 0);

	ASSERT_EQ(multiply(0, 1), 0);
	ASSERT_EQ(multiply(1, 0), 0);

	ASSERT_EQ(multiply(0, -1), 0);
	ASSERT_EQ(multiply(-1, 0), 0);

	ASSERT_EQ(multiply(5, 10), 50);
	ASSERT_EQ(multiply(7, 3.5), 24.5);

	ASSERT_EQ(multiply(-45.5, 5), -227.5);
	ASSERT_EQ(multiply(-12.5, -3.1), 38.75);
};

TEST(DivideTest, BasicTests)
{
	ASSERT_EQ(divide(0, 1), 0);

	ASSERT_EQ(divide(0, -1), 0);

	ASSERT_EQ(divide(5, 10), 0.5);
	ASSERT_EQ(divide(7, 3.5), 2);

	ASSERT_EQ(divide(-45, 5), -9);
	ASSERT_EQ(divide(-45, -5), 9);
};

TEST(DivideTest, DivideByZero)
{
	bool caught = false;
	try
	{
		divide(0, 0);
	}
	catch (std::invalid_argument const &e)
	{
		caught = true;
	}
	ASSERT_TRUE(caught);

	caught = false;
	try
	{
		divide(1, 0);
	}
	catch (std::invalid_argument const &e)
	{
		caught = true;
	}
	ASSERT_TRUE(caught);

	caught = false;
	try
	{
		divide(-1, 0);
	}
	catch (std::invalid_argument const &e)
	{
		caught = true;
	}
	ASSERT_TRUE(caught);

	caught = false;
	try
	{
		divide(1, 0.0000000001);
	}
	catch (std::invalid_argument const &e)
	{
		caught = true;
	}
	ASSERT_FALSE(caught);
};

TEST(ExponentiateTest, BasicTest)
{
	ASSERT_EQ(exponentiate(1, 0), 1);
	ASSERT_EQ(exponentiate(1, 10), 1);
	ASSERT_EQ(exponentiate(-1, 10), 1);
	ASSERT_EQ(exponentiate(-1, 9), -1);
	ASSERT_EQ(exponentiate(0, 10), 0);
	ASSERT_EQ(exponentiate(12, 0), 1);
	ASSERT_EQ(exponentiate(-5, 2), 25);
	ASSERT_EQ(exponentiate(-5, 3), -125);
	ASSERT_EQ(exponentiate(2, -2), 0.25);
	ASSERT_EQ(exponentiate(-2, 20), 1048576);
	ASSERT_EQ(exponentiate(7.35, -88), 5.844053197e-77);
	ASSERT_EQ(exponentiate(7.35, 0.88), 5.785392902);
	ASSERT_EQ(exponentiate(7.35, -0.88), 0.1728491076);
};

TEST(ExponentiateTest, NotANumber)
{
	bool caught = false;
	try
	{
		exponentiate(0, -2);
	}
	catch (std::invalid_argument const &e)
	{
		caught = true;
	}
	ASSERT_TRUE(caught);

	caught = false;
	try
	{
		exponentiate(-2, 3.5);
	}
	catch (std::invalid_argument const &e)
	{
		caught = true;
	}
	ASSERT_TRUE(caught);

	caught = false;
	try
	{
		exponentiate(-2.123, -4.6);
	}
	catch (std::invalid_argument const &e)
	{
		caught = true;
	}
	ASSERT_TRUE(caught);
};

TEST(RootTest, BasicTests)
{
	ASSERT_EQ(root(0, 10), 0);
	ASSERT_EQ(root(0, 0.5), 0);
	ASSERT_EQ(root(4, 2), 2);
	ASSERT_EQ(root(4, -2), 0.5);
	ASSERT_EQ(root(7, 3.5), 1.743639034);
	ASSERT_EQ(root(-45.5, 5), -2.145864422);
	ASSERT_EQ(root(45.545, 5), 2.146288711);
	ASSERT_EQ(root(12.5, -3.234), 0.4579514249);
	ASSERT_EQ(root(0.25, 0.02), 7.888609052e-31);
};

TEST(RootTest, NotANumber)
{
	bool caught = false;
	try
	{
		root(0, -2);
	}
	catch (std::invalid_argument const &e)
	{
		caught = true;
	}
	ASSERT_TRUE(caught);

	caught = false;
	try
	{
		root(-2, 4);
	}
	catch (std::invalid_argument const &e)
	{
		caught = true;
	}
	ASSERT_TRUE(caught);

	caught = false;
	try
	{
		root(-2, -4);
	}
	catch (std::invalid_argument const &e)
	{
		caught = true;
	}
	ASSERT_TRUE(caught);

	// caught = false;
	// try
	// {
	// 	root(-2.1, -4.2);
	// }
	// catch (std::invalid_argument const& e)
	// {
	// 	caught = true;
	// }
	// ASSERT_TRUE(caught);
};

TEST(RootTest, DivideByZero)
{
	bool caught = false;
	try
	{
		root(3, 0);
	}
	catch (std::invalid_argument const &e)
	{
		caught = true;
	}
	ASSERT_TRUE(caught);

	caught = false;
	try
	{
		root(5.454, 0);
	}
	catch (std::invalid_argument const &e)
	{
		caught = true;
	}
	ASSERT_TRUE(caught);
};

TEST(LogTest, BasicTest){
	// LOG
};

// NEFUNGUJE
TEST(LogTest, NotANumber)
{
	bool caught = false;
	try
	{
		log(0, 3);
	}
	catch (std::invalid_argument const &e)
	{
		caught = true;
	}
	ASSERT_TRUE(caught);

	caught = false;
	try
	{
		log(-1, 2);
	}
	catch (std::invalid_argument const &e)
	{
		caught = true;
	}
	ASSERT_TRUE(caught);

	caught = false;
	try
	{
		log(0.2, 0);
	}
	catch (std::invalid_argument const &e)
	{
		caught = true;
	}
	ASSERT_TRUE(caught);

	caught = false;
	try
	{
		log(10, 1);
	}
	catch (std::invalid_argument const &e)
	{
		caught = true;
	}
	ASSERT_TRUE(caught);
};

TEST(FactorialTest, BasicTests)
{
	ASSERT_EQ(factorial(0), 1);
	ASSERT_EQ(factorial(3), 6);
	ASSERT_EQ(factorial(20), 2.432902008e18);
};

TEST(FactorialTest, OutOfRange)
{
	bool caught = false;
	try
	{
		factorial(-10);
	}
	catch (std::invalid_argument const &e)
	{
		caught = true;
	}
	ASSERT_TRUE(caught);

	caught = false;
	try
	{
		factorial(-15.25);
	}
	catch (std::invalid_argument const &e)
	{
		caught = true;
	}
	ASSERT_TRUE(caught);

	// caught = false;
	// try
	// {
	// 	factorial(atan(1) * 4); // pi ? chtelo by to math knihovnu
	// }
	// catch (std::invalid_argument const &e)
	// {
	// 	caught = true;
	// }
	// ASSERT_TRUE(caught);
}
