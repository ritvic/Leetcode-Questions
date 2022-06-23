// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution
{
  public:
    vector<int> findOrder(int n, int m, vector<vector<int>> p) 
    {
        //code here
        vector<vector<int>> adj(n);
        vector<int> indeg(n,0);
        vector<int> v;
        for(auto i:p)
        {
            adj[i[1]].push_back(i[0]);
            indeg[i[0]]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++)
        if(indeg[i]==0)
            {q.push(i);v.push_back(i);}
            
        while(!q.empty())
        {
            int u = q.front();
	        q.pop();
	        
	        for(int vv : adj[u]){
	            indeg[vv]--;
	            
	            if(indeg[vv] == 0){
	                {q.push(vv);v.push_back(vv);}
	            }
	        }
        }
        for(int i=0;i<n;i++)
        if(indeg[i]!=0)
            return vector<int> {};
        return v;
        
    }
};

// { Driver Code Starts.

int check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> prerequisites;

        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            prerequisites.push_back({u,v});
        }
        
        vector<int> adj[n];
        for (auto pre : prerequisites)
            adj[pre[1]].push_back(pre[0]);
        
        Solution obj;
        vector <int> res = obj.findOrder(n, m, prerequisites);
        if(!res.size())
            cout<<"No Ordering Possible"<<endl;
        else
            cout << check(n, res, adj) << endl;
    }
    
    return 0;
}  // } Driver Code Ends