// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int memoization(vector<vector<int>>&dp, int n , int r){
         if( n==r || r==0 ) return dp[r][n] = 1;
         if(r>n) return dp[r][n] =0;
         if(dp[r][n]!=-1) return dp[r][n];
         return dp[r][n] = (memoization(dp,n-1,r-1)+ memoization(dp,n-1,r))% 1000000007;
     }
     int nCr(int n, int r){
         if (r>n) return 0;
         vector<vector<int>> dp(r+1,vector<int>(n+1,-1));
         return memoization(dp,n,r);
     }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}  // } Driver Code Ends