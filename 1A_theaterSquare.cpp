#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

/*
key idea = always use long long when you have a really really big number - i.e 10^7 usually. otherwise the computer can't handle it - in addition, ceiling and floor operator are useful.
*/

int main() {
	long long n, m, a;

	cin >> n >> m >> a;

	long long required_n = (n + a - 1) / a;
	long long required_m = (m + a - 1) / a;
	
	cout << required_n * required_m << endl;


	return 0;
}



/*
- repeaet the first operation unitl we get a 5*n / 4*n / 3*n / 2*n / 1*n set up

ALGORITHM
1. 

*/
