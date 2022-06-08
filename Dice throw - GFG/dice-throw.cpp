// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
  
    long long go(int m,int n,int target,vector<vector<long long>> &dp){
        
        if(n==0){
            return target==0?1:0;
        }
        
        if(dp[n][target]!=-1)
            return dp[n][target];
        
        long long count=0;
        for(int i=1 ; i<=m && target>=i ; i++){
            count+=go(m,n-1,target-i,dp);
        }
        return dp[n][target]=count;
    }
    long long noOfWays(int M , int N , int X) {
        vector<vector<long long>> dp(N+1,vector<long long>(X+1,-1));
        return go(M,N,X,dp);
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int M,N,X;
        
        cin>>M>>N>>X;

        Solution ob;
        cout << ob.noOfWays(M,N,X) << endl;
    }
    return 0;
}  // } Driver Code Ends