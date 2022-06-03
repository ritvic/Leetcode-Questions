// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int cutRod(int a[], int n) {
        //code here
        vector<int> dp(n+1,0);
        int i,j;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=i;j++)
            {
                dp[i]=max(dp[i],dp[i-j]+a[j-1]);
            }
        }
        return dp[n];
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}  // } Driver Code Ends