// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to find the number of 'X' total shapes.
    void dfs(int i,int j,int n,int m,vector<vector<bool>> &vis,vector<vector<char>>& grid)
    {
        if(i<0 || j<0 || j>=m || i>=n || vis[i][j] || grid[i][j]=='O') return;
        vis[i][j]=1;
        dfs(i-1,j,n,m,vis,grid);
        dfs(i+1,j,n,m,vis,grid);
        dfs(i,j+1,n,m,vis,grid);
        dfs(i,j-1,n,m,vis,grid);
        return;
    }
    int xShape(vector<vector<char>>& grid) 
    {
        // Code here
        int n=grid.size(),m=grid[0].size();
        vector<vector<bool>> vis(n,vector<bool> (m,false));
        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j] && grid[i][j]=='X')
               {
                   dfs(i,j,n,m,vis,grid);
                    count++;
               }
            }
        }
        return count;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m, '#'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.xShape(grid);
		cout << ans <<'\n';
	}
	return 0;
}  // } Driver Code Ends