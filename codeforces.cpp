#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	int n;
	cin >> n;

	int x = 0;
	int y = 0;
	int z = 0;

	for (int i = 0; i < n; i++) {
		int temp_x, temp_y, temp_z;

		cin >> temp_x >> temp_y >> temp_z;

		x += temp_x;
		y += temp_y;
		z += temp_z;

	}

	if (x == 0 && y == 0 && z == 0) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}

	return 0;
}



/*
- repeaet the first operation unitl we get a 5*n / 4*n / 3*n / 2*n / 1*n set up

ALGORITHM
1. 

*/