#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_set>
using ll = long long;
using namespace std;

void solve() {
	ll n, m;
	cin >> n >> m;

	vector<ll> ovens(n);

	for (int i = 0; i < n; i++) {
		cin >> ovens[i];
	}

	// sort the ovens from greatest to least
	sort(ovens.begin(),ovens.end(), greater<int>());

	ll ans = 0;
	ll multiplier = m;

	for (int i = 0; i < n; i++) {
		if (multiplier == 0) {
			break;
		}
		ans += (ovens[i] * multiplier);
		multiplier--;
	}

	cout << ans << '\n';

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
- obviously one of the most optimal actions is to wait for the cakes to accumulate at a given oven - especially the one
that produces the most cakes

m = number of teleports that you have



*/