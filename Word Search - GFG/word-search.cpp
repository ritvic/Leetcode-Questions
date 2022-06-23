// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    bool dfs(int i,int j,int n,int m,vector<vector<bool>> &vis,vector<vector<char>>& grid,int index,string s)
    {
        if(index == s.size()) {return true;}
        if(i<0 || j<0 || j>=m || i>=n || vis[i][j] || grid[i][j]!=s[index]) return false;;
        vis[i][j]=1;
        bool ans=(dfs(i-1,j,n,m,vis,grid,index+1,s)||
        dfs(i+1,j,n,m,vis,grid,index+1,s) ||
        dfs(i,j+1,n,m,vis,grid,index+1,s) ||
        dfs(i,j-1,n,m,vis,grid,index+1,s));
        vis[i][j]=0;
        return ans;
    }
    bool isWordExist(vector<vector<char>>& grid, string word) {
        // Code here
        int n=grid.size(),m=grid[0].size();
        vector<vector<bool>> vis(n,vector<bool> (m,false));
        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==word[0])
               {
                   if(dfs(i,j,n,m,vis,grid,0,word))return true;
               }
            }
        }
        return false;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}  // } Driver Code Ends