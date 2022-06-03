// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool iscycle(int x,vector<bool> &vis,vector<int> adj[],int parent)
    {
        vis[x]=true;
        for(auto i:adj[x])
        {
            if(i!=parent)
                if(vis[i])
                return true;
            if(!vis[i] && iscycle(i,vis,adj,x))
            return true;
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<bool> vis(V+1,false);
        bool cycle=false;
        for(int i=0;i<V;i++)
        {
            if(!vis[i] && iscycle(i,vis,adj,-1))
            cycle=true;
        }
        return cycle;
    }
    
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends