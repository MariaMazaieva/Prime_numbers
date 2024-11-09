#include <math.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define UPPER_BOUND 1000000
#define MIN_VALUE 0
// #define MAX_VALUE 991350783549


int sieve_of_Eratosthenes(long n);
void division(int size, int B[ ], long number);
void check_for_prime(bool A[], long * count_false);
void array_of_primes(int B[ ], const bool A []);
int* control_input(int *ret);
void print_numbers(int * counter, int * power, int divisor);

int main(void) {
    int ret = EXIT_SUCCESS;
    control_input(&ret);
    return ret;
}
/*Function reads numbers from stdin to variable number in a loop while, stops if number == 0.
 * @var result  - used to read amount(1) of successfully scanned numbers from input.
 * @ret - EXIT_SUCCESS, otherwise number of error if integer was not read.
 * MIN_VALUE is set to 0, MAX_VALUE is set to 991350783549
 */

int* control_input(int *ret) {
    long number = -1;
    while(1) {
        int result = scanf("%ld", &number);
        if (number == 0)
            break;

        if (number < MIN_VALUE ) {
            fprintf(stderr, "Error: Chybny vstup!\n");
            *ret = 100;
            return ret;
        }
        if(result !=1) {
            fprintf(stderr, "Error: Chybny vstup!\n");
            *ret = 100;
            return ret;
        }
        if(number != 1) // special output for 1
            printf("Prvociselny rozklad cisla %ld je:\n", number);
        else
            printf("Prvociselny rozklad cisla 1 je:\n1");

        sieve_of_Eratosthenes(number);
    }
    return ret;
}

/*Function creates a table with multiples of prime numbers and mark them as False.
 * @arr bool A[]  - used to create an array of all true-s.
 * @count_arr - used to track the amount of prime numbers to later on use them in array B.
 * func division - is used to divide number and find its divisors.
 */

int sieve_of_Eratosthenes (long n) {
    bool A[UPPER_BOUND] ; // to count last one as well

    A[0] = false;
    A[1] = false;
    for (int i = 2; i < UPPER_BOUND; i++) //from 2, so 0 and 1 wont be in the array
        A[i] = true;
    //set first and second to false
    int count_arr = 0;
    // int size = sizeof(A)/sizeof(A[]);
    long count_false = 0;
    check_for_prime(A, &count_false);
    // printf("count false %lu\n", count_false);
    count_arr = UPPER_BOUND - count_false-2;
    // printf("primes %d",check_for_prime(A));
    // for( int i = 0; i <= UPPER_BOUND; i++) {//count the amount of prime numbers for arr B
    //     if(A[i])
    //         count_arr++;
    // }
    // printf("Array %d\n",count_arr);
    // printf("count false %lu\n", count_false);
    // printf("count arr %d\n", count_arr);
    int B[count_arr-1]; //creating arr B, size of amount of p
    array_of_primes(B,A);
    // count_arr = sqrt(count_arr);
    division(count_arr,B, n);

    return 0;
}

/*Function divides number to the prime numbers, count its factorials as well.
 * @size  - amount of prime numbers we have from func sieve_of_Eratosthenes
 */

void  check_for_prime(bool A[], long * count_false) {
    *count_false = 0;
    int sqr = (int)sqrt(UPPER_BOUND);
    for(int i = 2; i < sqr; i++) {
        for(int j = i*i; j < UPPER_BOUND; j +=i) {
            if (A[j] == true) {
                A[j] = false;
                (*count_false)++;
            }
        }
    }
}

void array_of_primes(int B[], const bool A[]) {
    int index = 0;
    for( int i = 0; i < UPPER_BOUND; i++) {
        if(A[i] ) {
            B[index++] = i;
            // index++;
        }
    }
}

/*
    int
    for( int i = 0; i <= UPPER_BOUND; i++) {//count the amount of prime numbers for arr B
        if(A[i])
        count_arr++;
    }
    // printf("Array %d\n",count_arr);
    int B[count_arr-1]; //creating arr B, size of amount of p
    array_of_primes(B,A);
    division(count_arr,B, n);
*/
void division(const int size,int B[],long number) {
    int counter = 0;
    // int power = ;
    bool first_number = true;
    // size == sqrt(size);
    for (int i = 0; i < size && number > 1; i++){
        if( number % B[i] == 0) {
            int power = 1;
            counter++;
            number = number / B[i];
            while (number % B[i] == 0) {
                number = number / B[i];
                power++;
            }
            if(first_number) {
                printf("%d",B[i]);
                if(power > 1)
                    printf("^%d",power);
                first_number = false;
            }else {
                printf(" x %d", B[i]);
                if(power > 1)
                    printf("^%d",power);
            }
        }
    }
    putchar('\n');
}
// let A be an array of Boolean values, indexed by integers 2 to n,
//   initially all set to true.
//
//   for i = 2, 3, 4, ..., not exceeding √n do
//       if A[i] is true
//           for j = i2, i2+i, i2+2i, i2+3i, ..., not exceeding n do
//               set A[j] := false
//
//   return all i such that A[i] is true.
//
//


