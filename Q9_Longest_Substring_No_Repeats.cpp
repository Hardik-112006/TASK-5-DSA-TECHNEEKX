#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    string s = "abcabcbb";
    vector<bool> seen(256, false);
    int left = 0, bestLength = 0;

    for (int right = 0; right < (int)s.size(); right++) {
        unsigned char current = static_cast<unsigned char>(s[right]);

        while (seen[current]) {
            unsigned char outgoing = static_cast<unsigned char>(s[left]);
            seen[outgoing] = false;
            left++;
        }

        seen[current] = true;
        bestLength = max(bestLength, right - left + 1);
    }

    cout << bestLength << "\n";
    return 0;
}
