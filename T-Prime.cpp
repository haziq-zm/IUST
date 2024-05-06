#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Function to check if a number is prime
bool isPrime(int num) {
    if (num <= 1) return false;
    if (num <= 3) return true;

    if (num % 2 == 0 || num % 3 == 0) return false;

    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) {
            return false;
        }
    }

    return true;
}

// Function to check if a number is T-prime
bool isTPrime(long long num) {
    if (num <= 3) return false;

    long long root = sqrt(num);
    if (root * root != num) return false;

    return isPrime(root);
}

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<long long> arr(n);
    cout << "Enter the elements of the array:\n";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << "T-prime numbers in the array:\n";
    for (int i = 0; i < n; ++i) {
        if (isTPrime(arr[i])) {
            cout << arr[i] << " ";
        }
    }
    cout << endl;

    return 0;
}
