# Weekly Exercise 7: Euler phi
* Name: Rowan Tilroe
* ID: 1629172
* CMPUT 274, Fall 2019


## Included Files:
* README
* eulerphi.cpp

## Running instruction:
1. In the directory containing eulerphi.cpp, type "g++ eulerphi.cpp -o eulerphi" to compile the program.
2. Once the program had been compiled, type "./eulerphi" to run the program.
3. Enter a number of your choice to view the relevant output.

## Notes & Assumptions:
* The function gcd_euclid_fast() was downloaded from eclass and used.
* This program assumes an input range of [1, 2^32 -1].
* The function phi() does not store all of the prime factors of n. Instead, it updates the value of phi(n) after each loop for a given nprime with its lowest prime factor.
* In the phi() function, a small adjustment had to be made to the p found. This is because in the case where a p WAS found, an extra 1 was added to it at the end of the loop. If a p WAS NOT found, the remaining p is incorrect and is in fact equal to nprime.
