// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int getPairsCount(int v[], int n, int k) {
        // code here
        map<int,int> m;
        for(int i=0;i<n;i++)
        {
            if(m[v[i]])
            m[v[i]]++;
            else
            m[v[i]]=1;
        }
        int c=0;
        for(int i=0;i<n;i++)
        {
            int x = k - v[i];
            
            if(m[x] && v[i]==x)
            c+=m[x]-1;
            else if(m[x])
            c+=m[x];
        }
        return c/2;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getPairsCount(arr, n, k);
        cout << ans << "\n";
    }
    
    return 0;
}  // } Driver Code Ends