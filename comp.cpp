#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n, k;
	cin >> n >> k;

	vector<int> a(n);
	int occurrences_of_k = 0;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] == k) occurrences_of_k++;
	}

	sort(a.begin(), a.end());

	int idx = 0;               
	int missing_numbers = 0;  

	for (int x = 0; x < k; x++) {
		while (idx < n && a[idx] < x) idx++;
		if (idx < n && a[idx] == x) {
			idx++;
		} else {
			missing_numbers++;
		}
	}

	cout << max(missing_numbers, occurrences_of_k) << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	if (!(cin >> t)) return 0;
	while (t--) solve();
	return 0;
}
