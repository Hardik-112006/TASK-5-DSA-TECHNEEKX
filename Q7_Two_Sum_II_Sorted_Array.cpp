#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> numbers = {2, 7, 11, 15};
    int target = 9;
    int left = 0, right = (int)numbers.size() - 1;

    while (left < right) {
        int sum = numbers[left] + numbers[right];

        if (sum == target) {
            cout << left + 1 << " " << right + 1 << "\n"; // 1-based indices
            return 0;
        } else if (sum < target) {
            left++;
        } else {
            right--;
        }
    }

    cout << "No pair found\n";
    return 0;
}
