// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &v, int k) {
        // Your code goes here
        int n=v.size();
        vector<vector<int>> vv;
        sort(v.begin(),v.end());
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int f=k-v[i]-v[j];
                int k=j+1,l=n-1;
                while(k<l)
                {
                    if(v[k]+v[l]==f)
                        {vv.push_back({v[i],v[j],v[k],v[l]});k++;l--;}
                    else if(v[k]+v[l]>f) l--;
                    else k++;
                }
            }
        }
        sort(vv.begin(),vv.end());
        vector<vector<int>>::iterator ip;
  
    ip = std::unique(vv.begin(), vv.end());
    vv.resize(std::distance(vv.begin(), ip));
        return vv;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends