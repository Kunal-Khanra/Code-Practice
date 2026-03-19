#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Take the size of the array
    int n; cin >> n;

    vector<int> arr(n);
    for (int i = 0 ; i < n ; i += 1) cin >> arr[i];

    // Let the first element be the maximum element
    int max_element = arr[0];
    for (int i = 1 ; i < n ; i += 1) 
        max_element = max(max_element, arr[i]); // Update the maximum element if the current element is greater
    
    cout << "The largest element is: " << max_element << endl;
    return 0;
}