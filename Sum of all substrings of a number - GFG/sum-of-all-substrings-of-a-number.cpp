// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
    public:
    //Function to find sum of all possible substrings of the given string.
    long long sumSubstrings(string s){
        int n = s.size();
        long long dp[n];
        long long mod = 1e9 + 7;
        dp[0] = s[0] - '0';
        long long sum = dp[0];
        for(int i = 1; i < n; i++){
            dp[i] = ((i+1)*(s[i] - '0') + 10*(dp[i - 1]))%mod;
            sum += dp[i];
            sum %= mod;
        }
        return sum;
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking string
        string s;
        cin>>s;
        Solution ob;
        //calling sumSubstrings() function
        cout << ob.sumSubstrings(s) << endl;
        
    }
    return 0;
}
  // } Driver Code Ends