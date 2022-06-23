// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:

    int dfs(int node, int n, vector<int> adj[], vector<int>& dp){
        if(dp[node] != -1)  return dp[node];
        int chainLen = 1;
        for(auto nodes: adj[node]){
            int val = 1 + dfs(nodes, n, adj, dp);
            chainLen = max(chainLen, val);
        }
        return dp[node] = chainLen;
    }
    int minColour(int N, int M, vector<int> mat[]) {
        // code here
        vector<int> adj[N+1];
        for(int i=0;i<M;i++){
            int v = mat[i][0], u = mat[i][1];
            adj[u].push_back(v);
        }
        int res = 0;
        vector<int> dp(N+1, -1);
        for(int i=1;i<=N;i++){
            if(dp[i] == -1){
                int chainLen = dfs(i, N, adj, dp);
                res = max(res, chainLen);
            }
            else{
                res = max(res, 1+dp[i]);
            }
        }
        return res;
    } 
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, M, x, y;
        cin>>N>>M;
        vector<int> mat[M];
        for(int i = 0;i < M;i++){
            cin>>x>>y;
            mat[i].push_back(x);
            mat[i].push_back(y);
        }
        
        Solution ob;
        cout<<ob.minColour(N, M, mat)<<"\n";
    }
    return 0;
}  // } Driver Code Ends