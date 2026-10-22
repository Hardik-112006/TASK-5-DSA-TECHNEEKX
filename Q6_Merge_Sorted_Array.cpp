#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2 = {2, 5, 6};
    int m = 3, n = 3;

    int i = m - 1, j = n - 1, write = m + n - 1;

    while (i >= 0 && j >= 0) {
        if (nums1[i] > nums2[j]) {
            nums1[write] = nums1[i];
            i--;
        } else {
            nums1[write] = nums2[j];
            j--;
        }
        write--;
    }

    while (j >= 0) {
        nums1[write] = nums2[j];
        j--;
        write--;
    }

    for (int x = 0; x < (int)nums1.size(); x++) {
        cout << nums1[x] << (x + 1 == (int)nums1.size() ? "\n" : " ");
    }
    return 0;
}
