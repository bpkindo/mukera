#include <cmath>
#include "functions.h"
#include <map>


//--------------------------------------------------
//make xinfo = cutpoints
// [[Rcpp::depends(RcppArmadillo)]]
void makexinfo(size_t p, size_t n, arma::mat const& x, arma::mat& xi, size_t nc)
{
   double xinc;

   //compute min and max for each x. minx[i] is the minimum value for the ith predictor
   // and maxx[i] is the maximum value for the ith predictor
   std::vector<double> minx(p,INFINITY);
   std::vector<double> maxx(p,-INFINITY);
   double xx;
   for(size_t i=0;i<p;i++) {
      for(size_t j=0;j<n;j++) {
         xx = x(i,j);
         if(xx < minx[i]) minx[i]=xx;
         if(xx > maxx[i]) maxx[i]=xx;
      }
   }
   //make grid of nc cutpoints between min and max for each x.
   for(size_t i=0;i<p;i++) {
      xinc = (maxx[i]-minx[i])/(nc+1.0);
      for(size_t j=0;j<nc;j++) xi(i,j) = minx[i] + (j+1)*xinc;
   }
}
