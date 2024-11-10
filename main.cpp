/*
 * Aidan Levy
 * Creation: 11-9-24
 * Description:
 *  Breaks a number down into its prime factors
 */

#include <iostream> 
#include <vector>
#include <cmath>
using namespace std;

void getNum(unsigned long long&);
void getPrimes(vector<unsigned long long>&, unsigned long long);
void factorize(vector<unsigned long long>&, unsigned long long);
void print(vector<unsigned long long>&, string);

int main() {
    
    // vars
    unsigned long long num;
    vector<unsigned long long> primes;
    
    // get input from user 
    getNum(num);
    
    // If number is 1
    if (num == 1) {
        cout << "The only factor of 1 is 1." << endl;
        return 0;
    }
    
    // find prime numbers
    getPrimes(primes, num);
    
    try {
        factorize(primes, num);
    } catch (const string& e) {
        cout << e << endl;
    }
    
    return 0;
}

void getNum(unsigned long long& n) {
    do {
        cout << "Please enter a positive integer: ";
        cin >> n;
    } while (n < 1);
}

void getPrimes(vector<unsigned long long>& primes, unsigned long long num) {
    vector<bool> isPrime(num+1, true);
    isPrime[0] = isPrime[1] = false;
    
    for (unsigned long long i = 2; i*i <= num; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
            for (unsigned long long j = i * i; j <= num; j += i) {
                isPrime[j] = false;
            }
        }
    }
}

void factorize(vector<unsigned long long>& primes, unsigned long long num) {
    vector<unsigned long long> factors;
    unsigned long long oNum = num;

    // find factors
    for (unsigned long long i = 0; i < primes.size(); i++) {
        while (num % primes[i] == 0) {
            factors.push_back(primes[i]);
            num /= primes[i];
        }
    }
    
    // if num is greater than 1, it is a prime number
    if (num > 1)
        factors.push_back(num);
    
    // Ensure correct factorization
    unsigned long long total = 1;
    for (unsigned long long f : factors)
        total *= f;

    // check if the total == the original number
    if (total == oNum)
        print(factors, "Prime Factors:");
    else
        throw "Error: Incorrect factors.";
}

void print(vector<unsigned long long>& v, string m) {
    cout << m << endl;
    for (unsigned long long i : v)
        cout << i << " ";
    cout << endl;
}
