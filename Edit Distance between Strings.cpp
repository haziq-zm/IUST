#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int editDistance(const string& str1, const string& str2) {
    int m = str1.length();
    int n = str2.length();

    // Create a 2D vector to store the edit distance
    vector<vector<int> > dp(m + 1, vector<int>(n + 1, 0)); // Added a space between '> >'

    // Initialize the first row and column
    for (int i = 0; i <= m; ++i) {
        dp[i][0] = i;
    }
    for (int j = 0; j <= n; ++j) {
        dp[0][j] = j;
    }

    // Fill in the rest of the matrix
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1]; // No operation needed
            } else {
                dp[i][j] = 1 + min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])); // Changed min call
            }
        }
    }

    return dp[m][n];
}

int main() {
    string str1, str2;
    cout << "Enter the first string: ";
    cin >> str1;
    cout << "Enter the second string: ";
    cin >> str2;

    int distance = editDistance(str1, str2);
    cout << "Edit distance between the two strings: " << distance << endl;

    return 0;
}
