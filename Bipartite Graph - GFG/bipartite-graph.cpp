// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    bool color(int u,int curr,vector<int>adj[],vector<int> &col)
    {
        if(col[u]!=-1 && col[u]!=curr)
        return false;
        // if(col[u]!=-1)
        // return true;
        bool ans = true;

        col[u]=curr;
        for(auto i:adj[u])
        {
            if(col[i]==-1)
            ans&=color(i,curr^1,adj,col);
            if(col[i] !=-1 && col[i] != 1^curr)
                return false;
            if (!ans)
            return false;
        }
        return true;
    }
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    vector<int> col(V,-1);
	    for(int i=0;i<V;i++)
	    {
	        if(col[i]==-1&& !color(i,0,adj,col))
	        return false;

	    }
	    return true;
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
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}  // } Driver Code Ends