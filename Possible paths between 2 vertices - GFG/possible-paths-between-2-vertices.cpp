// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to count paths between two vertices in a directed graph.
//     void solve(vector<int> adj[], int& cnt,int source, int destination){
//       if(source == destination){
//           cnt++;
//           return;
//       }
//       for(int u:adj[source]){
//           solve(adj,cnt,u,destination);
//       }
//   }
   
//   int countPaths(int V, vector<int> adj[], int source, int destination) {
//       // Code here
//       int cnt=0;
//       solve(adj,cnt,source,destination);
//       return cnt;
//   }
   void dfs(int s, int d, int &count, vector<bool> &visited, vector<int>adj[]){
       if(s==d){
           count++;
           return;
       }
       visited[s]=1;
       for(auto nbr: adj[s]){
           if(!visited[nbr]){
               dfs(nbr,d,count,visited,adj);
           }
       }
       visited[s]=0;
   }
   int countPaths(int V, vector<int> adj[], int source, int destination) {
       // Code here
       int count=0;
       vector<bool> visited(V, false);
       dfs(source,destination,count,visited,adj);
       return count;
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
            // adj[v].push_back(u);
        }
        int source, destination;
        cin >> source >> destination;
        Solution obj;
        cout << obj.countPaths(V, adj, source, destination) << endl;
    }
    return 0;
}  // } Driver Code Ends