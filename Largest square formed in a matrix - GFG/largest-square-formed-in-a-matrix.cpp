// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maxSquare(int n, int m, vector<vector<int>> v){
        // code here
        int mm=0,a=-1,b;
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                if(v[i][j]==1)
                v[i][j]=min({v[i][j-1], v[i-1][j],v[i-1][j-1]})+1;
            }
        }
        for(auto i:v)
        for(auto j:i)
        mm=max(mm,j);
        return mm;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for(int i = 0;i < n*m;i++)
            cin>>mat[i/m][i%m];
        
        Solution ob;
        cout<<ob.maxSquare(n, m, mat)<<"\n";
    }
    return 0;
}  // } Driver Code Ends