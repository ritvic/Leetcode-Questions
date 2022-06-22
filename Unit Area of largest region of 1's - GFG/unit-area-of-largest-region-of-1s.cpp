// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find unit area of the largest region of 1s.
    void dfs(int i,int j,int n,int m,vector<vector<int>>& grid,vector<vector<bool>> &vis,int &count)
    {
        if(i<0 || j<0 ||i>=n ||j>=m || vis[i][j] || !grid[i][j]) return;
        vis[i][j]=true;
        count++;
        dfs(i+1,j,n,m,grid,vis,count);
        dfs(i-1,j,n,m,grid,vis,count);
        dfs(i,j+1,n,m,grid,vis,count);
        dfs(i,j-1,n,m,grid,vis,count);
        dfs(i+1,j+1,n,m,grid,vis,count);
        dfs(i-1,j-1,n,m,grid,vis,count);
        dfs(i-1,j+1,n,m,grid,vis,count);
        dfs(i+1,j-1,n,m,grid,vis,count);
        return ;
        
    }
    
    int findMaxArea(vector<vector<int>>& grid) {
        // Code here
        int n=grid.size(),m=grid[0].size();
        vector<vector<bool>> vis(n,vector<bool> (m,false));
        int maxx=-1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] && !vis[i][j])
                {
                    int count=0;
                    dfs(i,j,n,m,grid,vis,count);
                    maxx=max(maxx,count);
                }
            }
        }
        return maxx;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.findMaxArea(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends