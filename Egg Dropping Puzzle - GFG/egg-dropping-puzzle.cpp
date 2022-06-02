// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

vector<vector<int> >dp;
class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int fun(int e,int f)
    {
        if(f == 0 || f == 1) return f;
        if(e == 1)  return f;
        if(dp[e][f] != -1) 
            return dp[e][f];
        int ans = INT_MAX;
        for(int k=1;k<=f;k++){
            int breaks=1+ fun(e-1,k-1);
            int notbreak=1+fun(e,f-k);
            ans=min(ans, max(breaks , notbreak));
        }
        return dp[e][f] = ans;
    }
    int eggDrop(int n, int k) 
    {
        dp=vector<vector<int>> (210,vector<int> (210,-1));
        return fun(n,k);
        // your code here
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
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}
  // } Driver Code Ends