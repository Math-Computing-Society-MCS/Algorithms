// prime number generation upto 'n' using standard sieve of eratosthenes
// source: https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes#Overview

#include<iostream>

using namespace std;

//sieve of eratosthenes, prints the output to stdout
void SOE (int n) {

    //boolean array. true = prime, false = not prime. 
    bool primeArray[n+1]; //size = n+1 for avoiding confusions 

    //setting every elements to prime (from 2 to n, ignore the rest)
    for (int i=2; i<=n; i++) {
        primeArray[i] = true;
    }

    //processing each number if it is set to prime upto n
    for (int i=2; i<=n; i++) {
        if (primeArray[i]==true) {
            //mark all the multimples of i (excluding i) to not-prime upto n
            int iMultiple = i + i;
            while (iMultiple <= n) {
                primeArray[iMultiple] = false;
                iMultiple += i;
            }
        }
    }

    //printing the primes
    cout << "primes upto " << n << ": " << endl;
    for (int i = 2; i <= n; i++) {
        if (primeArray[i] == true) cout << i << " ";        
    }
    cout << endl;   

}

int main() {
    int n;

    cout << "Enter the value for n: ";
    cin >> n;

    //simple error check :)
    if (n < 2) {
        cout << "wrong input..." << endl;
        return 0;
    } 

    SOE(n);
    return 0;
}