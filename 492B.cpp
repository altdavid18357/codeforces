#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

int main() {
	int n, t;
	cin >> n >> t;

	vector<int> books(n);
	for (int i = 0; i < n; i++) {
		cin >> books[i];
	}

	//code
	int max_books = 0, sum = 0;
	int left = 0, right = 0;

	while (right < n) {
		sum += books[right];
		
		while (sum > t) {
			sum -= books[left];
			left++;
		}

		max_books = max(max_books, right - left + 1);
		right++;
	}

	cout << max_books;

	return 0;
}
