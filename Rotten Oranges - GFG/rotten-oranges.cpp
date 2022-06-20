// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    bool isValid (int i, int j, int n, int m, vector<vector<int>>& grid)
    {
        if (i>=0 && j>=0 && i<n && j<m && grid[i][j]==1)
            return true;
        return false;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int n=grid.size(),m=grid[0].size(),tot=0;

        queue <pair<int,int> > q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if (grid[i][j]!=0)
                    tot++;
                if(grid[i][j]==2)
                {
                    q.push({i,j});
                }
            }
        }
        int count = 0, timer = 0;
        while (!q.empty())
        {
            int k = q.size();
            count += k;
            
            while (k--)
            {
                int i = q.front().first, j = q.front().second;
                q.pop();
                
                if (isValid(i-1,j, n, m, grid))
                {
                    grid[i-1][j]=2;
                    q.push({i-1,j});
                }
                
                if (isValid(i+1,j, n, m, grid))
                {
                    grid[i+1][j]=2;
                    q.push({i+1,j});
                }
                
                if (isValid(i,j-1, n, m, grid))
                {
                    grid[i][j-1]=2;
                    q.push({i,j-1});
                }
                
                if (isValid(i,j+1, n, m, grid))
                {
                    grid[i][j+1]=2;
                    q.push({i,j+1});
                }
            }
            
            if (!q.empty())
            {
                timer++;
            }
        }
        
        return tot==count?timer:-1;
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
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends