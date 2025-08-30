#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

void solve() {
	int n, s, tmp;
	cin >> n >> s;

    vector<int> a(3);
    

    for (int i = 0; i < n; i++) {
        cin >> tmp;
        a[tmp]++;
    }

    if (a[1] + a[2]*2 == s || s >= a[1] + a[2]*2 + 2) {              // if difference between total and s is 1, then we can stop alice, otherwise if the dif is greater than 1, then we can't
        cout << -1 << '\n';
        return;
    }

    // otherwise we can stop alice by placing all the zeros at the beginning, then all the twos, then all the 0s, then we can get to a place where there is no 1 increment possible :) -- > then alice cannot win
    for (int i=0; i < a[0]; i++) cout << 0 << ' ';
    for (int i=0; i < a[2]; i++) cout << 2 << ' ';
    for (int i=0; i < a[1]; i++) cout << 1 << ' ';

    return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while (t--) solve();
}