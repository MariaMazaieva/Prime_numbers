#include <math.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define UPPER_BOUND 1000000
#define MIN_VALUE 0
#define size_B 100000
// #define MAX_VALUE 991350783549
//999983

int sieve_of_Eratosthenes(int B[]);
void division(int size, int B[], long number);
int* control_input(int *ret, int count_arr,int B[] );
// bool is_in_B(long n, int B[], int count_arr);

int main(void) {
    int ret = EXIT_SUCCESS;
    int count_arr = 0;
    int B [size_B] = {0};
    count_arr = sieve_of_Eratosthenes(B);
    control_input(&ret, count_arr, B);
    return ret;
}
/*Function reads numbers from stdin to variable number in a loop while, stops if number == 0.
 * @var result  - used to read amount(1) of successfully scanned numbers from input.
 * @ret - EXIT_SUCCESS, otherwise number of error if integer was not read.
 * MIN_VALUE is set to 0, MAX_VALUE is set to 991350783549
 */

int* control_input(int *ret, int count_arr,int B []) {
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

        division(count_arr,B, number);
    }
    return ret;
}

/*Function creates a table with multiples of prime numbers and mark them as False.
 * @arr bool A[]  - used to create an array of all true-s.
 * @count_arr - used to track the amount of prime numbers to later on use them in array B.
 * func division - is used to divide number and find its divisors.
 */

int sieve_of_Eratosthenes (int B[]) {
    bool A[UPPER_BOUND] ; // to count last one as well
    //
    A[0] = false;
    A[1] = false;
    for (int i = 2; i < UPPER_BOUND; i++) //from 2, so 0 and 1 wont be in the array
        A[i] = true;

    int index = 0;
    int sqr = (int)sqrt(UPPER_BOUND);
    for(int i = 2; i <UPPER_BOUND; i++) {
        if (A[i] == true && i <= sqr) {
            for(int j = i*i; j < UPPER_BOUND; j +=i) {
                A[j] = false;
            }
        }
        if (A[i]) {
            B[index++] = i;
        }
    }
    //  counter = sizeof(B) / sizeof(B[0]);
    // *count_arr = counter;
    return index;
}

/*Function divides number to the prime numbers, count its factorials as well.
 * @size  - amount of prime numbers we have from func sieve_of_Eratosthenes
 */

void division(const int size,int B[],long number) {
    bool first_number = true;
    for (int i = 0; i <size -1 && number > 1; i++){
        int n = B[i];
        // if (n == 0) break;
        if( number % n == 0) {
            int power = 1;
            number = number / n;
            while (number % n == 0) {
                number = number / n;
                power++;
            }
            if(first_number) {
                printf("%d",n);
                first_number = false;
            }else {
                printf(" x %d", n);
            }
            if (power > 1) {
                printf("^%d", power);
            }
        }
    }
    if (number > 1) {
        if (!first_number) {
            printf(" x ");
        }
        printf("%ld", number);
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


