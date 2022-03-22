/**
 *	\file		assignment1.cc
 *	\brief		This program preforms both a numerical approximation and a polynomial approximation to the 
 *				integral of a Gaussian curve. The functions provided in the program will calculate phi(x),
 *				the value of the function at a given point x (the probability density function), and also 
 *				an approximate of the cumulative distribution function (C.D.F).
 *  \author		P. Prunty
 *  \version 	1.0
 * 	\date		2020-02-08
 */
#include <iostream>
#include <cmath>
#include <iomanip>
#include <ctime>

#include <boost/math/distributions/normal.hpp>

#include "gaussian.h"

#define BILLION 1E9

int main() {

    // Create object of class Gaussian via default constructor
    Gaussian A;
    boost::math::normal C;

    // Call overloaded constructor
    Gaussian B{1, 2};
    boost::math::normal D{1, 2};

    // Create a list. Is actually ok to use auto here
    auto list = {-3.0, -2.0, -1.0, -0.5, 0.0, 0.5, 1.0, 2.0, 3.0};

    // Calculate time taken by a request
    struct timespec requestStart, requestEnd;

    clock_gettime(CLOCK_REALTIME, &requestStart);

    // Calculate and print cumulative density function values for A for a number of input values
    std::cout << std::fixed << '\n';
    A.print_parameters();
    std::cout << std::setw(60) << std::setfill('-') << '\n' << std::setfill(' ');
    std::cout << "  x           Phi(x)             Method \n";
    for (auto i : list) {
        std::cout << std::setw(4) << std::setprecision(1) << i << "\t" << std::setprecision(14) << A.CDF(A, i)
                  << "  \tHart approx.\n"
                  << std::setw(4) << std::setprecision(1) << i << "\t" << std::setprecision(14)
                  << boost::math::cdf(C, i)
                  << "  \tBOOST Library.\n";
    }
    std::cout << std::setw(60) << std::setfill('-') << '\n' << std::setfill(' ');
    std::cout << "\n\n";


    // Calculate and print cumulative density function values for B for a number of input values.
    B.print_parameters();
    std::cout << std::setw(60) << std::setfill('-') << '\n' << std::setfill(' ');
    std::cout << "  x           Phi(x)             Method \n";
    for (auto i : list) {
        std::cout << std::setw(4) << std::setprecision(1) << i << "\t" << std::setprecision(14) << B.CDF(B, i)
                  << "  \tHart approx.\n"
                  << std::setw(4) << std::setprecision(1) << i << "\t" << std::setprecision(14)
                  << boost::math::cdf(D, i)
                  << "  \tBOOST Library.\n";
    }
    std::cout << std::setw(60) << std::setfill('-') << '\n' << std::setfill(' ');
    std::cout << "\n";

    clock_gettime(CLOCK_REALTIME, &requestEnd);

    // Calculate the time it took
    long double accum = (requestEnd.tv_sec - requestStart.tv_sec)
                        + (requestEnd.tv_nsec - requestStart.tv_nsec)
                          / BILLION;

    std::cout << "CPU time used (per clock_gettime()): " << std::setprecision(6) << accum << " seconds.\n";

    return 0;

}
