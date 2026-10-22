#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    if (prices.empty()) {
        cout << 0 << "\n";
        return 0;
    }

    int minPrice = prices[0];
    int maxProfit = 0;

    for (int i = 1; i < (int)prices.size(); i++) {
        minPrice = min(minPrice, prices[i]);
        maxProfit = max(maxProfit, prices[i] - minPrice);
    }

    cout << maxProfit << "\n";
    return 0;
}
