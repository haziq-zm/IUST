#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}
int knapsack(int capacity, int weight[], int profit[], int items) {

    int dp[items + 1][capacity + 1];
    
    // Initialize the dp array with zeros
    for (int i = 0; i <= items; i++) {
        for (int j = 0; j <= capacity; j++) {
            dp[i][j] = 0;
        }
    }
    for (int i = 1; i <= items; i++) {
        for (int w = 1; w <= capacity; w++) {
            if (weight[i - 1] <= w) {
                dp[i][w] = max(profit[i - 1] + dp[i - 1][w - weight[i - 1]], dp[i - 1][w]);
            } else {

                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    return dp[items][capacity];
}

int main() {
    int profit[] = {60, 150, 90};
    int weight[] = {2, 4, 1};
    int capacity = 5;
    int items = sizeof(profit) / sizeof(profit[0]);
    int total = knapsack(capacity, weight, profit, items);
    printf("Total profit earned is %d", total);
    return 0;
}
