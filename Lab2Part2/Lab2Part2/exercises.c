/* SYSC 2006 Lab 2, Part 2.
 *
 * Incomplete implementations of the functions that will be coded during the lab.
 *
 * Name: Ali Alvi
 * Student Number: 101114940
 */

#include <stdlib.h>
#include <math.h>

#include "exercises.h"

/* Returns n! for n >= 0. (0! is defined to be 1.)
   Note that the return type is int, and n! grows rapidly as n increases,
   so this function should only be used for fairly small values of n; 
   i.e., if ints are implemented as 32-bit values, n must be <= 15.
*/
int factorial(int n)
{
    int result = 1;
    
    for(int i = 1; i <= n; i++){ //i is 1 because factorial 0 is 1
        result = result * i;
    }
    return result;
}

/* Returns the number of different ordered subsets of k objects picked
   from a set of n objects, for n > 0, k > 0, n >= k.
 */
int ordered_subsets(int n, int k)
{
    return factorial(n)/factorial(n-k);
}

/* Returns the binomial coefficient (n k); that is, the number of 
   combinations of k objects that can be chosen from a set of n objects, 
   for n > 0, k > 0, n >= k.
 */
int binomial(int n, int k)
{
    //If you factor the binomial formula and rearrange it,
    //you get (factorial(n)/factorial(n-k))/factorial(k)
    //which is just ordered_subsets(n,k)/factorial(k)
    return ordered_subsets(n, k)/factorial(k);
}

/* Returns the cosine of x (measured in radians) by calculating
 * the first n terms of the infinite series expansion of cosine.
 */
double cosine(double x, int n)
{
    double result = 1; //First time of series is 1
    
    for(int i = 0; i < n; i++){ //Starts from second term of the series
        
        if(i%2 == 0){ //If the term is even number, then add
            result += pow(x, i*2)/factorial(i*2);
        }
        else{
            result -= pow(x, i*2)/factorial(i*2); //else if odd number term
        }
    }
    return result; //return the result
}

