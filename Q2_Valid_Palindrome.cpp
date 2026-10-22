#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    string s = "A man, a plan, a canal: Panama";
    int left = 0, right = (int)s.size() - 1;

    while (left < right) {
        while (left < right && !isalnum(static_cast<unsigned char>(s[left]))) left++;
        while (left < right && !isalnum(static_cast<unsigned char>(s[right]))) right--;

        if (tolower(static_cast<unsigned char>(s[left])) !=
            tolower(static_cast<unsigned char>(s[right]))) {
            cout << "false\n";
            return 0;
        }
        left++;
        right--;
    }

    cout << "true\n";
    return 0;
}
