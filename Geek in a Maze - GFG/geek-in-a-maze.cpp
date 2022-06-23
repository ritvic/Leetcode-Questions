// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
 
	public:
	int m,n;
    bool valid(int i,int j,int u,int d)
    {
         if(i<0 || j<0 || i>=m || j>=n || u<0 || d<0)
            return false;
         return true;    
    }
    struct st
    {
        int x,y,u,d;
    };
    int dx[4]={0,0,1,-1};
    int dy[4]={1,-1,0,0};
    int du[4]={0,0,0,-1};
    int dd[4]={0,0,-1,0};
    int numberOfCells(int M, int N, int r, int c, int u, int d, vector<vector<char>> &mat)
    {
     m=M,n=N;
     queue<st>q;
     q.push({r,c,u,d});
     if(mat[r][c]=='#')
        return 0;
     mat[r][c]='#';
     int res=0;
     while(!q.empty())
     {
         st p=q.front();
         q.pop();
         r=p.x,c=p.y,u=p.u,d=p.d;
         res++;
         for(int k=0;k<4;k++)
         {
             int i=r+dx[k],j=c+dy[k],u1=u+du[k],d1=d+dd[k];
             if(valid(i,j,u1,d1) && mat[i][j]=='.')
             {
                 mat[i][j]='#';
                 q.push({i,j,u1,d1});
             }
         }
     }
     return res;
    }

};

// { Driver Code Starts.

int main() 
{
   	
   	int t;
    cin >> t;

    while (t--)
    {
    	int n, m, r, c, u, d;
        cin >> n >> m >> r >> c >> u >> d;
        
        vector<vector<char>> mat(n, vector<char>(m, '.'));

        for(int i = 0; i < n; i++)
        {
        	for(int j = 0; j < m; j++)
        	{
        		cin >> mat[i][j];
        	}
        }

      

        Solution obj;
        cout << obj.numberOfCells(n, m, r, c, u, d, mat) << "\n";
    
    }

    return 0;
}


  // } Driver Code Ends