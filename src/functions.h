#include <RcppArmadillo.h>
#include <cmath>
#include <iostream>
#include "info.h"

using namespace arma;
using namespace Rcpp;

void makexinfo(size_t p, size_t n, arma::mat const& x, arma::mat& xi, size_t nc);
