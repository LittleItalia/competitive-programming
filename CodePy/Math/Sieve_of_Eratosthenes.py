# Sang nguyen to O(n)

def sieve(n):   
    min_prime = [0] * (n + 1)
    primes = []

    for i in range(2, n + 1, 1):
        if min_prime[i] == 0:
            min_prime[i] = i
            primes.append(i)

        for j in range(0,  n + 1, 1):
            if i * primes[j] > n:
                break

            min_prime[i * primes[j]] = primes[j]
            if primes[j] == min_prime[i]:
                break

    return primes
