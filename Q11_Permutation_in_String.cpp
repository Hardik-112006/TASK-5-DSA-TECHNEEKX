#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string s1 = "ab";
    string s2 = "eidbaooo";

    if (s1.size() > s2.size()) {
        cout << "false\n";
        return 0;
    }

    vector<int> need(26, 0), window(26, 0);
    for (char ch : s1) {
        need[ch - 'a']++;
    }

    int k = (int)s1.size();
    for (int right = 0; right < (int)s2.size(); right++) {
        window[s2[right] - 'a']++;

        if (right >= k) {
            window[s2[right - k] - 'a']--;
        }

        if (window == need) {
            cout << "true\n";
            return 0;
        }
    }

    cout << "false\n";
    return 0;
}
