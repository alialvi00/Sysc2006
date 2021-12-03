/* SYSC 2006 Lab 10 - Unfinished Test Harness. */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "recursive_functions.h"


/* Display the values returned by C's pow() function and our
 * recursive power() function. If power() is correct, the two values
 * should be the same, or differ at most by a small amount.
 */
void test_power(double x, int k)
{
    printf("Calling power(x, k) with x = %.2f, k = %d\n", x, k);
    printf("Expected result: %.2f\n", pow(x, k));
    printf("Actual result: %.2f\n\n", power(x, k));
}

/* Exercise our recursive num_digits() function.
 * Display the result we expect num_digits() to return, followed by
 * the actual value calculated by the function.
 *
 * Parameter k is the argument that will be passed to num_digits().
 * Parameter expected is the result that a correct implementation of
 * num_digits() will return.
 */
void test_num_digits(int k, int expected)
{
    printf("Calling num_digits(k, expected) with k = %d, expected = %d\n",k,expected);
    printf("Expected result: %d\n ", expected);
    printf("Actual result: %d\n", num_digits(k));
    
}

/*
 * Print then integers in array a in the form: [a[0] a[1] .. a[n-1]].
 */
void print_array(int a[], int n)
{
    if (n <= 0)
        return;

    printf("{%d", a[0]);
    for (int i = 1; i < n; i += 1) {
        printf(" %d", a[i]);
    }
    printf("}");
}

/* Exercise our recursive occurrences function.
 * Display the result we expect occurrences() to return, followed by
 * the actual value calculated by the function.
 *
 * Parameter a is the array that will be passed to occurrences().
 * Parameter n is the number of elements in the array.
 * Parameter target is the value that occurrences() will search for.
 * Parameter expected is the result that a correct implementation of
 * occurrences() will return.
 */
void test_occurrences(int a[], int n, int target, int expected)
{
    int length = (sizeof(a)/sizeof(a[0]));
    int i = 0;
    printf("Array: ");
    while(i<length) {
        printf("%d ", a[i]);
        i++;
    }
    printf("\n");
    printf("Calling occurrences(a[], n, target, expected) with n = %d, target = %d and expected = %d\n",n,target,expected);
    printf("Expected result: %d\n ",expected);
    printf("Actual result: %d\n ",occurrences(a,n,target));
}

/* Challenge exercise:
 * Display the values returned by C's pow() function and our
 * recursive power2() function. If power2() is correct, the two values
 * should be the same, or differ at most by a small amount.
 */
void test_power2(double x, int k)
{
    printf("Calling power(x, k) with x = %.2f, k = %d\n", x, k);
    printf("Expected result: %.2f\n", pow(x, k));
    printf("Actual result: %.2f\n\n", power2(x, k));
}

void test_exercise_1(void)
{
    /* Test cases that allow us to verify if power() correctly calculates
     * 3.5 ^ 0, 3.5 ^ 1, 3.5 ^ 2, 3.5 ^ 3 and 3.5 ^ 4.
     */
    printf("*** Exercise 1: Testing power ***\n");
    test_power(3.5, 0);
    test_power(3.5, 1);
    test_power(3.5, 2);
    test_power(3.5, 3);
    test_power(3.5, 4);
    printf("\n");
}

void test_exercise_2(void)
{
    printf("*** Exercise 2: Testing num_digits ***\n");
    /* Test case: num_digits(5) should return 1. */
    test_num_digits(5, 1);

    /* Test case: num_digits(9) should return 1. */
    test_num_digits(9, 1);

    /* Test case: num_digits(10) should return 2. */
    test_num_digits(10, 2);

    /* Test case: num_digits(99) should return 2. */
    test_num_digits(99, 2);

    /* Test case: num_digits(100) should return 3. */
    test_num_digits(100, 3);

    /* Test case: num_digits(999) should return 3. */
    test_num_digits(999, 3);

    /* Test case: num_digits(1000) should return 4. */
    test_num_digits(1000, 4);
    printf("\n");
}

void test_exercise_3(void)
{
    printf("*** Exercise 3: Testing occurrences ***\n");
    int x[] = {1, 2, 4, 4, 4, 5, 6, 7, 8, 9, 12};
    int n = sizeof(x) / sizeof(n);

    /* Test case: occurrences(x, n, 1) should return 1. */
    test_occurrences(x, n, 1, 1);

    /* Test case: occurrences(x, n, 2) should return 1. */
    test_occurrences(x, n, 2, 1);

    /* Test case: occurrences(x, n, 4) should return 3. */
    test_occurrences(x, n, 4, 3);

    /* Test case: occurrences(x, n, 12) should return 1. */
    test_occurrences(x, n, 12, 1);

    /* Test case: occurrences(x, n, 3) should return 0. */
    test_occurrences(x, n, 3, 0);
    printf("\n");
}

void test_exercise_4(void)
{
    /* Test cases that allow us to verify if power2() correctly calculates
     * 3.5 ^ 0, 3.5 ^ 1, 3.5 ^ 2, 3.5 ^ 3 and 3.5 ^ 4.
     */
    printf("*** Exercise 4: Testing power2 ***\n");
    test_power2(3.5, 0);
    test_power2(3.5, 1);
    test_power2(3.5, 2);
    test_power2(3.5, 3);
    test_power2(3.5, 4);
    printf("\n");
}

int main(void)
{
    printf("SYSC 2006 Lab 10 Test Harness\n\n");

    test_exercise_1();
    test_exercise_2();
    test_exercise_3();
    test_exercise_4();

    return 0;
}
