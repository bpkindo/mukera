#ifndef __MUKERA_H__
#define __MUKERA_H__

#include <RcppArmadillo.h>
#include <Rcpp.h>
#include <stdio.h>
#include <time.h>

using namespace arma;
using namespace Rcpp;

arma::vec breg(arma::vec const& y, arma::mat const& X, arma::vec const& betabar, arma::mat const& A);

#endif