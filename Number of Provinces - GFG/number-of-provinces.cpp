// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  int getcompo(int x,vector<vector<int>> adj,vector<int> &vis,int V)
  {
      if(vis[x])
      return 0;
      vis[x]=1;
      int ans=1;
      for(int j=0;j<V;j++)
        {
            if(adj[x][j]==1 && !vis[j])
            {
                ans+=getcompo(j,adj,vis,V);
                vis[j]=1;
            }
        }

      return ans;
      
  }
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        vector<int> compo,vis(V,0);
        for(int i=0;i<V;i++)
        if(!vis[i])
        compo.push_back(getcompo(i,adj,vis,V));
        // for(auto i:compo)
        // cout<<i<<" ";
        return compo.size();
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}  // } Driver Code Ends