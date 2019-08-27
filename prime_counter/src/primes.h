#if !defined(PRIMES)
#define PRIMES

#define PRIMES_OFFSET 2

char *find_primes(char*, int);
//int* calculate_multiples(int* array, int begin, int size);
char *alloc_primes(int size);
void free_primes();
void print_primes(char* array, int size);
void parallel_find_primes(char *array, int size, int num_threads);

#endif // PRIMES
