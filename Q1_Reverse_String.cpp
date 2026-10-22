#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string s = "hello";
    int left = 0, right = (int)s.size() - 1;

    while (left < right) {
        swap(s[left], s[right]);
        left++;
        right--;
    }

    cout << s << "\n";
    return 0;
}
