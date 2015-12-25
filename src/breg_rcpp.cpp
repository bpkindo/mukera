#include "mukera.h"
#include "info.h"
#include "functions.h"
// [[Rcpp::depends(RcppArmadillo)]]


//[[Rcpp::export]]
arma::vec breg(arma::vec const& y, arma::mat const& X, arma::vec const& betabar, arma::mat const& A) {

// Keunwoo Kim 06/20/2014

// Purpose: draw from posterior for linear regression, sigmasq=1.0

// Output: draw from posterior
 
// Model: y = Xbeta + e  e ~ N(0,I)

// Prior:  beta ~ N(betabar,A^-1)

  int k = betabar.size();
  arma::mat RA = chol(A);
  arma::mat W = join_cols(X, RA); //same as rbind(X,RA)
  arma::vec z = join_cols(y, RA*betabar);
  arma::mat IR = solve(trimatu(chol(trans(W)*W)), arma::eye(k,k)); //trimatu interprets the matrix as upper triangular and makes solve more efficient

  //mean and standard deviation of y
  double ybar = arma::mean(y);  
  double shat = arma::stddev(y);

 
   double lambda = 1.0; 
   double nu = 3.0;
   double kfac = 2.0;
   //x cutpoints
   size_t nc=100; //100 equally spaced cutpoints from min to max.
   size_t p = X.n_cols;
   size_t n = X.n_rows;
   arma::mat xi(p,nc);
   makexinfo(p,n,X,xi,nc); 
   
   xi.print();

   //--------------------------------------------------
  //prior and mcmc
  pinfo pi;
 
  return ((IR*trans(IR))*(trans(W)*z) + IR*arma::vec(rnorm(k)));
} 