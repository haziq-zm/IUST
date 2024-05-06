#include <iostream>
#include <vector>

using namespace std;

bool subsetSumExists(const vector<int>& nums, int sum) {
    int n = nums.size();
    // Create a 2D DP array to store the subset sum possibilities
    vector<vector<bool> > dp(n + 1, vector<bool>(sum + 1, false));

    // If sum is 0, then answer is true for empty subset
    for (int i = 0; i <= n; ++i) {
        dp[i][0] = true;
    }

    // Fill the DP table
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= sum; ++j) {
            // If current element is greater than sum, then it can't be included in the subset
            if (nums[i - 1] > j) {
                dp[i][j] = dp[i - 1][j];
            } else {
                // Check if either including the current element or excluding it makes the subset sum to sum
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
            }
        }
    }

    return dp[n][sum];
}

int main() {
    int n, sum;
    cout << "Enter the number of elements in the set: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements of the set:\n";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    cout << "Enter the target sum: ";
    cin >> sum;

    if (subsetSumExists(nums, sum)) {
        cout << "Yes, there exists a subset with sum equal to " << sum << endl;
    } else {
        cout << "No, there is no subset with sum equal to " << sum << endl;
    }

    return 0;
}
