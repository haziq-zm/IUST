#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string lcs(string s1, string s2) {
    int m = s1.size();
    int n = s2.size();

    // Create a 2D vector to store the lengths of LCS for substrings
    vector<vector<int> > dp(m + 1, vector<int>(n + 1, 0));

    // Fill in the dp table
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1; // Match found, increment length
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]); // No match, take maximum length
            }
        }
    }

    // Reconstruct the LCS from dp table
    string lcs_string = "";
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (s1[i - 1] == s2[j - 1]) {
            lcs_string = s1[i - 1] + lcs_string;
            --i;
            --j;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            --i;
        } else {
            --j;
        }
    }

    return lcs_string;
}

int main() {
    string s1, s2;
    cout << "Enter the first string: ";
    cin >> s1;
    cout << "Enter the second string: ";
    cin >> s2;

    string result = lcs(s1, s2);
    cout << "Longest Common Subsequence (LCS): " << result << endl;

    return 0;
}
