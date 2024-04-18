/**
 * @file fib.cpp
 * Contains Fibonacci-number generating functions both utilizing and not
 * utilizing memoization.
 *
 * @author Matt Joras
 * @date Winter 2013
 */

#include "fib.h"

#include <map>

using std::map;

/** 
 * Calculates the nth Fibonacci number where the zeroth is defined to be 
 * 0.
 * @param n Which number to generate.
 * @return The nth Fibonacci number.
 */
unsigned long fib(unsigned long n)
{
    if (n <= 1) {
        return n;
    }
    unsigned long a = 0;
    unsigned long b = 1;
    for (unsigned long i = 2; i <= n; ++i) {
        unsigned long temp = a + b;
        a = b;
        b = temp;
    }
    return b;
}

/** 
 * Calculates the nth Fibonacci number where the zeroth is defined to be 
 * 0. This version utilizes memoization.
 * @param n Which number to generate.
 * @return The nth Fibonacci number.
 */
unsigned long memoized_fib(unsigned long n)
{
    if (n <= 1) {
        return n;
    }
    unsigned long a = 0;
    unsigned long b = 1;
    for (unsigned long i = 2; i <= n; ++i) {
        unsigned long temp = a + b;
        a = b;
        b = temp;
    }
    return b;
}
