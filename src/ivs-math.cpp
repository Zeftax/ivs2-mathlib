#include <stdexcept>
#include <cmath>

namespace ivsm {

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

    double exponentiate(double p_base, unsigned long p_exponent)
    {
        return pow(p_base, p_exponent);
    }

    double root(double p_radicand, double p_degree)
    {
        if(p_degree == 0)
        {
            throw std::invalid_argument("The degree cannot be 0.");
        }
		if(p_radicand < 0 && p_radicand != (long) p_radicand)
		{
			throw std::invalid_argument("In the negaive, we only support "
					"integer radicands");
		}

		return pow(p_radicand, 1 / p_degree);
    }

    double log(double p_antilogarithm, double p_base)
    {
        if(p_base < 0)
        {
            throw std::invalid_argument(
					"The base has to be a positive number.");
        }
        if(p_base == 1)
        {
            throw std::invalid_argument("The base cannot be 1.");
        }
        if(p_antilogarithm <= 0)
        {
            throw std::invalid_argument(
					"The anti logarithm has to be positive.");
        }

        return log2(p_antilogarithm) / log2(p_base);
    }

    unsigned long factorial(unsigned long p_arg)
    {
        if(p_arg == 0)
        {
            return 1;
        }
        else
        {
            return p_arg * factorial(p_arg - 1);
        }
    }

}
