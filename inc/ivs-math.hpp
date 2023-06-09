/**
 * @file ivs-math.hpp
 *
 * @author Zdeněk Borovec <xborov08@vutbr.cz>
 * @author Tomáš Krejčí <xkrejc84@vutbr.cz>
 * @author Jan Lozrt <xlozrt00@vutbr.cz>
 * @author Jakub Mitrenga <xmitre07@vutbr.cz>
 *
 * @brief A collection of some math functions
 * @copyright GNU GPLv3
 * 
 * This library aims to serve the needs of our second IVS project in the academic year of 2022/2023 on BUT.
 */

#ifndef IVS_MATH
#define IVS_MATH

namespace ivsm {

    /**
     * @brief Sum of the two input numbers.
     * 
     * @param p_addend_a	The first addend.
     * @param p_addend_b	The second addend.
     * 
     * @return The sum of the two input numbers.
    */
    double add(double p_addend_a, double p_addend_b);

    /**
     * @brief Difference of the two input numbers.
     * 
     * @param p_minuend		The minuend.
     * @param p_subtrahend	The subtrahend.
     * 
     * @return The difference of the two input numbers.
    */
    double subtract(double p_minuend, double p_subtrahend);

    /**
     * @brief Multiplication of the two input numbers.
     * 
     * @param p_multiplier	The multiplier.
     * @param p_multiplicand	The multiplicand.
     * 
     * @return The product of the two input numbers.
    */
    double multiply(double p_multiplier, double p_multiplicand);

    /**
     * @brief Division of the two input numbers.
     * 
     * @param p_dividend	The dividend.
     * @param p_divisor	The divisor.
     * 
     * @return The ratio of the two input numbers.
    */
    double divide(double p_dividend, double p_divisor);

    /**
     * @brief Exponentiation of the base to the exponent.
     * 
     * @param p_base	The base for this exponentiation.
     * @param p_exponent	The exponent for this exponentiation.
     * 
     * @return The power of the base to the exponent.
    */
    double exponentiate(double p_base, double p_exponent);

    /**
     * @brief Degreeth root of the radicand.
     * 
     * @param p_radicand	The radicant of this root.
     * @param p_degree	The degree of this root.
     * 
     * @return The degreeth root of the radicand.
    */
    double root(double p_radicand, double p_degree);

    /**
     * @brief Logarithm of the anti-logarithm and the base.
     * 
     * @param p_antilogarithm	The anti-logarithm for this logarithm.
     * @param p_base			The base of the logarithm.
     * 
     * @return The logarithm of the anti-logarithm and the base.
    */
    double log(double p_antilogarithm, double p_base);

    /**
     * @brief Factorial of the number
     * 
     * @param p_arg The number which to factorialize.
     * 
     * @return The factorial of the input number.
    */
    unsigned long factorial(unsigned long p_arg);

}

#endif // IVS_MATH
