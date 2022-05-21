// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:

	// Function to find maximum product subarray
	long long maxProduct(vector<int> arr, int n)
{

    long long int maxp, minp, globalp = INT_MIN;
    maxp = 1;
    minp = 1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 0)
            swap(maxp, minp);
        maxp = max((long long int)arr[i], arr[i] * maxp); //180
        minp = min((long long int)arr[i], arr[i] * minp); //-60
        if (arr[i] == 0)
        {
            maxp = 1;
            minp = 1;
        }
        if (maxp > globalp)
            globalp = maxp;
    }
    return globalp;
}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<int> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends