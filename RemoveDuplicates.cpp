#include <bits/stdc++.h>
using namespace std;

// Remove duplicates from a sorted array and return the new length of the array
int main()
{
    int n; cin >> n; // The size of the array
    vector<int> arr(n); // The array to store the input
    for (int i = 0; i < n; i++)
        cin >> arr[i]; // Read each element of the array

    if (n == 1) {
        cout << 1 << endl; // If the array has only one element, return 1
        return 0;
    }

    int k = 0; // Initialize k to 0, which will be used to track the position of the last unique element
    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[k]) { // If the current element is not equal
            arr[++k] = arr[i]; // Increment k to move to the next position and Update the position of the last unique element
        }
    }
    cout << k + 1 << endl; // Return the new length of the array, which is k + 1
    return 0;
}