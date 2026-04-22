#include <bits/stdc++.h>
using namespace std;


// This function rotates the array by k positions
// Time complexity -> O(n) - because we are iterating over the entrie array
// Space complexity -> O(n) - we are using a new array to store the rotated elements
vector<int> leftRotateArrayByK(vector<int>& arr, int k) {
    int n = arr.size();
    vector<int> rotatedArr(n); // Create a new array to store the rotated elements

    for (int i = 0; i < n; i++) {
        // Calculate the new position for each element
        int newPosition = (i - k + n) % n; // Use modulo to wrap around
        rotatedArr[newPosition] = arr[i]; // Place the element in its new position
    }
    return rotatedArr; // Return the rotated array
}

int main()
{
    int n; cin >> n; // The size of the array
    vector<int> arr(n); // The array to store the input
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int k; cin >> k; // The number of positions to rotate the array
    k = k % n; // To handle cases where k is greater than n
}