# Hart Approximation to Normal Distribution

This is a simple program that implements Hart's polynomial approximation to the Normal or Gaussian
distribution. The method provides a high precision approximation of the cumulative distribution
function (C.D.F) whose implementation lends itself to C++ since we can use constexpressions to evaluate
many of the values needed for the polynomial approximation at run time. The results are comparable in 
speed and precision to that of the Boost C++ Libraries.

## Contents

1. [Overview](#overview)
2. [Requirements](#requirements)
3. [Compilation and Usage](#compilation-and-usage)
4. [Known Issues](#known-issues)

## Overview

The Gaussian object allows calculations for the ERF, CDF and PDF of a Gaussian object with given mean
and stdev.


## Requirements

- gcc
- gnuplot (if you would like to produce graphics)
- gsl (for using Sobol qrng, otherwise comment out that part of the code (L.48-56 in coord.cc))

## Compilation and Usage

To compile the code simply run the following command inside a terminal in the project directory:

```shell
make
```

To run a test on the code, simply run the following command inside a terminal in the project directory:

```shell
./main
```

Note: I know I can add this to the Makefile as 'make plot' but I prefer to leave the commands here so I can return to them.

## Results

Using Hart Approximation we see that we get very similar results to that of the Gaussian object used in the
Boost library. Likewise, we get similar, if not better performance output using Hart Approximation.

```shell

Normal Distribution with mean = 0.000000 and stdev = 1.000000
-----------------------------------------------------------
  x           Phi(x)             Method 
-3.0    0.00134989803163        Hart approx.
-3.0    0.00134989803163        BOOST Library.
-2.0    0.02275013194818        Hart approx.
-2.0    0.02275013194818        BOOST Library.
-1.0    0.15865525393146        Hart approx.
-1.0    0.15865525393146        BOOST Library.
-0.5    0.30853753872599        Hart approx.
-0.5    0.30853753872599        BOOST Library.
 0.0    0.50000000000000        Hart approx.
 0.0    0.50000000000000        BOOST Library.
 0.5    0.69146246127401        Hart approx.
 0.5    0.69146246127401        BOOST Library.
 1.0    0.84134474606854        Hart approx.
 1.0    0.84134474606854        BOOST Library.
 2.0    0.97724986805182        Hart approx.
 2.0    0.97724986805182        BOOST Library.
 3.0    0.99865010196837        Hart approx.
 3.0    0.99865010196837        BOOST Library.
-----------------------------------------------------------


Normal Distribution with mean = 1.00000000000000 and stdev = 2.00000000000000
-----------------------------------------------------------
  x           Phi(x)             Method 
-3.0    0.02275013194818        Hart approx.
-3.0    0.02275013194818        BOOST Library.
-2.0    0.06680720126886        Hart approx.
-2.0    0.06680720126886        BOOST Library.
-1.0    0.15865525393146        Hart approx.
-1.0    0.15865525393146        BOOST Library.
-0.5    0.22662735237687        Hart approx.
-0.5    0.22662735237687        BOOST Library.
 0.0    0.30853753872599        Hart approx.
 0.0    0.30853753872599        BOOST Library.
 0.5    0.40129367431708        Hart approx.
 0.5    0.40129367431708        BOOST Library.
 1.0    0.50000000000000        Hart approx.
 1.0    0.50000000000000        BOOST Library.
 2.0    0.69146246127401        Hart approx.
 2.0    0.69146246127401        BOOST Library.
 3.0    0.84134474606854        Hart approx.
 3.0    0.84134474606854        BOOST Library.
-----------------------------------------------------------

CPU time used (per clock_gettime()): 0.016768 seconds.

```

## Known Issues

None at present.
