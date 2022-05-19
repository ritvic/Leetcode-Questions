// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
         int dp[1001][1001];

        int helper(int h,int m){
         if(h<=0|| m<=0) return 0;
         if(dp[h][m]!=-1) return dp[h][m];
         int a = helper(h-5+3,m-10+2)+2;
         int b = helper(h-20+3,m+5+2)+2; 
         return dp[h][m] = max(a,b);
     }
       int maxLevel(int h,int m)
       {
           // code here
           memset(dp, -1, sizeof(dp));
           return helper(h,m)-1;
       }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    Solution a;
    while(t--)
    {
        int h,m;
        cin>>h>>m;
        cout<<a.maxLevel(h,m)<<endl;
    }
    return 0;
}  // } Driver Code Ends