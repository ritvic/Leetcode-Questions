// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    long long int count(int S[], int m, int n) 
    {
        vector<long long int>v(n+1);
        v[0]=1;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<=n;j++)
            {
                if(S[i]<=j)
                    v[j]+=v[j-S[i]];
            }
        }
        return v[n];
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int arr[m];
        for (int i = 0; i < m; i++) cin >> arr[i];
        Solution ob;
        cout << ob.count(arr, m, n) << endl;
    }

    return 0;
}  // } Driver Code Ends