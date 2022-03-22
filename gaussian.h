#ifndef NORMAL_H_ZORMJADF
#define NORMAL_H_ZORMJADF

constexpr double MYPI = M_PI;

/**
 *
 *  \brief         A class used to represent a Gaussian distribution object.
 *
 */
class Gaussian {
public:
    // Constructors
    Gaussian() : mu_(0.0), sigma_(1.0) {};

    Gaussian(double mean, double stdev) : mu_{mean}, sigma_{stdev} {};

    // Copy operators
    Gaussian(const Gaussian &rhs);               //!< Copy constructor
    Gaussian &operator=(const Gaussian &rhs);    //!< Copy assignment operator

    // Gaussian distribution functions
    inline double Z(const double x) const;

    inline double ERF(const Gaussian &dist, const double x) const;

    inline double PDF(const Gaussian &dist, const double x);

    double CDF(const Gaussian &dist, const double x) const;

    // Get functions
    inline double get_mu() const;

    inline double get_sigma() const;

    // Util function for printing
    void print_parameters() const;

    // Destructor
    ~Gaussian() {};

private:
    double mu_;        //!< mu_ holds the mean of Gaussian
    double sigma_;     //!< sigma_ holds the mean of Gaussian

};

#endif // End of include guard: NORMAL_H_ZORMJADF
