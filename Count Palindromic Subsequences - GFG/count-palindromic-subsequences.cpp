// { Driver Code Starts
// Counts Palindromic Subsequence in a given String
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    /*You are required to complete below method */
    long long int  countPS(string str)
    {
        int n = str.length();
        string s = str;
       vector<vector<long long int>> t(n , vector<long long int> (n));
       
       for(int g=0;g<n;g++)
       {
           for(int i = 0,j=g; j<n ;i++ , j++)
           {
              if(i==j)
              t[i][j] = 1;
              else if(j - i ==1)
              t[i][j] = (s[i] == s[j])? 3 : 2;
              else
              {
                  if(s[i]==s[j])
                  t[i][j] = (t[i][j-1]%1000000007 + t[i+1][j]%1000000007  +1)%1000000007  ;
                  else
                  t[i][j] = (1000000007 + t[i][j-1]%1000000007  + t[i+1][j]%1000000007)%1000000007  - t[i+1][j-1]%1000000007 ;
              }
           }
       }
       
       return t[0][n-1]%1000000007;
    }
     
};

// { Driver Code Starts.
// Driver program
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        Solution ob;
        long long int ans = ob.countPS(str);
        cout<<ans<<endl;
    } 
}  // } Driver Code Ends