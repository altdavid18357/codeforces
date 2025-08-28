#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_set>
using namespace std;

void solve() {
	int n;
	cin >> n;

	vector<int> a(n);
	vector<int> b(n);

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}

	int ans = 0;

	for (int i = 0; i < n; i++) {
		int diff = a[i] - b[i];
		
		if (diff > 0) {
			ans += diff;
		}

	}

	cout << ans + 1 << endl;


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