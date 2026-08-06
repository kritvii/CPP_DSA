// LC 204 - Count Primes
// Pattern : Sieve of Eratosthenes
// Time    : O(n log log n)  |  Space : O(n)

// WHY O(n log log n)?
// much faster than brute force O(n√n)
// n=5,000,000 → brute=11 billion ops, sieve=~17 million ops

// Core idea: instead of checking each number individually
// eliminate all multiples of every prime → whatever is left is prime
// start marking from p*p not p*2 →
// smaller multiples already marked by previous primes

class Solution {
public:
    int countPrimes(int n) {

        if(n < 2) return 0;

        // sieve — mark everyone as prime initially
        // true = prime, false = not prime
        vector<bool>isPrime(n, true);

        // 0 and 1 are not prime
        isPrime[0] = false;
        isPrime[1] = false;

        // start from p=2, go till sqrt(n)
        // no need to check beyond sqrt(n) — larger factors already marked
        for(int p = 2; p * p < n; p++) {

            // if p is still marked prime → mark its multiples
            if(isPrime[p]) {

                // start from p*p — smaller multiples already marked
                // mark p*p, p*p+p, p*p+2p... as not prime
                for(int j = p*p; j < n; j += p) {
                    isPrime[j] = false;
                }
            }
        }

        // count remaining primes
        int count = 0;
        for(int i = 2; i < n; i++) {
            if(isPrime[i]) count++;
        }

        return count;
    }
};

// DRY RUN: n=10
// isPrime = [F,F,T,T,T,T,T,T,T,T]
// p=2: mark 4,6,8 → [F,F,T,T,F,T,F,T,F,T]
// p=3: mark 9    → [F,F,T,T,F,T,F,T,F,F]
// p=4: 4*4=16 >= 10 → loop ends
// count T's from 2: 2,3,5,7 → return 4 ✓

// BRUTE VS SIEVE:
// brute  → O(n√n)        → TLE for large n
// sieve  → O(n log log n) → passes ✓

// TRAPS:
// ❌ starting inner loop from p*2 → revisits already marked numbers
// ✅ start from p*p → smaller multiples already marked by previous primes
// ❌ outer loop till n → unnecessary, larger factors already handled
// ✅ outer loop till sqrt(n) → p*p < n