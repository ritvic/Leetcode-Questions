// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int LCSof3 (string A, string B, string C, int n1, int n2, int n3);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; cin >> n1 >> n2 >> n3;
        string A, B, C; cin >> A >> B >> C;
        cout << LCSof3 (A, B, C, n1, n2, n3) << endl;
    }
}
// Contributed By: Pranay Bansal
// } Driver Code Ends

int dp[100][100][100];
int fun(string X,string Y,string Z,int i,int j,int k)
{
    if(i==-1||j==-1||k==-1)
        return 0;
    if(dp[i][j][k]!=-1)
        return dp[i][j][k];
     
    if(X[i]==Y[j] && Y[j]==Z[k])
        return dp[i][j][k] = 1+fun(X,Y,Z,i-1,j-1,k-1);
    else
        return dp[i][j][k] = max(max(fun(X,Y,Z,i-1,j,k),
                            fun(X,Y,Z,i,j-1,k)),fun(X,Y,Z,i,j,k-1));
}
int LCSof3 (string A, string B, string C, int n1, int n2, int n3)
{
    // your code here
    memset(dp,-1,sizeof dp);
    return fun(A,B,C,n1-1,n2-1,n3-1);
    
    
}