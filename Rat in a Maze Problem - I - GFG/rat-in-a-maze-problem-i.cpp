// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
     vector<string> ans;
    void solve ( int i, int j , string s , int n, vector<vector<int>> m){
        if (i<0 or j< 0 or i>=n or j>= n) return;
        if (m[i][j] != 1) return ;
        
        if (i == n-1 and j == n-1){
            ans.push_back(s);
            return ;
        }
        m[i][j] =2;
        solve (i-1, j , s+"U" , n , m);
        solve (i+1, j, s+"D", n, m);
        solve (i, j-1, s+"L", n, m);
        solve ( i, j+1, s+"R", n, m);
        m[i][j] =1;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        if (m[0][0]==0 )return ans;
        if (m[n-1][n-1] == 0) return ans;
        string s="";
        solve ( 0,0, s, n , m);
        sort ( ans.begin(),ans.end());
        return ans;
        
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends