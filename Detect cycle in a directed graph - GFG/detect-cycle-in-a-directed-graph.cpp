// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
  bool iscycle(int x,vector<int> &vis,vector<int> adj[],vector<int> &stack)
{
    stack[x]=1;
    if(!vis[x])
    {
        vis[x]=1;
        for(auto i:adj[x])
        {
            if(!vis[i] && iscycle(i,vis,adj,stack))
                return true;
            if(stack[i])
                return true;
        }
    }
    stack[x]=0;
    return false;
}
    // Function to detect cycle in a directed graph.
   bool isCyclic(int V, vector<int> adj[]) {
        vector<int> stack(V+1,0),vis(V+1,0);bool cycle=false;
    for(int i=0;i<V;i++)
    {
        if(!vis[i] && iscycle(i,vis,adj,stack))
        cycle=true;
    }
    return (cycle)?1:0;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
  // } Driver Code Ends