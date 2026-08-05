Here's a clean, standalone explanation for your notes.

---

## Sieve of Eratosthenes — Notes

**Purpose:** Find all prime numbers up to a given limit `n`, efficiently — much faster than checking each number individually for primality.

**Core idea:** Instead of asking *"is this number prime?"* for every number one by one, flip the approach: start from each prime you find, and **mark all its multiples as composite** (not prime). Whatever never gets marked by the end must be prime.

**Why it's fast:** Checking primality of a single number by trial division takes up to O(√n) time. Doing that for every number from 2 to n would be O(n√n) total. The sieve instead does bulk elimination — O(n log log n) total — by reusing the work: once you know 2 is prime, you instantly rule out every multiple of 2 in one sweep, instead of re-testing each of them individually.

**Steps:**
1. Create a boolean array of size `n`, initialize all entries to `true` (assume everyone is prime).
2. Mark index `0` and `1` as `false` (not prime, by definition).
3. Starting from `p = 2`, for each `p` still marked `true`:
   - Mark all multiples of `p`, starting from `p*p`, as `false`.
4. Only need to do this for `p` up to `√n` — beyond that, all composites are already caught.
5. Whatever remains `true` in the array is prime.

**Why start marking from `p*p`, not `2p`:**
Any smaller multiple of `p` (like `2p`, `3p`, ..., `(p-1)p`) already has a smaller prime factor, so it would have been marked `false` by an earlier, smaller prime already. Starting at `p*p` avoids redundant work.

**Why only sieve up to `√n`:**
If a number `x ≤ n` is composite, it must have at least one factor ≤ `√x` ≤ `√n`. So by the time you've sieved with every prime up to `√n`, every composite number in the range has already been caught by one of its smaller factors.

**Example: n = 30**

```
Start: all true (except 0, 1)

p=2 (prime): mark 4,6,8,10,12,14,16,18,20,22,24,26,28,30 as false
p=3 (prime): mark 9,12,15,18,21,24,27,30 as false
p=4: already false (composite), skip
p=5 (prime): mark 25,30 as false
p=6: 6*6=36 > 30 -> stop (no more sieving needed)

Remaining true: 2, 3, 5, 7, 11, 13, 17, 19, 23, 29
```

**Code:**

```cpp
vector<bool> isPrime(n, true);
isPrime[0] = false;
isPrime[1] = false;

for(int p = 2; p * p < n; p++){
    if(isPrime[p]){
        for(int j = p*p; j < n; j += p){
            isPrime[j] = false;
        }
    }
}
```

**Time Complexity:** O(n log log n) — considered near-linear in practice
**Space Complexity:** O(n) — the boolean array

**Common use case:** Any problem asking to count/find/list all primes up to some limit `n` — much better than checking each number individually when `n` is large.