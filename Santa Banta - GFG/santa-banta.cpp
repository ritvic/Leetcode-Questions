// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

void precompute();
int helpSanta(int n, int m, vector<vector<int>> &g);

int main(){
	int t;cin>>t;
	precompute();
	while(t--){
        int n,e,u,v;
        cin>>n>>e;
        vector<vector<int>> g(n+10);
        
		for(int i = 0; i < e; i++)
		{
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		
		cout << helpSanta(n, e, g) << endl;
		
	}
}


// } Driver Code Ends


void precompute()
{
    int a = 0;
}
    bool IsPrime[1000005];

int SieveOfEratosthenes(int c)
{
    memset(IsPrime, true, sizeof(IsPrime));
 
    for (int p = 2; p * p < 1000005; p++){
        if (IsPrime[p] == true) {
            for (int i = p * p; i < 1000005; i += p)
                IsPrime[i] = false;
        }
    }
 
    int count = 1;
    for (int p = 2; p < 1000005; p++){
        if (IsPrime[p]){
        if(count == c) return p;
        count++;
        }
    }
    return -1;
}
void dfs( vector<vector<int>> &g , vector <int> &visit , int i , int &val)
{
    val++;
    visit[i] = 1;
    for(auto it : g[i])
    {
        if(visit[it]==0)
        dfs(g , visit , it , val);
    }
}
int helpSanta(int n, int m, vector<vector<int>> &g){
    vector <int> visit(n+1 , 0);
    int maxConection = 0;
    for(int i = 1 ; i <= n ; i++)
    {
        if(visit[i] == 0)
        {
            int val = 0;
            dfs(g , visit , i , val);
            maxConection = max(maxConection , val);
        }
    }
    if(maxConection==1) return -1;
    return SieveOfEratosthenes(maxConection);
}