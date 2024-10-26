#include <math.h>
#include <stdio.h>
#include <stdbool.h>
int is_prime(int n);
int prime_numbers(long n);
void division(int size, int B[ ], long number);
/*
*  let A be an array of Boolean values, indexed by integers 2 to n,
    initially all set to true.

    for i = 2, 3, 4, ..., not exceeding √n do
        if A[i] is true
            for j = i2, i2+i, i2+2i, i2+3i, ..., not exceeding n do
                set A[j] := false

    return all i such that A[i] is true.
 */

int main(void) {
    int number = 0;
//991350783547
    prime_numbers(991350783547);
    // printf(prime_numbers(991350783547));

    // while(scanf("%d", &number)==1 && number != 0) {
    //
    //     if(is_prime(number))
    //         printf("Prvociselny rozklad cisla %d je:\n%d\n", number, number);
    //
    //     else {
    //         printf("Prvociselny rozklad cisla %d je:\n", number);
    //         int counter = 0; //
    //         for(int i = 2; i <= sqrt(number); i++) { //10 = 2s x 5 ; 2^3
    //
    //             while (number % i == 0) {
    //                 counter ++;
    //                 number = number / i;
    //             }
    //             // if (counter > 0) {
    //             if (counter == 1) {
    //                 printf("%d", i);
    //                 counter = 0;
    //             }
    //             else if (counter > 1)  {
    //                 printf(" X %d^%d", i, counter);
    //                 counter = 0;
    //
    //             }
    //             // }
    //
    //
    //         }
    //
    //     }
    //
    // }

    // printf("%d", is_prime(number));




    return 0;
}

// cislo 10 169 //i <= sqrt(n); ++i
int is_prime(int n) {
    for(int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}



int prime_numbers(long n) {
    bool A[1000000]; // to count last one as well
    for (int i = 2; i < 1000000; i++) {//from 2, so 0 and 1 wont be in the array
        A[i] = true;
    }

    int counter = 0;
    int count_arr = 0;
    for(int i = 2; i < (int)sqrt(1000000); i++) {
        if(A[i] == true) {
            for(int j = i*i; j < 1000000; j +=i) {
                A[j] = false;
            }
        }
    }
    for( int i = 0; i < 1000000; i++) {//count the amount of prime numbers for arr B
        if(A[i] == true)
            count_arr++;
    }
    printf("%d\n", count_arr);

    int B[count_arr]; //Why am I adding 1
    printf("Size of B: %d\n", sizeof(B) / sizeof(int));
    int index = 0;
    for( int i = 0; i < 1000000; i++) {
        if(A[i] == true) {
            B[index] = i;
            // printf("%d ", B[index]);
            index ++;
            counter++;
         }
    }
    division(count_arr,B, n);
    return 0;
}

void division(int size,int B[],long number) {
    // number = 991350783547;
    printf("Size of num: %ld\n", number);
    for(int i = 0; i < size; i++) {
        if( number % B[i] == 0) {
            printf("From func division %d\n", B[i]);
            number /= B[i];
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