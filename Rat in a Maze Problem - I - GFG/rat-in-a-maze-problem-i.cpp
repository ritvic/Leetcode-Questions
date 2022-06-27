// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

int dir[4] = {1,-1,0,0};
string D="DULR";
class Solution{
    vector<string> ans;
    public:
    void dfs(int i,int j,int n,string route,vector<vector<int>> &m){
        if(!m[i][j])
            return;
        if(i==n-1 && j==n-1){
            ans.push_back(route);
            return;
        }
        m[i][j]=0;
        for(int k=0;k<4;k++){
            int x= i+dir[k], y =j+dir[3-k];
            if(x>=0 && y>=0 && x<n && y<n && m[x][y])
                dfs(x,y,n,route+D[k],m);
        }
        m[i][j]=1;
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        dfs(0,0,n,"",m);
        sort(ans.begin(),ans.end());
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