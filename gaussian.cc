#include <cmath>
#include <iostream>

#include "gaussian.h"



/**
 *
 *  \brief         A simple copy assignment operator for two Gaussian objects.
 *
 */
Gaussian::Gaussian(const Gaussian& rhs) {
    mu_ = rhs.mu_;
    sigma_ = rhs.sigma_;
}

/**
 *
 *  \brief         A simple copy constructor for two Gaussian objects.
 *
 */
Gaussian&::Gaussian::operator=(const Gaussian &rhs){
    if (mu_ != rhs.mu_ && sigma_ != rhs.sigma_) {
        mu_ = rhs.mu_;
        sigma_ = rhs.sigma_;
    }
    return *this;
}

/**
 *
 *  \brief         A simple get function which returns the mean value mu of the Gaussian
 *                 distribution object.
 *  \return        mu. The mean of the Gaussian distribution.
 *
 */
inline double Gaussian::get_mu() const {
    return mu_;
}

/**
 *
 *  \brief         A simple get function which returns the standard deviation value sigma
 *                 of the Gaussian distribution object.
 *  \return        sigma. The standard deviation of the Gaussian distribution.
 *
 */
inline double Gaussian::get_sigma() const {
    return sigma_;
}

/**
 *
 *  \brief         A simple function used to print the Normal Distribution mean and stdev. *
 */
void Gaussian::print_parameters() const {
    std::cout << "Normal Distribution with mean = " << mu_ << " and stdev = " << sigma_ << '\n';
}

/**
 *
 *  \brief         A simple function which returns the normalized Z score value using the
 *                 Z-score formula. A z-score tells you where the score lies on a normal
 *                 distribution curve. A z-score of zero tells you the values is exactly average
 *                 while a score of +3 tells you that the value is much higher than average.
 *  \param         The value x is the observed value.
 *  \return        The standard score, or Z value.
 *
 */
inline double Gaussian::Z(const double x) const {
    return (x - mu_) / sigma_;
}

/**
 *
 *  \brief         A function which uses the cumulative distribution function of the normal
 *                 distribution to
 *  \param         The value x is as above, the right-most point in the interval.
 *  \return        An approximation of the integral for the given interval x.
 *
 */
inline double Gaussian::ERF(const Gaussian &dist, const double x) const {
    return 2 * dist.CDF(dist, x * std::sqrt(2)) - 1;
}

/**
 *
 *  \brief         A function which preforms a polynomial approximation of the
 *                 cumulative distribution function (C.D.F) using Hart approximation.
 *  \param         The value x is as above, the right-most point in the interval.
 *  \return        An approximation of the integral for the given interval x.
 *
 */
double Gaussian::CDF(const Gaussian &dist, const double x) const {

    const double norm = dist.Z(x);
    constexpr double boundary = 7.07106781186547;

    constexpr double kN0 = 220.206867912376;
    constexpr double kN1 = 221.213596169931;
    constexpr double kN2 = 112.079291497871;
    constexpr double kN3 = 33.912866078383;
    constexpr double kN4 = 6.37396220353165;
    constexpr double kN5 = 0.700383064443688;
    constexpr double kN6 = 3.52624965998911e-02;

    constexpr double kM0 = 440.413735824752;
    constexpr double kM1 = 793.826512519948;
    constexpr double kM2 = 637.333633378831;
    constexpr double kM3 = 296.564248779674;
    constexpr double kM4 = 86.7807322029461;
    constexpr double kM5 = 16.064177579207;
    constexpr double kM6 = 1.75566716318264;
    constexpr double kM7 = 8.83883476483184e-02;

    const double z = std::fabs(norm);
    double c = 0.0;

    if (z <= 37.0) {
        const double e = exp(-z * z / 2.0);
        if (z < boundary) {
            const double n = (((((kN6 * z + kN5) * z + kN4) * z + kN3) * z + kN2) * z + kN1) * z + kN0;
            const double d = ((((((kM7 * z + kM6) * z + kM5) * z + kM4) * z + kM3) * z + kM2) * z + kM1) * z + kM0;
            c = e * n / d;
        } else {
            const double f = z + 1.0 / (z + 2.0 / (z + 3.0 / (z + 4.0 / (z + 13.0 / 20.0))));
            c = e / (std::sqrt(4 * MYPI * f));
        }
    }
    return norm <= 0.0 ? c : 1 - c;
}

/**
 *
 *  \brief         A function which preforms a polynomail approximation of the
 *                 cumulative distribution function (C.D.F) using Hart approximation.
 *  \param         The value x is as above, the right-most point in the interval.
 *  \return        An approximation of the integral for the given interval x.
 *
 */
inline double Gaussian::PDF(const Gaussian &dist, const double x) {
    return 1 / (dist.get_sigma() * sqrt(2 * MYPI)) * exp(-0.5 * pow((x - dist.get_mu()) / dist.get_sigma(), 2));
}