#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> nums = {-4, -1, 0, 3, 10};
    int n = (int)nums.size();
    vector<int> answer(n);
    int left = 0, right = n - 1, write = n - 1;

    while (left <= right) {
        int leftSquare = nums[left] * nums[left];
        int rightSquare = nums[right] * nums[right];

        if (leftSquare > rightSquare) {
            answer[write] = leftSquare;
            left++;
        } else {
            answer[write] = rightSquare;
            right--;
        }
        write--;
    }

    for (int i = 0; i < n; i++) {
        cout << answer[i] << (i + 1 == n ? "\n" : " ");
    }
    return 0;
}
