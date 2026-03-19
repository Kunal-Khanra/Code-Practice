#include <bits/stdc++.h>
using namespace std;


int main()
{
    int n; cin >> n; // size of array
    vector<int> arr(n); // Create an array of size n

    for (int i = 0; i < n; i++) {
        cin >> arr[i]; // Input elements of the array
    }

    // Check if the array is sorted in non-decreasing order
    bool isSorted = true; // Assume the array is sorted
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[i - 1]) { // If current element is less than the previous element
            isSorted = false; // The array is not sorted
            break; // No need to check further  
        }
    }
    cout << (isSorted ? "YES" : "NO"); // Output "YES" if sorted, otherwise "NO"
    return 0;
}