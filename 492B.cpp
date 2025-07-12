#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

int main() {
	int length, lanterns;
	cin >> lanterns >> length;

	vector<int> positions(lanterns);
	for (int i = 0; i < lanterns; i++) {
		cin >> positions[i];
	}

	sort(positions.begin(), positions.end());

	double maxGap = 0;
	for (int i = 0; i < lanterns - 1; i++) {
		maxGap = max(maxGap, (positions[i + 1] - positions[i]) / 2.0);
	}

	double edgeLeft = positions[0];
	double edgeRight = length - positions.back();

	double ans = max({maxGap, edgeLeft, edgeRight});

	cout << fixed << setprecision(10) << ans;
	return 0;
}
