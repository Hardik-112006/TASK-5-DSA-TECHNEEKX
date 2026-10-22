#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> nums = {1, 1, 2};
    if (nums.empty()) {
        cout << 0 << "\n";
        return 0;
    }

    int write = 0;
    for (int read = 1; read < (int)nums.size(); read++) {
        if (nums[read] != nums[write]) {
            write++;
            nums[write] = nums[read];
        }
    }

    int uniqueCount = write + 1;
    cout << "Unique count: " << uniqueCount << "\nElements: ";
    for (int i = 0; i < uniqueCount; i++) {
        cout << nums[i] << (i + 1 == uniqueCount ? "\n" : " ");
    }
    return 0;
}
