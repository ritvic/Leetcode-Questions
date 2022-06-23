// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'


 // } Driver Code Ends
class Solution{
    public:
    int minTime(vector<pair<int, int>> &dependency, int duration[], int n, int m) {
        int ind[n]={0},start[n]={0};
        vector<int> adj[n];
        for(auto it:dependency){
            adj[it.first].push_back(it.second);
            ind[it.second]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++)
            if(!ind[i])
                q.push(i);
        int ans=0,cnt=0;
        while(!q.empty()){
            int mod = q.front();
            cnt++;
            q.pop();
            ans = max(ans,start[mod]+duration[mod]);
            for(auto it: adj[mod]){
                start[it] = max(start[it],start[mod]+duration[mod]);
                if(!--ind[it])
                    q.push(it);
            }
        }
        return cnt==n ? ans:-1;
    }
};


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, x, y;
        cin >> n >> m;
        int duration[n + 5];
        vector<pair<int, int>> dependency;
        for (int i = 0; i < n; i++) cin >> duration[i];
        for (int i = 0; i < m; i++) {
            cin >> x >> y;
            dependency.push_back({x, y});
        }
        Solution obj;
        cout << obj.minTime(dependency, duration, n, m) << endl;
    }
    return 0;
}  // } Driver Code Ends