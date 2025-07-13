#include <iostream>
#include <queue>
#include <unordered_set>
using namespace std;

int bfs(int start, int target) {
	if (start >= target) {
		return start - target;  // Only blue button needed
	}

	queue<pair<int, int>> q;
	q.push({start, 0});
	unordered_set<int> visited;
	visited.insert(start);

	while (!q.empty()) {
		auto [curr, clicks] = q.front();
		q.pop();

		if (curr == target) {
			return clicks;
		}

		// Try red button (multiply by 2)
		if (curr * 2 <= target * 2 && !visited.count(curr * 2)) {
			q.push({curr * 2, clicks + 1});
			visited.insert(curr * 2);
		}

		// Try blue button (subtract 1)
		if (curr - 1 > 0 && !visited.count(curr - 1)) {
			q.push({curr - 1, clicks + 1});
			visited.insert(curr - 1);
		}
	}

	return -1; // shouldn't reach here
}

int main() {
	int n, m;
	cin >> n >> m;

	int answer = bfs(n, m);
	cout << answer << endl;

	return 0;
}


/*
inital thoughts
- dfs through the tree
- if curr_number > m + 1 --> do not explore this branch

ALGORITHM


int dfs(int curr_number, int target, int clicks) {
	if (curr_number < 0 || curr_number > target * 2) {
		return -1;
	}

	if (curr_number == target) {
		return clicks;
	}

	int red_button = dfs(curr_number * 2, target, clicks + 1);

	int blue_button = dfs(curr_number - 1, target, clicks + 1);

	if (red_button == -1 and blue_button == -1) return -1;
	if (red_button == -1) return blue_button; 
	if (blue_button == - 1) return red_button;

	return min(red_button, blue_button);

}

*/