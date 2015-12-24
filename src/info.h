#ifndef __INFO_H__
#define __INFO_H__

#include <RcppArmadillo.h>
#include <Rcpp.h>
#include <stdio.h>
#include <time.h>

using namespace arma;
using namespace Rcpp;

struct moments{
  vec y;
  mat X;
  mat XpX;
  vec Xpy;
  mat hess;
};

//data
//class dinfo {
//public:
//   dinfo() {p=0;n=0;x=0;y=0;}
//   int p;  //number of vars
//   int n;  //number of observations
//   mat x; // armadillo matrix of predictors
//   vec y; // vector of response
//};

#endif
