// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        int lvl = 0;
        vector <pair<int,int>> dir{{0,1}, {0,-1}, {1,0}, {-1,0}};
        if(A[0][0] == 0 || A[X][Y] == 0)
            return -1;
        queue <pair<int,int>> q;
        q.push({0, 0});
        while(!q.empty()){
            int n = q.size();
            while(n--){
                pair <int,int> p = q.front();
                q.pop();
                int x = p.first;
                int y = p.second;
                if(x == X && y == Y)
                    return lvl;
                for(auto i:dir){
                    int I = x + i.first;
                    int J = y + i.second;
                    if(I >= 0 && J >= 0 && I < N && J < M && A[I][J] == 1){
                        A[I][J] = 0;
                        q.push({I, J});
                    }
                }
            }
            lvl += 1;
        }
        return -1;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}  // } Driver Code Ends