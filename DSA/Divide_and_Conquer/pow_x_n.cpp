#include <iostream>
using namespace std;

// Function to calculate x^n using Binary Exponentiation
double myPow(double x, int n) {

    // Handle edge cases

    // Any number raised to the power 0 is 1
    if (n == 0) return 1.0;

    // 0 raised to any positive power is 0
    if (x == 0) return 0.0;

    // 1 raised to any power is always 1
    if (x == 1) return 1.0;

    // (-1) raised to an even power is 1
    if (x == -1 && n % 2 == 0) return 1.0;

    // (-1) raised to an odd power is -1
    if (x == -1 && n % 2 != 0) return -1.0;

    // Store exponent as long long to handle INT_MIN safely
    long long power = n;

    // Initialize answer
    double ans = 1.0;

    // If exponent is negative,
    // invert the base and make exponent positive
    if (power < 0) {
        x = 1.0 / x;
        power = -power;
    }

    // Binary Exponentiation
    while (power > 0) {

        // If the current binary bit is 1,
        // multiply the current base into the answer
        if (power % 2 == 1) {
            ans *= x;
        }

        // Square the base
        x *= x;

        // Move to the next binary bit
        power /= 2;
    }

    return ans;
}

int main() {

    double x;
    int n;

    cout << "Enter base (x): ";
    cin >> x;

    cout << "Enter exponent (n): ";
    cin >> n;

    cout << "\nResult = " << myPow(x, n) << endl;

    return 0;
} 

/*
2^10
power = 10  (binary: 1010),  x = 2,  ans = 1

step 1: power=10, 10%2=0 → skip,        x = 2×2 = 4,     power = 5
step 2: power=5,  5%2=1  → ans = 1×4=4, x = 4×4 = 16,    power = 2
step 3: power=2,  2%2=0  → skip,        x = 16×16 = 256,  power = 1
step 4: power=1,  1%2=1  → ans = 4×256=1024, x = 256×256, power = 0

loop ends → return 1024 ✓

2^-2
power = -2  →  flip x = 1/2 = 0.5,  power = 2
power = 2  (binary: 10),  x = 0.5,  ans = 1

step 1: power=2,  2%2=0 → skip,           x = 0.5×0.5 = 0.25,  power = 1
step 2: power=1,  1%2=1 → ans = 1×0.25=0.25, x = 0.25×0.25,   power = 0

loop ends → return 0.25 ✓
(which is 1/4 = 2^-2 ✓)

2^3
power = 3  (binary: 11),  x = 2,  ans = 1

step 1: power=3,  3%2=1 → ans = 1×2=2,  x = 2×2 = 4,   power = 1
step 2: power=1,  1%2=1 → ans = 2×4=8,  x = 4×4 = 16,  power = 0

loop ends → return 8 ✓
*/