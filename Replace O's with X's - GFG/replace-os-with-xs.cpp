// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int dx[4] = {0,1,0,-1};
    int dy[4] = {1,0,-1,0};
    bool isValid(int x, int y, int n, int m)
    {
        return !(x<0 or x>n-1 or y < 0 or y>m-1);
    }
    bool isCorner(int x, int y, int n, int m)
    {
        return (x == 0 or x == n-1 or y == 0 or y == m-1); 
    }
    void bfs(int x, int y, vector<vector<char>> &mat, vector<vector<int> > &vis)
    {
        int n = mat.size(), m = mat[0].size();
        queue<pair<int,int> > q;
        q.push({x,y});
        vis[x][y] = 1;
        mat[x][y] = '#';
        while(!q.empty())
        {
            int qsz = q.size();
            while(qsz--)
            {
                auto curr = q.front();
                q.pop();
                for(int j = 0; j < 4; j++)
                {
                    int newx = curr.first+dx[j], newy = curr.second+dy[j];
                    if(isValid(newx,newy,n,m) and mat[newx][newy] == 'O' and vis[newx][newy] == 0)
                    {
                        mat[newx][newy] = '#';
                        q.push({newx,newy});
                        vis[newx][newy] = 1;
                    }
                }
            }
        }
    }
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        
        vector<vector<int> > vis(n,vector<int> (m,0));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(isCorner(i,j,n,m) and mat[i][j] == 'O' and vis[i][j] == 0) 
                    bfs(i,j,mat,vis);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(mat[i][j] == 'O')
                    mat[i][j] = 'X';
        
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(mat[i][j] == '#')
                    mat[i][j] = 'O';
        return mat;
        
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}  // } Driver Code Ends