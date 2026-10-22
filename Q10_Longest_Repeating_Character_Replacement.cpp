#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    string s = "ABAB";
    int k = 2;
    vector<int> count(26, 0);
    int left = 0, maxFrequency = 0, bestLength = 0;

    for (int right = 0; right < (int)s.size(); right++) {
        count[s[right] - 'A']++;
        maxFrequency = max(maxFrequency, count[s[right] - 'A']);

        while ((right - left + 1) - maxFrequency > k) {
            count[s[left] - 'A']--;
            left++;
        }

        bestLength = max(bestLength, right - left + 1);
    }

    cout << bestLength << "\n";
    return 0;
}
