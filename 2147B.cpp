#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    
    vector<int> a(n*2);
    
    a[0] = n;
    a[n] = n;

    int index = 1;
    for (int i = n - 1; i > 0; i--) {
        a[index] = i;
        int next_index = index + (2*i);
        a[next_index] = i;
        index++;
    }

    for (int i = 0; i < n*2; i++) {
        cout << a[i] << " ";
    }

    cout << '\n';
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