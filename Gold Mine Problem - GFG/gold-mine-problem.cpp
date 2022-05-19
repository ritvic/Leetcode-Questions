// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maxGold(int n, int m, vector<vector<int>> v)
    {
        // code here
        for(int j=1;j<m;j++)
        {
            for(int i=0;i<n;i++)
            {
                if(i<n-1 && i>0)
                v[i][j]=v[i][j]+max(v[i][j-1],max(v[i-1][j-1],v[i+1][j-1]));
                else if(i>0)
                v[i][j]=v[i][j]+max(v[i][j-1],v[i-1][j-1]);
                else if(i<n-1)
                v[i][j]=v[i][j]+max(v[i][j-1],v[i+1][j-1]);
                else
                v[i][j]=v[i][j]+v[i][j-1];
                
            }
        }
        int ma=INT_MIN;
        for(int i=0;i<n;i++)
        {
            ma=max(ma,v[i][m-1]);
        }
        return ma;

    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> M(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++)
                cin>>M[i][j];
        }
        
        Solution ob;
        cout<<ob.maxGold(n, m, M)<<"\n";
    }
    return 0;
}  // } Driver Code Ends