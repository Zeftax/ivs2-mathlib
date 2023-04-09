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
#include <cmath>

#include "gtest/gtest.h"
#include "ivs-math.hpp"

TEST(AddTest, BasicTests)
{
	EXPECT_EQ(0, add(0, 0));

	EXPECT_EQ(1, add(0, 1));
	EXPECT_EQ(1, add(1, 0));

	EXPECT_EQ(-1, add(0, -1));
	EXPECT_EQ(-1, add(-1, 0));

	EXPECT_EQ(15, add(5, 10));
	EXPECT_EQ(-15, add(-10, -5));

	EXPECT_EQ(10.5, add(7, 3.5));
	EXPECT_EQ(-40.5, add(-45.5, 5));
	EXPECT_EQ(-15.6, add(-12.5, -3.1));

	EXPECT_NE(11, add(1, 10.23456));
	EXPECT_NE(10, add(-10, -10));
	EXPECT_NE(-15, add(-15, -15));
};

TEST(SubtractTest, BasicTests)
{
	EXPECT_EQ(0, subtract(0, 0));

	EXPECT_EQ(-1, subtract(0, 1));
	EXPECT_EQ(1, subtract(1, 0));

	EXPECT_EQ(1, subtract(0, -1));
	EXPECT_EQ(-1, subtract(-1, 0));

	EXPECT_EQ(-5, subtract(5, 10));
	EXPECT_EQ(-5, subtract(-10, -5));

	EXPECT_EQ(3.5, subtract(7, 3.5));
	EXPECT_EQ(-50.5, subtract(-45.5, 5));
	EXPECT_EQ(-9.4, subtract(-12.5, -3.1));

	EXPECT_NE(9, subtract(1, 10.23456));
	EXPECT_NE(10, subtract(-10, -10));
	EXPECT_NE(-15, subtract(-15, -15));
};

TEST(MultiplyTest, BasicTests)
{
	EXPECT_EQ(0, multiply(0, 0));
	EXPECT_EQ(0, multiply(0, 1));
	EXPECT_EQ(0, multiply(1, 0));
	EXPECT_EQ(0, multiply(0, -1));
	EXPECT_EQ(0, multiply(-1, 0));

	EXPECT_EQ(50, multiply(5, 10));

	EXPECT_EQ(24.5, multiply(7, 3.5));
	EXPECT_EQ(-227.5, multiply(-45.5, 5));
	EXPECT_EQ(38.75, multiply(-12.5, -3.1));
};

TEST(DivideTest, BasicTests)
{
	EXPECT_EQ(0, divide(0, 1));

	EXPECT_EQ(0, divide(0, -1));

	EXPECT_EQ(0.5, divide(5, 10));
	EXPECT_EQ(2, divide(7, 3.5));

	EXPECT_EQ(-9, divide(-45, 5));
	EXPECT_EQ(9, divide(-45, -5));
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
	EXPECT_TRUE(caught);

	caught = false;
	try
	{
		divide(1, 0);
	}
	catch (std::invalid_argument const &e)
	{
		caught = true;
	}
	EXPECT_TRUE(caught);

	caught = false;
	try
	{
		divide(-1, 0);
	}
	catch (std::invalid_argument const &e)
	{
		caught = true;
	}
	EXPECT_TRUE(caught);

	caught = false;
	try
	{
		divide(1, 0.0000000001);
	}
	catch (std::invalid_argument const &e)
	{
		caught = true;
	}
	EXPECT_FALSE(caught);
};

