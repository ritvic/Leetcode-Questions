// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    long long int fun(int n,vector<int> &dp)
    {
         if(n==3)
        return 4;
        if(n==2)
        return 2;
        if(n==1)
        return 1;
        if(dp[n]!=-1)
        return dp[n];
        return dp[n]=(fun(n-1,dp)+(n-1)*fun(n-2,dp))%1000000007;
    }
    int countFriendsPairings(int n) 
    { 
        vector<int> dp(10001,-1);
        return fun(n,dp);
    }

};    
 

// { Driver Code Starts.
int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	Solution ob;
    	cout <<ob.countFriendsPairings(n); 
    	cout<<endl;
    }
} 
  // } Driver Code Ends