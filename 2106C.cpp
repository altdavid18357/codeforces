#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_set>
using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;

	vector<int> a(n);
	vector<int> b(n);

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}

	// first see if it's even possible by checking if all the sums currently in the thing are the same
	int tmp = -1;
	for (int i = 0; i < n; i++) {
		if (b[i] != -1) {

			if (tmp == -1) {			// if first sum found
				tmp = a[i] + b[i];
			} else {
				if (a[i] + b[i] != tmp) {
					cout << 0 << '\n';
					return;
				}
			}
		}
	}

	auto _max = max_element(a.begin(), a.end());
	auto _min = min_element(a.begin(), a.end());

	// if the two arrays are valid, then...

	// if one set is already made, then this is a special situation

	if (tmp != -1) {
		if (*_min + k < tmp || tmp < *_max) {
			cout << 0 << '\n';
			return;
		} 
		else {
			cout << 1 << '\n';
			return;
		}
	}


	// if not sets made, then...
	cout << (*_min + k) - *_max + 1 << '\n';
	return;

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while (t--) solve();
}

/*
initial thoughts

after how many iterations does there exist of total separation between a and b

*/