#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_map>
using namespace std;

int main() {
	int n;
	std::cin >> n;

	std::unordered_map<std::string, int> hashmap;
	
	for (int i = 0; i < n; ++i) {
		std::string x;
		std::cin >> x;
		
		if (hashmap.find(x) == hashmap.end()) {
			hashmap[x] = 1;
			cout << "OK" << "\n";
		} else {
			string new_name = x + to_string(hashmap[x]);
			cout << new_name << "\n";
			hashmap[x] += 1;
		}

	}

	return 0;

}
