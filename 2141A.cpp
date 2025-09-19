#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_set>
using namespace std;

void solve() {
	int n;
	cin >> n;

	vector<int> sofas(n);
	for (int i = 0; i < n; i++) {
		cin >> sofas[i];
	}

	int counter = 0;
	int prefix_min = sofas[0];
	vector<int> answers;

	// compute the prefix min -- if the prefix min < curr, then store the index in answer and increment counter
	for (int i = 1; i < n; i++) {
		if (prefix_min < sofas[i]) {
			answers.push_back(i+1);
			counter++;
		}
		// update prefix_min
		prefix_min = min(prefix_min, sofas[i]);
	}
	
	cout << counter << '\n';
	for (int i = 0; i < answers.size(); i++) {
		cout << answers[i] << " "; 
	}
	cout << '\n';

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

after how many iterations does there exist of total separation between a and b



*/