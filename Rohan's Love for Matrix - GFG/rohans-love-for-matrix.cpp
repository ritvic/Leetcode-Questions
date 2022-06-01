// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++
vector<int> dp(1000000+1,-1);
const int mod=1e9+7;

class Solution {
  public:
  int fib(int n)
  {
      if(n==0 || n==1)
      return dp[n]=n;
      if(dp[n]!=-1)
      return dp[n]%mod;
      return dp[n]=(fib(n-1)%mod + fib(n-2)%mod)%mod;
  }
    int firstElement(int n) 
    {
        // code here
        return fib(n);
        // cout<<dp[n];
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int  n;
        cin >> n ;
        Solution ob;
        cout<<ob.firstElement(n)<<endl;
    }
    return 0;
}
  // } Driver Code Ends