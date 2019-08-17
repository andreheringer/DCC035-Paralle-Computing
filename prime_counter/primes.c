#include <stdlib.h>
#include "primes.h"

void free_primes(int* array) {

}

int* alloc_primes(int size_t) {
    int* new_array = calloc(sizeof(int), size_t);
    return new_array;
}

int* calculate_multiples(int* array, int begin, int size_t) {
    
    int prime_key = begin;
    begin++;
    
    for (int i = begin; i < size_t; i++) {
        if (i % prime_key == 0) {   
             array[i] = 1;
        }
    }

    return array;
}

int* find_primes(int* array, int size_t) {

    for (int i = 0; i < size_t; i++)
    {
        array = calculate_multiples(array, i, size_t);
    }
    
    return array;
}
