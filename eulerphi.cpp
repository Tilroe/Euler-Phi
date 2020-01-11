// ==============================
//  Name: Rowan Tilroe
//  ID: 1629172
//  CMPUT 274, Fall 2019
//
//  Weekly Exercise 7: Euler phi
// ==============================

#include <iostream>
#include <cmath> // for sqrt
#include <iomanip>

using namespace std;

// Fast GCD function posted on eclass
uint32_t gcd_euclid_fast(uint32_t a, uint32_t b) {
    while (b > 0) {
        a %= b;

        // now swap them
        uint32_t tmp = a;
        a = b;
        b = tmp;
    }
    return a; // b is 0
}

unsigned int phi(unsigned int n) {
    uint32_t nprime = n;
    uint32_t phin = n;

    // Repeat below process until nprime reaches 1
    while (nprime != 1) {
        
        uint32_t sqrtnprime = sqrt(nprime);
        uint32_t p = 2;
        bool primeFound = false;
        
        // Find smallest prime between 2 and sqrt(nprime)
        while ((not primeFound) && (p <= sqrtnprime)) {

            if (nprime%p == 0) {
                // Prime found that divides n
                primeFound = true;
            }
            p++;
        }

        // Adjust p after loop
        p = p-1;
        if (not primeFound) {
            p = nprime;
        }

        // Repeatedly divide nprime by p until it can't divide anymore => find next nprime
        while (nprime%p == 0) {
            nprime = nprime/p;
        }

        // Update phi(n) with the p found in this loop iteration
        // Redo loop with new nprime until n' = 1
        phin = (phin/p) * (p-1);
    }

    return phin;
}


int main() {
    // Get n and display it
    uint32_t n;
    cin >> n;
    cout << "n           = " << n << endl;

    // Compute phi(n) and display
    uint32_t phin;
    phin = phi(n);
    cout << "phi(n)      = " << phin << endl;

    // Compute phi(n)/n and display
    double phinOVERn = double(phin)/double(n);
    cout << "phi(n)/n    = ";
    cout << fixed << setprecision(5) << phinOVERn << endl;

    // Compute 15-bit test and display if necessary
    if (n >= (1<<15)) {
        // Iterate through all k between 2^14 <= k < 2^15 and check if
        // GCD(n,k) = 1. Keep track of amount of times that is true.
        uint32_t x = 0;

        for (uint32_t k = (1<<14); k < (1<<15); k++) {
            if (gcd_euclid_fast(n,k) == 1) {
                x++;
            }
        }

        // Display result
        double fifteenBitTest = double(x)/double(1<<14);
        cout << "15-bit test = ";
        cout << fixed << setprecision(5) << fifteenBitTest << endl;
    }

    return 0;
}