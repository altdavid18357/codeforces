#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
essentially, the main idea here is that 
#1 - the array has to be an arithmetic seqeunce, which is what the first part is doing. this is kind of like pruning in a way.
#2 - basically we want all elements of the array to be divisible by (n+1) --> which is basically when you use operation 1 and operation 2 at the same time and thus the array is explodable.
in order to get the array to that position, there could be a n number of extra operations of 1 or 2. 
We use the idea that when the difference is positive, we should undo operation 1 whereas if the difference is negative we should undo operation 2.
lastly, we check if we have any negatives and the first part of step 2 --> answer

*/

void solve() {
	int n;
		cin >> n;
		
		vector<long long> array(n);

		for (auto &it: array) {
			cin >> it;
		}

		bool bad = false;
		long long diff = array[1] - array[0];

		for (int i = 2; i < n; i++) {
			if (diff != array[i] - array[i-1]) {
				bad = true;
			}
		}

		if (bad) {
			cout << "NO" << endl;
			return;
		}

		for (int i = 0; i < n; i++) {
			if (diff < 0) {
				array[i] = array[i] + diff * (n - i);
			} else {
				array[i] = array[i] - diff * (i + 1);
			}

		}

		cout << (array[0] >= 0 && array[0] % (n+1) == 0 ? "YES": "NO") << endl;
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		solve();
	}

	return 0;
}



/*
- repeaet the first operation unitl we get a 5*n / 4*n / 3*n / 2*n / 1*n set up

ALGORITHM
1. 

*/
