// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


bool is_k_palin(string s,int k);

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		string s ;
		cin>>s;
		int k;
		cin>>k;
		
		cout<<is_k_palin(s,k)<<endl;
	}
	return 0;
}// } Driver Code Ends


/*You are required to complete this function*/
bool is_k_palin(string s,int k)
{
//Your code here
    int n = s.size();
    int dp[n+1][n+1];
    memset(dp,0,sizeof(dp));
    
    string str = s;
    reverse(str.begin(),str.end());
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(s[i-1]==str[j-1])
            dp[i][j]=dp[i-1][j-1]+1;
            else
            dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    
    int palin = n-dp[n][n];
    
    if(palin<=k)return 1;
    else
    return 0;

}