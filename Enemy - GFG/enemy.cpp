// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
        int largestArea(int n,int m,int k,vector<vector<int>> &arr)
        {
            //  code here
            vector<int>row(n,0);
           vector<int>col(m,0);
           int ans = 0;
           for(auto a:arr){
               row[a[0]-1]=1;
               col[a[1]-1] = 1;
           }
           int longrow = 0;
           int cur = 0;
           int i = 0;
           while(i<n){
               if(row[i] == 0)++cur;
               else{
                   longrow = max(longrow,cur);
                   cur = 0;
               }
               ++i;
           }
           longrow = max(longrow,cur);
           i = 0;
           cur = 0;
           int longcol = 0;
           while(i<m){
               if(col[i] == 0)++cur;
               else{
                   longcol = max(longcol,cur);
                   cur = 0;
               }
               ++i;
           }
           longcol = max(longcol,cur);
           ans = longrow*longcol;
           return ans;
        }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        int k;
        cin>>k;
        vector<vector<int>> e(k,vector<int>(2));
        for(int i=0;i<k;i++)
            cin>>e[i][0]>>e[i][1];
        Solution a;
        cout<<a.largestArea(n,m,k,e)<<endl;
    }
    return 0;
}  // } Driver Code Ends