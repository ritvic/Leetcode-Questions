// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
   bool isCyclic(int V, vector<int> adj[]) {
        vector <int> indegree(V, 0);
	    for(int i=0; i<V; i++){
	        for(auto j:adj[i])
	            indegree[j]++;
	    }
	    queue <int> q;
	    for(int i=0; i<V; i++){
	        if(indegree[i] == 0)
	            q.push(i);
	    }
	    int c = 0;
	    while(!q.empty()){
	        int t = q.front();
	        q.pop();
	        c += 1;
	        for(auto i:adj[t]){
	            indegree[i]--;
	            if(indegree[i] == 0)
	                q.push(i);
	        }
	    }
	    return c == V ? 0 : 1;
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