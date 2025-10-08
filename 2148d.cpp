#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> a;
	a.reserve(n);

	for (int i = 0; i < n; ++i) {
		int set_size;
		cin >> set_size;

		vector<int> temp;
        temp.reserve(set_size);
        for (int j = 0; j < set_size; ++j) {
            int x; cin >> x;
            temp.push_back(x-1);
        }

        a.push_back(temp);
	}

    vector<int> cnt(m);
    for (int i = 0; i < m; i++) {
        cnt[i] = 0;
    }
    int t = 0; 

    for (int i = 0; i < n; i++) {
        
        for (int j = 0; j < a[i].size(); j++) {
            int x = a[i][j];
            if (cnt[x] == 0) {
                t++;
            }
            cnt[x]++;
        }
    }

    int ans = (t == m); 

    for (int i = 0; i < n; i++) {
        for (int num: a[i]) {
            cnt[num] -= 1;
            if (cnt[num] == 0) {
                t--;
            }
        }

        if (t==m) ans++;

        for (int num: a[i]) {
            if (cnt[num] == 0) t++;
            cnt[num]++;
        }
    }

    cout << (ans >= 3 ? "YES \n": "NO \n"); 

    return;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}


/*

*/