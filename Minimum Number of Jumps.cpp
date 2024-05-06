#include <iostream>
#include <vector>

using namespace std;

int minJumps(vector<int>& nums) {
    int n = nums.size();
    if (n <= 1) return 0;

    int maxReach = nums[0]; // Maximum index that can be reached so far
    int steps = nums[0];    // Maximum steps that can be taken from current position
    int jumps = 1;           // Number of jumps needed

    for (int i = 1; i < n; ++i) {
        if (i == n - 1) {
            return jumps; // If we reached the end of the array
        }

        maxReach = max(maxReach, i + nums[i]); // Update the maximum reachable index

        steps--; // Consume a step

        if (steps == 0) {
            jumps++;            // Need to jump since no more steps
            if (i >= maxReach) {
                return -1;      // Cannot proceed further
            }
            steps = maxReach - i; // Update steps with the remaining steps
        }
    }

    return -1; // If the end of the array cannot be reached
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements of the array:\n";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    cout << "Minimum number of jumps: " << minJumps(nums) << endl;
    return 0;
}
