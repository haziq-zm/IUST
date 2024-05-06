#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int min_operations(int n) {
    // Initialize a vector to store minimum operations needed for each number
    vector<int> dp(n + 1, 0);

    for (int i = 2; i <= n; ++i) {
        // At each step, the minimum number of operations to reach i is
        // either 1 + minimum operations to reach i/2, i/3, or i-1
        dp[i] = dp[i - 1] + 1;

        if (i % 2 == 0) {
            dp[i] = min(dp[i], dp[i / 2] + 1);
        }

        if (i % 3 == 0) {
            dp[i] = min(dp[i], dp[i / 3] + 1);
        }
    }

    return dp[n];
}

int main() {
    int n;
    cout << "Enter a positive integer n: ";
    cin >> n;
    cout << "Minimum number of operations to reach " << n << " is " << min_operations(n) << endl;
    return 0;
}
