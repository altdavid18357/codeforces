#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve() {
	int n;
	cin >> n;

	vector<long long> list(n);
	for (int i = 0; i < n; i++) {
		cin >> list[i];
	}

	vector<long long> prefix_max(n);
	prefix_max[0] = list[0];
	for (int i = 1; i < n; i++) {
		prefix_max[i] = max(prefix_max[i - 1], list[i]);
	}

	vector<long long> suffix_sum(n + 1, 0); // 1 extra for safety
	for (int i = n - 1; i >= 0; i--) {
		suffix_sum[i] = list[i] + suffix_sum[i + 1];
	}

	for (int k = 1; k <= n; k++) {
		int edge_index = n - k;

		long long maximum = prefix_max[edge_index];
		long long count = 0;

		if (list[edge_index] >= maximum) {
			count = suffix_sum[edge_index];
		} else {
			count = maximum + suffix_sum[edge_index + 1];
		}

		cout << count << '\n';
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while (t--) solve();
}