TEST(ExponentiateTest, BasicTests)
{
	EXPECT_EQ(1, exponentiate(1, 0));
	EXPECT_EQ(1, exponentiate(1, 10));
	EXPECT_EQ(1, exponentiate(-1, 10));
	EXPECT_EQ(-1, exponentiate(-1, 9));
	EXPECT_EQ(0, exponentiate(0, 10));
	EXPECT_EQ(1, exponentiate(12, 0));
	EXPECT_EQ(25, exponentiate(-5, 2));
	EXPECT_EQ(-125, exponentiate(-5, 3));
	EXPECT_EQ(0.25, exponentiate(2, -2));
	EXPECT_EQ(1048576, exponentiate(-2, 20));
	EXPECT_EQ(5.844053197e-77, exponentiate(7.35, -88));
	EXPECT_EQ(5.785392902, exponentiate(7.35, 0.88));
	EXPECT_EQ(0.1728491076, exponentiate(7.35, -0.88));
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
	EXPECT_TRUE(caught);

	caught = false;
	try
	{
		exponentiate(-2, 3.5);
	}
	catch (std::invalid_argument const &e)
	{
		caught = true;
	}
	EXPECT_TRUE(caught);

	caught = false;
	try
	{
		exponentiate(-2.123, -4.6);
	}
	catch (std::invalid_argument const &e)
	{
		caught = true;
	}
	EXPECT_TRUE(caught);
};

TEST(RootTest, BasicTests)
{
	EXPECT_EQ(0, root(0, 10));
	EXPECT_EQ(0, root(0, 0.5));
	EXPECT_EQ(2, root(4, 2));
	EXPECT_EQ(0.5, root(4, -2));
	EXPECT_EQ(1.743639034, root(7, 3.5));
	EXPECT_EQ(-2.145864422, root(-45.5, 5));
	EXPECT_EQ(2.146288711, root(45.545, 5));
	EXPECT_EQ(0.4579514249, root(12.5, -3.234));
	EXPECT_EQ(7.888609052e-31, root(0.25, 0.02));
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
	EXPECT_TRUE(caught);

	caught = false;
	try
	{
		root(-2, 4);
	}
	catch (std::invalid_argument const &e)
	{
		caught = true;
	}
	EXPECT_TRUE(caught);

	caught = false;
	try
	{
		root(-2, -4);
	}
	catch (std::invalid_argument const &e)
	{
		caught = true;
	}
	EXPECT_TRUE(caught);

	// caught = false;
	// try
	// {
	// 	root(-2.1, -4.2);
	// }
	// catch (std::invalid_argument const& e)
	// {
	// 	caught = true;
	// }
	// EXPECT_TRUE(caught);
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
	EXPECT_TRUE(caught);

	caught = false;
	try
	{
		root(5.454, 0);
	}
	catch (std::invalid_argument const &e)
	{
		caught = true;
	}
	EXPECT_TRUE(caught);
};

TEST(LogTest, BasicTests){
	EXPECT_EQ(0, log(1,0));
	EXPECT_EQ(1, log(10,10));
	EXPECT_EQ(2, log(64,8));
	EXPECT_EQ(6, log(46656,6));

	EXPECT_NEAR(-1.609437912434e+00, log(0.2,M_E), 1e-9);
	EXPECT_NEAR(4.306765580734e-01, log(2,5), 1e-9);
	EXPECT_NEAR(1.318065436796e+00, log(15.5,8), 1e-9);
	EXPECT_NEAR(2.321928094887e+00, log(0.2,0.5), 1e-9);
	EXPECT_NEAR(5.107922458136e+01, log(987654321,1.5), 1e-9);

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
	EXPECT_TRUE(caught);

	caught = false;
	try
	{
		log(-1, 2);
	}
	catch (std::invalid_argument const &e)
	{
		caught = true;
	}
	EXPECT_TRUE(caught);

	caught = false;
	try
	{
		std::cout << log(0.2, 0) << std::endl;
	}
	catch (std::invalid_argument const &e)
	{
		caught = true;
	}
	EXPECT_TRUE(caught);

	caught = false;
	try
	{
		log(10, 1);
	}
	catch (std::invalid_argument const &e)
	{
		caught = true;
	}
	EXPECT_TRUE(caught);
};

TEST(FactorialTest, BasicTests)
{
	EXPECT_EQ(1, factorial(0));
	EXPECT_EQ(6, factorial(3));
	EXPECT_EQ(2432902008176640000, factorial(20));
};
