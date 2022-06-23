// { Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h> 
using namespace std; 


 // } Driver Code Ends
//User function Template for C++

class Solution {
public:
vector<pair<int, int> > direction= { { 1, 0 }, { 0, -1 }, { -1, 0 }, { 0, 1 } };
    int helpaterp(vector<vector<int>> arr)
   {
       int n = arr.size();

    int m = arr[0].size();
    int timeofinfection[n][m];
    queue<pair<pair<int, int>, int> > q;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            timeofinfection[i][j] = -1;
            // is already infected
            if (arr[i][j] == 2) {
                q.push({ { i, j }, 0 });
                timeofinfection[i][j] = 0;
            }
        }
    }

    while (!q.empty()) {
        pair<pair<int, int>, int> current= q.front();
        q.pop();
        for (auto it : direction) {
            int i = current.first.first
                    + it.first;
            int j = current.first.second
                    + it.second;
            if (i < 0 || j < 0 || i >= n
                || j >= m || arr[i][j] != 1
                || timeofinfection[i][j] != -1) {
                continue;
            }
            q.push({ { i, j },
                     current.second + 1 });
            timeofinfection[i][j]
                = current.second + 1;
        }
    }

    int maxi = INT_MIN;
    int flag = 0;

    // Traverse the matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] != 1)
                continue;
            if (arr[i][j] == 1
                && timeofinfection[i][j] == -1) {
                flag = 1;
                break;
            }
            maxi = max(maxi, timeofinfection[i][j]);
        }
    }
    if (flag)
        return -1;
    return maxi;
   }


};


// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int R;int C;
        
        cin>>R>>C;
        vector<vector<int>> hospital;
        int i,j;
        for(i=0;i<R;i++)
         {   vector<int> temp;
             for(j=0;j<C;j++)
            {
                int k;
                cin>>k;
                temp.push_back(k);
            }
            hospital.push_back(temp);
         }
        
        Solution ob;
        int ans = ob.helpaterp(hospital);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends