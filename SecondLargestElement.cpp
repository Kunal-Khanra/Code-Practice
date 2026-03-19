#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin >> n;
    vector<int> arr(n); // Create a array of size n
    for (int i = 0 ; i < n ; i += 1) cin >> arr[i]; // Input the array

    int largest = -1; // Initialize largest to the smallest possible integer
    int secondLargest = -1; // Initialize second largest to the smallest possible integer

    for (int i = 0 ; i < n ; i += 1) // Traverse the array
    {
        if (arr[i] > largest) // If the current element is greater than largest
        {
            secondLargest = largest; // Update second largest to largest
            largest = arr[i]; // Update largest to current element
        }
        else if (arr[i] > secondLargest && arr[i] != largest) // If the current element is greater than second largest and not equal to largest
        {
            secondLargest = arr[i]; // Update second largest to current element
        }
    }
    cout << "The second largest element is: " << secondLargest << endl;
    return 0;
}