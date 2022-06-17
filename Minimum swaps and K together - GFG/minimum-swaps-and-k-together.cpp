// { Driver Code Starts
// C++ program to find minimum swaps required
// to club all elements less than or equals
// to k together
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends


class Solution
{
public:
    int minSwap(int v[], int n, int k) {
        // Complet the function
        int c=0;
        for(int i=0;i<n;i++)
        {
            if(v[i]<=k)c++;
        }
        int bad=0,minn=INT_MAX;
        int i=0;
        while(i<c)
        {
            if(v[i]>k)bad++;i++;
        }
        minn=bad;
        while(i<n)
        {
            if(v[i-c]>k)bad--;
            if(v[i]>k)bad++;
            i++;
            minn=min(minn,bad);
            
        }
        return minn;
    }
};


// { Driver Code Starts.

// Driver code
int main() {

	int t,n,k;
	cin>>t;
	while(t--)
    {
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cin>>k;
        Solution ob;
        cout << ob.minSwap(arr, n, k) << "\n";
    }
	return 0;
}
  // } Driver Code Ends