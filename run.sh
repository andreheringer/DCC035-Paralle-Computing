echo "Going from 100 to 1000000000"

echo "Runing primes sequential" >> log.txt

./release/primes 100 t 1 >> log.txt
./release/primes 1000 t 1 >> log.txt
./release/primes 10000 t 1 >> log.txt
./release/primes 100000 t 1 >> log.txt
./release/primes 1000000 t 1 >> log.txt
./release/primes 10000000 t 1 >> log.txt
./release/primes 100000000 t 1 >> log.txt
./release/primes 1000000000 t 1 >> log.txt

echo "Runing primes 2 threads" >> log.txt

./release/primes 100 t 2 >> log.txt
./release/primes 1000 t 2 >> log.txt
./release/primes 10000 t 2 >> log.txt
./release/primes 100000 t 2 >> log.txt
./release/primes 1000000 t 2 >> log.txt
./release/primes 10000000 t 2 >> log.txt
./release/primes 100000000 t 2 >> log.txt
./release/primes 1000000000 t 2 >> log.txt

echo "Runing primes 3 threads" >> log.txt

./release/primes 100 t 3 >> log.txt
./release/primes 1000 t 3 >> log.txt
./release/primes 10000 t 3 >> log.txt
./release/primes 100000 t 3 >> log.txt
./release/primes 1000000 t 3 >> log.txt
./release/primes 10000000 t 3 >> log.txt
./release/primes 100000000 t 3 >> log.txt
./release/primes 1000000000 t 3 >> log.txt

echo "Runing primes 4 threads" >> log.txt

./release/primes 100 t 4 >> log.txt
./release/primes 1000 t 4 >> log.txt
./release/primes 10000 t 4 >> log.txt
./release/primes 100000 t 4 >> log.txt
./release/primes 1000000 t 4 >> log.txt
./release/primes 10000000 t 4 >> log.txt
./release/primes 100000000 t 4 >> log.txt
./release/primes 1000000000 t 4 >> log.txt

echo "Runing primes 5 threads" >> log.txt

./release/primes 100 t 5 >> log.txt
./release/primes 1000 t 5 >> log.txt
./release/primes 10000 t 5 >> log.txt
./release/primes 100000 t 5 >> log.txt
./release/primes 1000000 t 5 >> log.txt
./release/primes 10000000 t 5 >> log.txt
./release/primes 100000000 t 5 >> log.txt
./release/primes 1000000000 t 5 >> log.txt

echo "Runing primes 6 threads" >> log.txt

./release/primes 100 t 6 >> log.txt
./release/primes 1000 t 6 >> log.txt
./release/primes 10000 t 6 >> log.txt
./release/primes 100000 t 6 >> log.txt
./release/primes 1000000 t 6 >> log.txt
./release/primes 10000000 t 6 >> log.txt
./release/primes 100000000 t 6 >> log.txt
./release/primes 1000000000 t 6 >> log.txt

echo "Runing primes 7 threads" >> log.txt

./release/primes 100 t 7 >> log.txt
./release/primes 1000 t 7 >> log.txt
./release/primes 10000 t 7 >> log.txt
./release/primes 100000 t 7 >> log.txt
./release/primes 1000000 t 7 >> log.txt
./release/primes 10000000 t 7 >> log.txt
./release/primes 100000000 t 7 >> log.txt
./release/primes 1000000000 t 7 >> log.txt

echo "Runing primes 8 threads" >> log.txt

./release/primes 100 t 8 >> log.txt
./release/primes 1000 t 8 >> log.txt
./release/primes 10000 t 8 >> log.txt
./release/primes 100000 t 8 >> log.txt
./release/primes 1000000 t 8 >> log.txt
./release/primes 10000000 t 8 >> log.txt
./release/primes 100000000 t 8 >> log.txt
./release/primes 1000000000 t 8 >> log.txt

echo "Done :)"

done