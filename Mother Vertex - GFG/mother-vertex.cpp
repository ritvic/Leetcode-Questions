// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution 
{
    public:
    //Function to find a Mother Vertex in the Graph.
    void dfs(vector<int> adj[],int i,stack<int> &st,vector<bool> &vis)
    {
        vis[i]=1;
        for(auto it:adj[i])
        {
            if(!vis[it])dfs(adj,it,st,vis);
        }
        st.push(i);
    }
    void dfss(vector<int> adj[],int i,vector<bool> &vis,int &count)
    {
        vis[i]=1;
        count++;
        for(auto it:adj[i])
        {
            if(!vis[it])dfss(adj,it,vis,count);
        }
        return ;
    }
	int findMotherVertex(int V, vector<int>adj[])
	{
	    // Code here
	    vector<bool> vis(V,false);
	    stack<int> st;
	    st.push(0);
	    for(int i=0;i<V;i++)
	    {
	        if(!vis[i])
	        dfs(adj,i,st,vis);
	    }
	    vis=vector<bool> (V,false);
	    int x=st.top();
	    int count=0;
	    dfss(adj,x,vis,count);
	    if(count==V)
	    return x;
	    return -1;
	}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
		}
		Solution obj;
		int ans = obj.findMotherVertex(V, adj);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends