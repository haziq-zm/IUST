#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int maxPoints(const vector<int>& sequence) {
    unordered_map<int, int> count;
    for (const auto& num : sequence) {
        count[num]++;
    }

    int maxPoints = 0;
    for (const auto& [num, freq] : count) {
        int points = freq;
        if (count.find(num - 1)!= count.end()) {
            points += count.at(num - 1);
        }
        if (count.find(num + 1)!= count.end()) {
            points += count.at(num + 1);
        }
        maxPoints = max(maxPoints, points);
    }

    return maxPoints;
}

int main() {
    int sequenceSize;
    cout << "Enter the size of the sequence: ";
    cin >> sequenceSize;

    vector<int> sequence(sequenceSize);
    cout << "Enter the elements of the sequence:\n";
    for (int i = 0; i < sequenceSize; i++) {
        cin >> sequence[i];
    }

    cout << "Maximum points: " << maxPoints(sequence) << endl;
    return 0;
}
