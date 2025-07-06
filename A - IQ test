#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    int count = 0;

    for (int i = 0; i < 3; ++i) {
        if (arr[i] % 2 == 0) {
            count++;
        } else
        {
            count--;
        }
    }

    
    if (count > 0) {                // even numbers are more than odd numbers
        for (int i = 0; i < n; ++i) {
            if (arr[i] % 2 == 1) {
                std::cout << i+1 << std::endl; // Output the index of the first odd number
            }
        }
    } else {
        for (int i = 0; i < n; ++i) {
            if (arr[i] % 2 == 0) {
                std::cout << i+1 << std::endl; // Output the index of the first even number
            }
        }
    }

}
