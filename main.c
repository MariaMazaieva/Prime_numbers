#include <math.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define UPPER_BOUND 1000000
#define MIN_VALUE 0
#define MAX_VALUE 991350783549
int sieve_of_Eratosthenes(long n);
void division(int size, int B[ ], long number);
void check_for_prime(bool A[]);
void array_of_primes(int B[ ], bool A []);
int control_input(int *ret, long number);
void print_numbers(int * counter, int * power, int divisor);

int main(void) {
    long number = -1;
    int ret = EXIT_SUCCESS;
    control_input(&ret, number);
    if ( ret == EXIT_SUCCESS ) {
        sieve_of_Eratosthenes(number);
    }

    return ret;
}
/*Function reads numbers from stdin to variable number in a loop while, stops if number == 0.
 * @var result  - used to read amount(1) of successfully scanned numbers from input.
 * @ret - EXIT_SUCCESS, otherwise number of error if integer was not read.
 * MIN_VALUE is set to 0, MAX_VALUE is set to 991350783549
 */

int control_input(int *ret, long number) {
    while(1) {
        int result = scanf("%ld", &number);
        if (number == 0)
            break;

        if (number < MIN_VALUE || number > MAX_VALUE) {
            fprintf(stderr, "Error: Chybny vstup!\n");
            *ret = 100;
            return *ret;
        }
        if(result !=1) {
            fprintf(stderr, "Error: Chybny vstup!\n");
            *ret = 100;
            return *ret;
        }
        if(number != 1) // special output for 1
            printf("Prvociselny rozklad cisla %ld je:\n", number);
        else
            printf("Prvociselny rozklad cisla 1 je:\n1");

        sieve_of_Eratosthenes(number);
    }
}

/*Function creates a table with multiples of prime numbers and mark them as False.
 * @arr bool A[]  - used to create an array of all true-s.
 * @count_arr - used to track the amount of prime numbers to later on use them in array B.
 * func division - is used to divide number and find its divisors.
 */

int sieve_of_Eratosthenes (long n) {
    bool A[UPPER_BOUND]; // to count last one as well
    for (int i = 2; i < UPPER_BOUND; i++) //from 2, so 0 and 1 wont be in the array
        A[i] = true;

    int count_arr = 0;
    check_for_prime(A);

    for( int i = 0; i < UPPER_BOUND; i++) {//count the amount of prime numbers for arr B
        if(A[i] == true)
            count_arr++;
    }

    int B[count_arr]; //creating arr B
    array_of_primes(B,A);
    division(count_arr,B, n);

    return 0;
}

/*Function divides number to the prime numbers, count its factorials as well.
 * @size  - amount of prime numbers we have from func sieve_of_Eratosthenes
 */
void division(int size,int B[],long number) {
    int counter = 0;
    int power = 1;
    int i =0;
    while(i < size && number > 0) {
        if( number % B[i] == 0) {
            counter++;
            number = number / B[i];
            while (number % B[i] == 0) {
                number = number / B[i];
                power++;
            }
            print_numbers(&counter, &power, B[i]);
        }
        i++;
    }
    if(number > 0)
        putchar('\n');
}

/*Function prints prime numbers of a given number.
 * has special conditions for each case of a number and its position in a line
 */

void print_numbers(int* counter, int * power, int divisor) {
    // reinitialize power, so it won't affect the next number
    if (*counter == 1 && *power > 1) //special condition for first !prime number
    {printf("%d^%d", divisor,*power);*power = 1;}

    else if (*counter == 1 && *power == 1) //special condition for first prime number
        printf("%d", divisor);

    else if (*counter >1  && *power > 1) //special condition for !first !prime number
    {printf(" x %d^%d",divisor, *power);*power = 1;}

    else if (*counter > 1 && *power == 0) //special condition for !first prime number
        printf(" x %d",divisor);
    else
        printf(" x %d",divisor);
}

void check_for_prime(bool A[]) {
    for(int i = 2; i < (int)sqrt(UPPER_BOUND); i++) {
        if(A[i] == true) {
            for(int j = i*i; j < UPPER_BOUND; j +=i)
                A[j] = false;
        }
    }
}

void array_of_primes(int B[], bool A[]) {
    int index = 0;
    for( int i = 0; i < UPPER_BOUND; i++) {
        if(A[i] == true) {
            B[index] = i;
            index ++;
        }
    }
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