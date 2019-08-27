#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include "primes.h"


int main(int argc, char const *argv[]) {
    
    if(argc != 4) {
        printf("Wrong arguments\n");
        return 1;
    } 

    int array_size = atoi(argv[1]);
    const char mode = *argv[2];
    int thread_number = atoi(argv[3]);

    char* primes = alloc_primes(array_size);

    struct timeval start_time;
    gettimeofday(&start_time, NULL);
    
    if (thread_number < 2) {
        primes = find_primes(primes, array_size);
    }
    else {
        parallel_find_primes(primes, array_size, thread_number);
    }
    
    struct timeval end_time;
    gettimeofday(&end_time, NULL);
    
    if (mode == 'l' || mode == 'a') {
        print_primes(primes, array_size);
    }
    
    if (mode == 't' || mode == 'a') {
        printf("%.6f\n", ((end_time.tv_sec - start_time.tv_sec) * 1000000u + end_time.tv_usec - start_time.tv_usec) / 1e6);
    }
    
    free_primes(primes);

    return 0;
}
