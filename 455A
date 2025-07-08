#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	int n;
	std::cin >> n;

	std::vector<long long> freq(100001, 0);

	for (int i = 0; i < n; ++i) {
		int x;
		std::cin >> x;
		freq[x]++;
	}

	std::vector<long long> dp(100001, 0);

	dp[1] = freq[1] * 1;

	for (int i = 2; i <= 100000; ++i) {
		dp[i] = std::max(dp[i-1], dp[i-2] + i * freq[i]);
	}

	std::cout << dp[100000] << '\n';
	return 0;

}
