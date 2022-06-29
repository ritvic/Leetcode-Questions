// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    bool isInterleave(string A, string B, string C) 
    {
        int n=A.size();
        int m=B.size();
        bool dp[n+1][m+1];
        if(m+n!=C.size())return 0;
        memset(&dp,false,sizeof(dp));
        // dp[0][0]=true;
        for (int i = 0; i <=n; i++)
        {
            for (int j = 0; j <=m; j++)
            {
                if(i==0 && j==0)dp[i][j]=1;
                else if (i == 0 && (B[j - 1] == C[j - 1]))
                    dp[i][j] = dp[i][j - 1];
                else if (j == 0 && (A[i - 1] == C[i - 1]))
                    dp[i][j] = dp[i - 1][j];
                else if(A[i - 1] == C[i + j - 1]&& B[j - 1] != C[i + j - 1])
                dp[i][j] = dp[i - 1][j];
                else if (A[i - 1] != C[i + j - 1] && B[j - 1] == C[i + j - 1])
                    dp[i][j] = dp[i][j - 1];
                else if (A[i - 1] == C[i + j - 1] && B[j - 1] == C[i + j - 1])
                    dp[i][j]= (dp[i - 1][j] || dp[i][j - 1]);
            }
        }
        return dp[n][m];
    }
//      int helper(string a,string b,string c,int n,int m,int len){
//       if(len == 0) return (1);
//       if(n == 0 && m == 0) return (0);
       
//       if(dp[n][m][len] != -1) return (dp[n][m][len]);
       
//       int x = 0, y = 0;
//       if(n-1 >= 0 && a[n-1] == c[len-1]) x = helper(a,b,c,n-1,m,len-1);
//       if(m-1 >= 0 && b[m-1] == c[len-1]) y = helper(a,b,c,n,m-1,len-1);
//       if(x == 1 || y == 1) return (dp[n][m][len] = 1);
//       return (dp[n][m][len] = 0);
//   }
   
//   bool isInterleave(string A, string B, string C) {
//       int n = A.length();
//       int m = B.length();
//       int len = C.length();
//       if(n+m != len) return (false);
//       memset(dp,-1,sizeof(dp));
//       return helper(A,B,C,n,m,len) == 1 ? true : false;
//   }

};

// { Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		string a,b,c;
		cin>>a;
		cin>>b;
		cin>>c;
		Solution obj;
		cout<<obj.isInterleave(a,b,c)<<endl;
	}
	// your code goes here
	return 0;
}  // } Driver Code Ends