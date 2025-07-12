#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <unordered_map>
using namespace std;

int backtracking(const vector<int>& pieces, int total, int n, vector<int>& memo) {
	if (total == n) return 0;         // base case: exact fit
	if (total > n) return INT_MIN;    // invalid case

	if (memo[total] != -1) return memo[total];

	int max_pieces = INT_MIN;
	for (int piece : pieces) {
		int res = backtracking(pieces, total + piece, n, memo);
		if (res != INT_MIN) {
			max_pieces = max(max_pieces, 1 + res);
		}
	}

	memo[total] = max_pieces;
	return max_pieces;
}

int main() {
	string line;
	getline(cin, line); // Input: 4000 1 2 3

	stringstream ss(line);
	int n;
	ss >> n;

	vector<int> pieces;
	int num;
	while (ss >> num) {
		pieces.push_back(num);
	}

	vector<int> memo(n + 1, -1);

	int result = backtracking(pieces, 0, n, memo);
	cout << (result < 0 ? 0 : result) << endl;

	return 0;
}
