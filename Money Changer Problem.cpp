#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int minCoins(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, INT_MAX); // Initialize dp array with INT_MAX
    dp[0] = 0; // Base case: 0 coins needed for amount 0

    for (int i = 1; i <= amount; ++i) {
        for (size_t j = 0; j < coins.size(); ++j) {
            int coin = coins[j];
            if (i >= coin && dp[i - coin] != INT_MAX) {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }

    return dp[amount] == INT_MAX ? -1 : dp[amount]; // Return -1 if amount cannot be made up
}

int main() {
    int arr[] = {1, 3, 4};
    vector<int> denominations(arr, arr + sizeof(arr) / sizeof(arr[0]));
    int amount;
    cout << "Enter the amount: ";
    cin >> amount;
    int minCoinsRequired = minCoins(denominations, amount);
    if (minCoinsRequired == -1) {
        cout << "It is not possible to make up the amount using the given denominations." << endl;
    } else {
        cout << "Minimum number of coins required: " << minCoinsRequired << endl;
    }
    return 0;
}
