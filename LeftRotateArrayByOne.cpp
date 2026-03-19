#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin >> n; // The size of the array
    vector<int> arr(n); // The array to store the input
    for (int i = 0; i < n; i++) 
        cin >> arr[i]; // Read the elements of the array

    // Perform left rotation by one
    int firstElement = arr[0]; // Store the first element to be moved to the end
    for (int i = 0; i < n - 1; i++)
        arr[i] = arr[i + 1]; // Shift elements to the left
    arr[n - 1] = firstElement; // Place the first element at the end
    
    // Output the rotated array
    for (int i = 0; i < n; i++)
        cout << arr[i] << " "; // Print the elements of the rotated array

    return 0; // Return 0 to indicate successful execution
}