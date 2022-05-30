// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
const int NN=1e3+7;
vector<vector<int>> dp(NN,vector<int> (NN,-1));

class Solution{
public:
    int knap(int N, int W, int val[], int wt[])
    {
        // code here
        if(W<=0||N<=0)
        return 0;
        if(dp[N][W]!=-1)
        return dp[N][W];
        
        if(W-wt[N-1]>=0)
        dp[N][W]=max(knap(N-1,W-wt[N-1],val,wt)+val[N-1],max(knap(N,W-wt[N-1],val,wt)+val[N-1],knap(N-1,W,val,wt)));
        // return dp[N][W]=max(knapSack(N,W-wt[N-1],val,wt)+val[N-1],knapSack(N-1,W,val,wt));
        else
        dp[N][W]=knap(N-1,W,val,wt);
        return dp[N][W];
    }
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        dp=vector<vector<int>> (NN,vector<int> (NN,-1));
        return knap(N,W,val,wt);
    }
    
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}  // } Driver Code Ends