// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to find whether a path exists from the source to destination.
    bool isvalid(int i,int j,int n,vector<vector<int>>& grid, vector<vector<bool>> &vis)
    {
        if(i>=0 && j>=0 && i<n && j<n && !vis[i][j] && grid[i][j]!=0) return true;
        return false;
    }
    bool is_Possible(vector<vector<int>>& grid) 
    {
        //code here
        int n=grid.size();
        vector<vector<bool>> vis(n,vector<bool> (n,false));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {q.push({i,j});i=n;break;}
            }
        }
        vis[q.front().first][q.front().second]=1;
        while(!q.empty())
        {
            int i=q.front().first,j=q.front().second;
            q.pop();
            if(grid[i][j]==2)return true;
            if(isvalid(i+1,j,n,grid,vis))
            {q.push({i+1,j});vis[i+1][j]=true;}
            if(isvalid(i-1,j,n,grid,vis))
            {q.push({i-1,j});vis[i-1][j]=true;}
            if(isvalid(i,j+1,n,grid,vis))
            {q.push({i,j+1});vis[i][j+1]=true;}
            if(isvalid(i,j-1,n,grid,vis))
            {q.push({i,j-1});vis[i][j+1]=true;}
            
        }
        return false;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	}
	return 0;
}  // } Driver Code Ends