#include <stdlib.h>
#include <stdio.h>
#include <omp.h>
#include "primes.h"

void free_primes(int *array) {
    free(array);
}

int *alloc_primes(int size) {
    int *new_array = calloc(sizeof(int), size);
    return new_array;
}

int* calculate_multiples(int *array, int begin, int size) {

    int prime_key = begin;
    begin++;
    
    for (int i = begin; i < size; i++) {
        if (i % prime_key == 0) {   
            array[i] = 1;
        }
    }
    return array;

}

void parallel_find_primes(int *array, int size, int num_threads) {

    #pragma omp parallel for num_threads(num_threads) schedule(static, 1)
    for (int i = PRIMES_OFFSET; i < size; i++) {
        calculate_multiples(array, i, size);
    }
}

int *find_primes(int *array, int size) {

    for (int i = PRIMES_OFFSET; i < size; i++) {
        calculate_multiples(array, i, size);
    }
    
    return array;
}

void print_primes(int* array, int size) {
    
    for (int i = PRIMES_OFFSET; i < size; i++) {
        if(!array[i]) {
            printf("%d ", i);
        }
    }
    printf("\n");
}