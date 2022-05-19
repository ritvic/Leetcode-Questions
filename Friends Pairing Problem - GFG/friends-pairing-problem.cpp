// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    int countFriendsPairings(int n) 
    { 
        const int mod=1e9+7;
       long long dp[n + 1];
        for (int i = 0; i <= n; i++) 
        {
            if (i <= 2)
                dp[i] = i;
            else
                dp[i] = (dp[i - 1] + ((i - 1) * dp[i - 2])%mod)%mod;
        }
 
        return dp[n];
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