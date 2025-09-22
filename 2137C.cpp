#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;

// multiply two ulls into a decimal string
string mul_to_string(ull a, ull b) {
    if (a == 0 || b == 0) return "0";
    string sa = to_string(a), sb = to_string(b);
    int na = sa.size(), nb = sb.size();
    vector<int> res(na + nb);
    for (int i = na - 1; i >= 0; --i) {
        for (int j = nb - 1; j >= 0; --j) {
            int da = sa[i] - '0';
            int db = sb[j] - '0';
            res[i + j + 1] += da * db;
        }
    }
    for (int k = na + nb - 1; k > 0; --k) {
        if (res[k] >= 10) {
            res[k - 1] += res[k] / 10;
            res[k] %= 10;
        }
    }
    string out;
    int start = 0;
    while (start < (int)res.size() && res[start] == 0) ++start;
    for (int i = start; i < (int)res.size(); ++i) out.push_back(char('0' + res[i]));
    if (out.empty()) return "0";
    return out;
}

// add a small ull to a decimal string representing a non-negative integer
string add_small_to_string(const string &s, ull add) {
    string out = s;
    // add to out from right to left
    int i = (int)out.size() - 1;
    unsigned long long carry = add;
    while (i >= 0 && carry > 0) {
        unsigned long long digit = out[i] - '0';
        unsigned long long sum = digit + (carry % 10ULL);
        // incorporate carry digit-by-digit properly:
        // we will add whole carry by converting carry to string and adding,
        // but simpler: convert add to string and do digit addition once.
        --i;
    }
    // simpler robust approach: convert add to string and do string addition
    string add_s = to_string(add);
    // add out + add_s
    string a = out, b = add_s;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    string res;
    int n = max(a.size(), b.size());
    int carry_digit = 0;
    for (int k = 0; k < n; ++k) {
        int da = (k < (int)a.size() ? a[k] - '0' : 0);
        int db = (k < (int)b.size() ? b[k] - '0' : 0);
        int ssum = da + db + carry_digit;
        res.push_back(char('0' + (ssum % 10)));
        carry_digit = ssum / 10;
    }
    while (carry_digit) {
        res.push_back(char('0' + (carry_digit % 10)));
        carry_digit /= 10;
    }
    reverse(res.begin(), res.end());
    // remove leading zeros (shouldn't be any)
    int pos = 0;
    while (pos + 1 < (int)res.size() && res[pos] == '0') ++pos;
    return res.substr(pos);
}

// add two decimal strings (non-negative integers)
string add_strings(const string &A, const string &B) {
    string a = A, b = B;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    string res;
    int n = max(a.size(), b.size());
    int carry = 0;
    for (int i = 0; i < n; ++i) {
        int da = i < (int)a.size() ? a[i] - '0' : 0;
        int db = i < (int)b.size() ? b[i] - '0' : 0;
        int s = da + db + carry;
        res.push_back(char('0' + (s % 10)));
        carry = s / 10;
    }
    while (carry) {
        res.push_back(char('0' + (carry % 10)));
        carry /= 10;
    }
    reverse(res.begin(), res.end());
    int pos = 0;
    while (pos + 1 < (int)res.size() && res[pos] == '0') ++pos;
    return res.substr(pos);
}

// compare non-negative decimal strings: return true if A < B
bool decimal_less(const string &A, const string &B) {
    if (A.size() != B.size()) return A.size() < B.size();
    return A < B;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        unsigned long long a, b;
        cin >> a >> b;
        if (b == 0) { // undefined divisors, follow previous behavior
            cout << -1 << "\n";
            continue;
        }

        // gather candidate divisors (unique)
        vector<unsigned long long> cand;
        auto push_unique = [&](unsigned long long d){
            if (d == 0) return;
            if (find(cand.begin(), cand.end(), d) == cand.end()) cand.push_back(d);
        };
        push_unique(1ULL);
        push_unique(b);
        if (b % 2 == 0) {
            push_unique(2ULL);
            push_unique(b / 2ULL);
        }

        string best_str = ""; // keep decimal string of best sum
        bool found = false;

        for (ull d : cand) {
            // parity check without multiplication:
            // parity(a*d) = (a%2)*(d%2)
            int parity_ad = (int)(a & 1ULL) * (int)(d & 1ULL);
            ull kd = b / d;
            int parity_k = (int)(kd & 1ULL);
            if ((parity_ad + parity_k) % 2 != 0) continue; // not even sum

            // compute S = a*d + b/d
            // try to compute in ull if safe
            bool mul_overflow = false;
            ull prod = 0;
            if (a != 0 && d > 0 && a > ULLONG_MAX / d) {
                mul_overflow = true;
            } else {
                prod = a * d;
            }
            if (!mul_overflow) {
                // addition overflow?
                ull addend = kd;
                if (prod > ULLONG_MAX - addend) {
                    mul_overflow = true;
                } else {
                    ull sum = prod + addend;
                    string sum_s = to_string(sum);
                    if (!found || decimal_less(best_str, sum_s)) {
                        best_str = sum_s;
                        found = true;
                    }
                    continue;
                }
            }
            // overflow path: compute using decimal-string big-int
            string prod_s = mul_to_string(a, d);
            string kd_s = to_string(kd);
            string sum_s = add_strings(prod_s, kd_s);
            if (!found || decimal_less(best_str, sum_s)) {
                best_str = sum_s;
                found = true;
            }
        }

        if (!found) cout << -1 << "\n";
        else cout << best_str << "\n";
    }
    return 0;
}
