#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int misorderings(vector<int> a, int n) {
    int first_zero_index = -1;
    int zero_count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            zero_count++;
            if (first_zero_index == -1) {
                first_zero_index = i;
            }
        }
    }

    int count = 1;
    int first_index = 400000;
    int last_index = -1;
    for (int i = 0; i < n; i++) {
        if (a[i] != count) {
            first_index = min(i, first_index);
            last_index = max(last_index, i);
        }
        count++;
    }

    if (first_index == 400000) {
        return 0;
    } else if (zero_count == 1) {
        for (int i = 0; i < n; i++) {
            if (first_zero_index + 1 == a[i]) {
                return last_index - first_index + 1;
            }
        }
        a[first_zero_index] = first_zero_index + 1;
        return misorderings(a, n);
    } else {
        return last_index - first_index + 1; // <-- fixed here
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << misorderings(a, n) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
