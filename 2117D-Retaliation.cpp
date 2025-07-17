#include <iostream>
#include <string>
#include <vector>
using namespace std;


void solve() {
	int n;
		cin >> n;
		
		vector<long long> array(n);

		for (auto &it: array) {
			cin >> it;
		}

		bool bad = false;
		long long diff = array[1] - array[0];

		for (int i = 2; i < n; i++) {
			if (diff != array[i] - array[i-1]) {
				bad = true;
			}
		}

		if (bad) {
			cout << "NO" << endl;
			return;
		}

		for (int i = 0; i < n; i++) {
			if (diff < 0) {
				array[i] = array[i] + diff * (n - i);
			} else {
				array[i] = array[i] - diff * (i + 1);
			}

		}

		cout << (array[0] >= 0 && array[0] % (n+1) == 0 ? "YES": "NO") << endl;
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		solve();
	}

	return 0;
}



/*
- repeaet the first operation unitl we get a 5*n / 4*n / 3*n / 2*n / 1*n set up

ALGORITHM
1. 

*/