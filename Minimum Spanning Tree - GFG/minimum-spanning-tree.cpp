// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        //required 
        vector<int> key(V , INT_MAX) ; //index(node) ke corresponding weght/dist store krega 
        vector<bool> mst(V, false) ; //ye track rakhega konsi node mst me he 
        vector<int> parent(V, -1) ; //index(node) ke corresponding uska parent batayega 
    
    
        //-----lets start ALgo-----//
        key[0] = 0 ;     //0 is source node 
        parent[0] = -1 ; 
        
        for( int i=0 ; i<V ; ++i)
        {
            int mini = INT_MAX ; 
            int u ; 
            //1. find min weight wali node (from key )
            for( int v=0 ; v<V ; v++)
            {
                if( mst[v]==false && key[v]<mini )
                { 
                    u = v ;         //v wala index hi min weight node he 
                    mini = key[v] ; 
                }
            }
            
            //2. mark min weight node true 
            mst[u] = true ; 
            
            //3. traverse adjancent of u 
            for( auto nbr : adj[u] )
            {
                int v = nbr[0] ;     //neighbour node of U 
                int w = nbr[1] ;     //weight from u to v 
                
                //3.1 agar v mst me nhi he aur V ka weight uske previous weight se kam he to update kar do 
                if( mst[v] == false &&  w<key[v] )
                {
                    key[v] = w ; 
                    parent[v] = u ;     //and v ka parent U initilise kar do 
                }
            }
        }
    
    int sum= 0 ; 
    for( auto it : key )
    {
        sum += it ; 
    }
    
    return sum ; 
    
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends