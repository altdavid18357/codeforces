#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <numeric>
#include <deque>
using ll = long long;
using namespace std;

void solve() {
	int n;
	cin >> n;

	deque<int> a(n);
	for (int i = 0; i < n; ++i) cin >> a[i];

	deque<int> dq;
	string ans;

	int i = 1;

	while (!a.empty()) {
		int left = a.front();
		int right = a.back();

		if (i % 2 == 0) {
			if (max(left,right) == left) {
				ans += 'L';
				a.pop_front();
			} else {
				ans += 'R';
				a.pop_back();
			}
		} else if (i % 2 == 1) {
			if (min(left,right) == left) {
				ans += 'L';
				a.pop_front();
			} else {
				ans += 'R';
				a.pop_back();
			}
		}

		i++;
	}

	cout << ans << '\n';

	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while (t--) solve();
}
