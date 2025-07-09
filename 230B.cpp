#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <sstream>
#include <string>
#include <cmath>
using namespace std;

bool isPrime(long long n) {
    if (n < 2) return false;
    for (int i = 2; i*i <= n; ++i)
        if (n % i == 0) return false;
    return true;
}

int main() {
    int n;
    std::cin >> n;

    std::cin.ignore(); // ignore the newline character after the number

    std::string line;
    std::getline(std::cin, line); // read the full line of numbers

    std::istringstream iss(line);
    long long x;

    for (int i = 0; i < n; ++i) {
        iss >> x;
        
		long long sr = sqrt(x);
		if (sr * sr != x) {
			cout << "NO\n";
			continue;
		}
		if (isPrime(sr)) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
    }

    return 0;
}

/*
thoughts
- essentially the number has to be a square of a prime number

*/