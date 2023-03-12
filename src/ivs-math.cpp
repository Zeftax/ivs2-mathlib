#include <stdexcept>

#include "ivs-math.hpp"

double add(double p_addend_a, double p_addend_b)
{
	return p_addend_a + p_addend_b;
}

double subtract(double p_minuend, double p_subtrahend)
{
	return p_minuend - p_subtrahend;
}

double multiply(double p_multiplier, double p_multiplicand)
{
	return p_multiplier * p_multiplicand;
}

double divide(double p_dividend, double p_divisor)
{
	if(p_divisor == 0)
	{
		throw std::invalid_argument("Cannot divide by 0 MORON!!!!");
	}
	return p_dividend / p_divisor;
}
