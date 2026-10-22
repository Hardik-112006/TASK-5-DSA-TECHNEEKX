#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    // PART A: Two Pointers - unique pairs with target sum
    vector<int> sorted = {1, 3, 4, 5, 7, 9, 10, 12};
    int target = 13;
    int left = 0, right = (int)sorted.size() - 1;
    long long twoPointerSteps = 0;

    cout << "PART A: Unique pairs with sum " << target << "\n";
    while (left < right) {
        twoPointerSteps++;
        int sum = sorted[left] + sorted[right];

        if (sum == target) {
            cout << sorted[left] << " + " << sorted[right] << "\n";

            int leftValue = sorted[left];
            int rightValue = sorted[right];

            while (left < right && sorted[left] == leftValue) {
                left++;
                twoPointerSteps++;
            }
            while (left < right && sorted[right] == rightValue) {
                right--;
                twoPointerSteps++;
            }
        } else if (sum < target) {
            left++;
        } else {
            right--;
        }
    }
    cout << "Two Pointers steps (comparisons + duplicate-skip checks): "
         << twoPointerSteps << "\n\n";

    // PART A2: Duplicate example - print each unique value-pair once
    vector<int> duplicateArray = {1, 1, 2, 3, 4, 4};
    int duplicateTarget = 5;
    left = 0;
    right = (int)duplicateArray.size() - 1;
    long long duplicateSteps = 0;

    cout << "PART A2: Unique pairs with duplicates, target "
         << duplicateTarget << "\n";
    while (left < right) {
        duplicateSteps++;
        int sum = duplicateArray[left] + duplicateArray[right];

        if (sum == duplicateTarget) {
            cout << duplicateArray[left] << " + "
                 << duplicateArray[right] << "\n";

            int leftValue = duplicateArray[left];
            int rightValue = duplicateArray[right];

            while (left < right && duplicateArray[left] == leftValue) {
                left++;
                duplicateSteps++;
            }
            while (left < right && duplicateArray[right] == rightValue) {
                right--;
                duplicateSteps++;
            }
        } else if (sum < duplicateTarget) {
            left++;
        } else {
            right--;
        }
    }
    cout << "Duplicate example steps: " << duplicateSteps << "\n\n";

    // PART B: Fixed Sliding Window - maximum sum of 3 consecutive elements
    vector<int> marks = {4, 2, 12, 1, 7, 8, 3, 9};
    int k = 3;
    int windowSum = 0;
    long long fixedWindowSteps = 0;

    for (int i = 0; i < k; i++) {
        windowSum += marks[i];
        fixedWindowSteps++;
    }

    int maxSum = windowSum;
    int bestStart = 0;

    for (int rightIndex = k; rightIndex < (int)marks.size(); rightIndex++) {
        windowSum -= marks[rightIndex - k];
        windowSum += marks[rightIndex];
        fixedWindowSteps += 2; // one removal and one addition

        int currentStart = rightIndex - k + 1;
        if (windowSum > maxSum) { // strict > preserves the first window on ties
            maxSum = windowSum;
            bestStart = currentStart;
        }
        fixedWindowSteps++; // max comparison
    }

    cout << "PART B: Fixed Sliding Window\n";
    cout << "Maximum window sum: " << maxSum << "\n";
    cout << "Starting index: " << bestStart << "\n";
    cout << "Window elements: [";
    for (int i = bestStart; i < bestStart + k; i++) {
        if (i > bestStart) cout << ", ";
        cout << marks[i];
    }
    cout << "]\n";
    cout << "Fixed Sliding Window steps (initial adds, slide updates, max checks): "
         << fixedWindowSteps << "\n\n";

    // PART C: Variable Sliding Window - shortest subarray with sum >= 15
    // This standard sliding-window solution assumes all numbers are positive.
    int requiredSum = 15;
    int variableLeft = 0;
    int currentSum = 0;
    int shortestLength = (int)marks.size() + 1;
    int shortestStart = -1;
    long long variableWindowSteps = 0;

    for (int variableRight = 0; variableRight < (int)marks.size(); variableRight++) {
        currentSum += marks[variableRight];
        variableWindowSteps++; // add right element

        while (currentSum >= requiredSum) {
            variableWindowSteps++; // valid-window check
            int currentLength = variableRight - variableLeft + 1;

            if (currentLength < shortestLength) {
                shortestLength = currentLength;
                shortestStart = variableLeft;
            }

            currentSum -= marks[variableLeft];
            variableLeft++;
            variableWindowSteps++; // shrink window
        }
        variableWindowSteps++; // final failed while-condition check
    }

    cout << "PART C: Variable Sliding Window (sum >= " << requiredSum << ")\n";
    if (shortestStart == -1) {
        cout << "No subarray found.\n";
    } else {
        cout << "Shortest length: " << shortestLength << "\n";
        cout << "Starting index: " << shortestStart << "\n";
        cout << "Subarray elements: [";
        for (int i = shortestStart; i < shortestStart + shortestLength; i++) {
            if (i > shortestStart) cout << ", ";
            cout << marks[i];
        }
        cout << "]\n";
    }
    cout << "Variable Sliding Window steps (additions, condition checks, shrinks): "
         << variableWindowSteps << "\n\n";

    // Rough comparison of operation counts for Part A and Part B.
    long long bruteForcePairChecks = 0;
    for (int i = 0; i < (int)sorted.size(); i++) {
        for (int j = i + 1; j < (int)sorted.size(); j++) {
            bruteForcePairChecks++;
        }
    }

    long long bruteForceWindowChecks = 0;
    for (int i = 0; i + k <= (int)marks.size(); i++) {
        for (int j = i; j < i + k; j++) {
            bruteForceWindowChecks++;
        }
    }

    cout << "COMPARISON\n";
    cout << "Brute-force pair sum checks (nested loops): "
         << bruteForcePairChecks << "\n";
    cout << "Two Pointers pair steps: " << twoPointerSteps << "\n";
    cout << "Brute-force fixed-window element additions: "
         << bruteForceWindowChecks << "\n";
    cout << "Fixed Sliding Window steps: " << fixedWindowSteps << "\n";

    return 0;
}
