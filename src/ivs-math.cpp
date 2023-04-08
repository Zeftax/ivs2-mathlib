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
		throw std::invalid_argument("cannot divide by 0 moron!!!!");
	}
	return p_dividend / p_divisor;
}

double exponentiate(double p_base, double p_exponent)
{
	if(p_exponent < 0)
	{
		throw std::invalid_argument("The exponent has to be a natural number.");
	}
	else if(p_exponent == 0)
	{
		return 1;
	}
	else
	{
		return p_base * exponentiate(p_base, p_exponent - 1);
	}
}

double root(double p_radicand, double p_degree)
{
	return exponentiate(p_radicand, 1 / p_degree);
}

double log(double p_antilogarithm, double p_base)
{
	// base ^ log = antilog
	return root(p_antilogarithm, p_base);
}

unsigned long factorial(unsigned long p_arg)
{
	if(p_arg == 2)
	{
		return 2;
	}
	else
	{
		return p_arg * factorial(p_arg - 1);
	}
}
