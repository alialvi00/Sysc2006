/* SYSC 2006 Lab 10.
*
* Student Name: Ali Alvi
* Student Number: 101114940
 */

#include <stdio.h>
#include <math.h>

/* Return x raised to the power n for n >= 0. */
double power(double x, int n)
{
    if(n==0){ //Base case #1: If power is 0 then answer is 1
        return 1;
    }
    if(n == 1){//Base case #2: If power is 1 then answer is x
        return x;
    }
    return x * power(x,n-1); //Else perform recursion
}

/* Return the number of digits in integer n, n >= 0. */
int num_digits(int n)
{
    if(n<10){//Base case: If number is less than 10, than return 1
        return 1;
    }
    return 1 + num_digits(n/10);  //else return the initial count of 1 plus more digits
}

/* Return the count of the number of times target occurs in the first 
 * n elements of array a.
 */   
int occurrences(int a[], int n, int target)
{
    if(n == 0){ //If the search only includes the first element of the array
        if(a[n] == target) //return 1 if the first element in array is equal to target
            return 1;
        else //if not equal to target, return 0
            return 0;
    }
    //else if search is more than one element in array
    else if(a[n] == target){ //if the specified element equals to target
        return 1 + occurrences(a, n-1, target); //then decrement to the previous element
    }
    return occurrences(a, n-1, target); //perform the search by decrementing
}

/* Challenge exercise: return x raised to the power n for n >= 0. */
double power2(double x, int n)
{
    return -1;
}
