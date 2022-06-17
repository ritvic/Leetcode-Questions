// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int kadanes(vector<int> &arr){
        int ans=INT_MIN,temp=0;
        for(int i=0;i<arr.size();i++){
            temp+=arr[i];
            ans=max(ans,temp);
            temp=max(temp,0);
        }
        return ans;
    }
    int maximumSumRectangle(int R, int C, vector<vector<int>> M) {
        int mx=INT_MIN;
        for(int i=0;i<R;i++){
            vector<int>v(C,0);
            for(int i1=i;i1<R;i1++){
                for(int j=0;j<C;j++){
                    v[j]+=M[i1][j];
                }
                mx=max(mx,kadanes(v));
            }
        }
        return (mx);
    }
};


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        Solution ob;
        cout << ob.maximumSumRectangle(N, M, v) << "\n";
    }
}  // } Driver Code Ends