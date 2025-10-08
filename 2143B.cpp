#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<ll> prices(n);
    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }

    vector<ll> discounts(k);
    for (int i = 0; i < k; i++) {
        cin >> discounts[i];
    }

    // sort prices in descending order
    sort(prices.begin(), prices.end(), greater<ll>());
    // sort discounts in ascencing order
    sort(discounts.begin(), discounts.end());

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans += prices[i];
    }

    int index = 0;
    for (int i = 0; i < k; i++) {
        int group_size = discounts[i];

        if (index + group_size - 1 > prices.size() - 1) {       // if out of bounds
            break;
        }
        
        // loop through prices and form a group
        ans -= prices[index + group_size - 1];

        index = index + group_size;

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
    return 0;
}


/*

*/