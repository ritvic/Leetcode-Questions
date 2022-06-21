// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
    void dfs(vector<int>adj[],int v,stack<int>& s,int vis[])
    {
        vis[v]=1;
        for(auto it:adj[v])
        {
            if(vis[it]==0)
            dfs(adj,it,s,vis);
        }
        s.push(v);
    }
    void dfs2(vector<int>adj[],int v,int vis[])
    {
        vis[v]=1;
        for(auto it:adj[v])
        {
            if(vis[it]==0)
            dfs2(adj,it,vis);
        }
    }
    int kosaraju(int V, vector<int> adj[])
    {
        int vis[V]={0};
        stack<int>s;
        for(int i=0;i<V;i++)
        {
            if(vis[i]==0)
            {
                dfs(adj,i,s,vis);
            }
        }
        vector<int> transpose[V];
        
        for(int i=0;i<V;i++){
            for(auto a:adj[i]){
                transpose[a].push_back(i);
            }
        }
        int vi[V]={0};
        int ans=0;
        while(!s.empty())
        {
            int kl=s.top();
            s.pop();
            if(vi[kl]==0){
                    ans++;
                    dfs2(transpose,kl,vi);
                }
        }
        return ans;
    }
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends