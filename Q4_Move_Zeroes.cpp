#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> nums = {0, 1, 0, 3, 12};
    int write = 0;

    for (int read = 0; read < (int)nums.size(); read++) {
        if (nums[read] != 0) {
            nums[write] = nums[read];
            write++;
        }
    }

    while (write < (int)nums.size()) {
        nums[write] = 0;
        write++;
    }

    for (int i = 0; i < (int)nums.size(); i++) {
        cout << nums[i] << (i + 1 == (int)nums.size() ? "\n" : " ");
    }
    return 0;
}
