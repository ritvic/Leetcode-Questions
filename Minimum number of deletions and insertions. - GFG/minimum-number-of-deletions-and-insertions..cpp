// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
		

	public:
	int minOperations(string str1, string str2) 
    { 
       int a=str1.length();
       int b=str2.length();
       int dp[a+1][b+1];
       for(int i=0;i<a+1;i++)
       {
           for(int j=0;j<b+1;j++)
           {
               if(i==0 || j==0)
               {
                   dp[i][j]=0;
               }
           }
       }
       for(int i=1;i<a+1;i++)
       {
           for(int j=1;j<b+1;j++)
           {
               if(str1[i-1]==str2[j-1])
               {
                   dp[i][j]=1+dp[i-1][j-1];
               }
               else{
                   dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
               }
           }
       }
       int x=b-dp[a][b];//no of insertion
       int y=a-dp[a][b];//no of deletion
       return x+y;
    }
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}

  // } Driver Code Ends