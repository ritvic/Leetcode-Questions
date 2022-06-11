// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};

bool valid(int i,int j,int n)
{
    if(i<0 || i>=n || j<0 || j>=n)
    {
        return 0;
    }
    return 1;
}

   int minimumCostPath(vector<vector<int>>& grid) 
   {
       
       int m=grid.size();
       int n=grid[0].size();
       typedef pair<int,pair<int,int>> ppp; //To store weight,x,y 
       //x,y as it is 2D array
       priority_queue<ppp,vector<ppp>,greater<ppp>> pq;
       pq.push({grid[0][0],{0,0}});
       
       
       vector<vector<int>> dis(m,vector<int>(n,INT_MAX));
       dis[0][0]=grid[0][0];
       
       while(!pq.empty())
       {
           int x=pq.top().second.first;
           int y=pq.top().second.second;
           pq.pop();
           if(x==m-1 && y==n-1)
           {
               break;
           }
           for(int i=0;i<4;i++)
           {
               int xv=x+dx[i];
               int yv=y+dy[i];
               if(valid(xv,yv,n))
               {
                   if(dis[xv][yv]>dis[x][y] + grid[xv][yv])
                   {
                       dis[xv][yv]=dis[x][y] + grid[xv][yv];
                       pq.push({dis[xv][yv],{xv,yv}});
                   }
               }
           }
       }
       return dis[m-1][n-1];
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
		int ans = obj.minimumCostPath(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends