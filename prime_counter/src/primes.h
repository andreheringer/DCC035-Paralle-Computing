#if !defined(PRIMES)
#define PRIMES

#define PRIMES_OFFSET 2

int *find_primes(int*, int);
//int* calculate_multiples(int* array, int begin, int size);
int *alloc_primes(int size);
void free_primes();
void print_primes(int* array, int size);
void parallel_find_primes(int *array, int size, int num_threads);

#endif // PRIMES
