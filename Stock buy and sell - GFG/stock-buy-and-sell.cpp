// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution{
public:
    //Function to find the days of buying and selling stock for max profit.
    vector<vector<int> > stockBuySell(vector<int> &v, int n){
        // code here
        int minn=v[0];
        vector<vector<int>> vv;
        int i=0,j=0;
        while(i<n && j<n)
        {
            if(v[i]<minn)
            {
                minn=v[i];
                i++;
                j++;
            }
            else
            {
                while(j+1<n && v[j]<v[j+1])
                j++;
                if(i!=j)
                vv.push_back({i,j});
                i=++j;
                minn=v[i];
            }
        }
        // for(auto i:vv)
        // for(auto j:i)
        // cout<<j<<" ";
        return vv;
    }
};

// { Driver Code Starts.

int check(vector<vector<int>> ans, vector<int> A, int p)
{
    int c = 0;
    for(int i=0; i<ans.size(); i++)
        c += A[ans[i][1]]-A[ans[i][0]];
    return (c==p) ? 1 : 0;
}

int main()
{   
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A(n);
        for (int i=0; i<n; ++i){
            cin>>A[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.stockBuySell(A, n);
        int p = 0;
        for(int i=0; i<n-1; i++)
        {
            int x = A[i+1]-A[i];
            if(x>0)
                p += x;
        }
        if(ans.size()==0)
            cout<<"No Profit";
        else{
            cout<<check(ans,A,p);
        }cout<<endl;
    }
    return 0;
}

  // } Driver Code Ends