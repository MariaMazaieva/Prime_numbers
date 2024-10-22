#include <math.h>
#include <stdio.h>
#include <stdbool.h>
int is_prime(int n);


int main(void) {
    int number = 0;
    while(scanf("%d", &number)==1 && number != 0) {

        if(is_prime(number))
            printf("Prvociselny rozklad cisla %d je:\n%d\n", number, number);

        else {
            int counter = 0; //
            for(int i = 2; i <= (number); i++) { //10 = 2s x 5 ; 2^3

                while (number % i == 0) {
                    counter ++;
                    number = number / i;
                }
                // if (counter > 0) {
                if (counter == 1) {
                    printf("%d\n", i);
                    counter = 0;
                }
                else if (counter > 1)  {
                    printf("%d^%d\n", i, counter);
                    counter = 0;

                }
                // }


            }

        }
    }

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
