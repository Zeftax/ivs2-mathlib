/*!
	\file tests.cpp
	\brief A collection of test for the math functions.
	\author Zdenek Borovec
	\author Tomas Krejci
	\author Jan Lozrt
	\author Jakub Mitrenga
	\copyright GNU GPLv3
*/

#include <gtest/gtest.h>
#include <stdexcept>

#include "ivs-math.hpp"

TEST(AddTest, BasicTests)
{
	EXPECT_EQ(add(0, 0), 0);

	EXPECT_EQ(add(0, 1), 1);
	EXPECT_EQ(add(1, 0), 1);

	EXPECT_EQ(add(0, -1), -1);
	EXPECT_EQ(add(-1, 0), -1);

	EXPECT_EQ(add(5, 10), 15);
	EXPECT_EQ(add(7, 3.5), 10.5);

	EXPECT_EQ(add(-45.5, 5), -40.5);
	EXPECT_EQ(add(-12.5, -3.1), -15.6);
}

TEST(SubtractTest, BasicTests)
{
	EXPECT_EQ(subtract(0, 0), 0);

	EXPECT_EQ(subtract(0, 1), -1);
	EXPECT_EQ(subtract(1, 0), 1);

	EXPECT_EQ(subtract(0, -1), 1);
	EXPECT_EQ(subtract(-1, 0), -1);

	EXPECT_EQ(subtract(5, 10), -5);
	EXPECT_EQ(subtract(7, 3.5), 3.5);

	EXPECT_EQ(subtract(-45.5, 5), -50.5);
	EXPECT_EQ(subtract(-12.5, -3.1), -9.4);
}

TEST(MultiplyTest, BasicTests)
{
	EXPECT_EQ(multiply(0, 0), 0);

	EXPECT_EQ(multiply(0, 1), 0);
	EXPECT_EQ(multiply(1, 0), 0);

	EXPECT_EQ(multiply(0, -1), 0);
	EXPECT_EQ(multiply(-1, 0), 0);

	EXPECT_EQ(multiply(5, 10), 50);
	EXPECT_EQ(multiply(7, 3.5), 24.5);

	EXPECT_EQ(multiply(-45.5, 5), -227.5);
	EXPECT_EQ(multiply(-12.5, -3.1), 38.75);
}

TEST(DivideTest, BasicTest)
{
	EXPECT_EQ(divide(0, 1), 0);

	EXPECT_EQ(divide(0, -1), 0);

	EXPECT_EQ(divide(5, 10), 0.5);
	EXPECT_EQ(divide(7, 3.5), 2);

	EXPECT_EQ(divide(-45, 5), -9);
	EXPECT_EQ(divide(-45, -5), 9);
}

TEST(DivideTest, DivideByZero)
{
	bool caught = false;
	try
	{
		divide(0, 0);
	}
	catch (std::invalid_argument const& e)
	{
		caught = true;
	}
	EXPECT_TRUE(caught);

	caught = false;
	try
	{
		divide(1, 0);
	}
	catch (std::invalid_argument const& e)
	{
		caught = true;
	}
	EXPECT_TRUE(caught);

	caught = false;
	try
	{
		divide(-1, 0);
	}
	catch (std::invalid_argument const& e)
	{
		caught = true;
	}
	EXPECT_TRUE(caught);

	caught = false;
	try
	{
		divide(1, 0.0000000001);
	}
	catch (std::invalid_argument const& e)
	{
		caught = true;
	}
	EXPECT_FALSE(caught);
}
