#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "primes.h"


int main(int argc, char const *argv[]) {
    
    if(argc != 4) {
        printf("Wrong arguments\n");
        return 1;
    } 

    int array_size = atoi(argv[1]);
    const char mode = *argv[2];
    int thread_number = atoi(argv[3]);

    int* primes = alloc_primes(array_size);

    clock_t start_time = clock();
    
    if (thread_number < 2) {
        primes = find_primes(primes, array_size);
    }
    else {
        parallel_find_primes(primes, array_size, thread_number);
    }
    
    clock_t end_time = clock();
    
    if (mode == 'l' || mode == 'a') {
        print_primes(primes, array_size);
    }
    
    if (mode == 't' || mode == 'a') {
        printf("%.6lf\n", (double)(end_time - start_time) / CLOCKS_PER_SEC);
    }
    
    free_primes(primes);

    return 0;
}
