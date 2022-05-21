// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> leftSmaller(int n, int v[]){
        // code here
        vector<int> res(n,-1);
        stack<pair<int,int>> st;
        st.push({v[n-1],n-1});
        for(int i=n-2;i>=0;i--)
        {
            while(!st.empty() && st.top().first>v[i])
            {
                res[st.top().second]=v[i];
                st.pop();
            }
            st.push({v[i],i});
        }
        return res;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i = 0;i < n;i++)
            cin>>a[i];
        
        Solution ob;
        vector<int> ans = ob.leftSmaller(n, a);
        for(int i = 0;i < n;i++)
            cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends