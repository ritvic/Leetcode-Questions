// { Driver Code Starts


#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution {
public:
    bool isvalid(int i,int j,int n,vector<vector<bool>> &vis)
    {
        if(i>=1 && j>=1  && i<=n && j<=n && !vis[i][j]) return true;
        return false;
    }
    vector<vector<int>> xy={{2,1},{2,-1},{-2,-1},{-2,1},{1,2},{1,-2},{-1,2},{-1,-2}};
	int minStepToReachTarget(vector<int>&kk, vector<int>&ttt, int N){
	    // Code here
	    queue<pair<int,int>> q;
	    q.push({kk[0],kk[1]});
	    vector<vector<bool>> vis(N+1,vector<bool> (N+1,false));
	    vis[kk[0]][kk[1]]=true;
	    int step=0;
	    while(!q.empty())
	    {
	        int nn=q.size();
	        while(nn--)
	        {
	            auto x=q.front();
	            q.pop();
        	    vis[kk[0]][kk[1]]=true;

	            if(x.first==ttt[0] && x.second==ttt[1]) return step;
	            for(int i=0;i<8;i++)
	            {
	                int o=xy[i][0]+x.first,p=xy[i][1]+x.second;
	                if(isvalid(o,p,N,vis))
	                {q.push({o,p});vis[o][p]=true;}
	            }
	        }
	        step++;
	    }
	    return -1;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends