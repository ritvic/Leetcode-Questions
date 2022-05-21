// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long v[], int n)
    {
        vector<long long> r1(n,n),r2(n,-1);
       stack<pair<long long,int>> st,st1;
       st.push({v[0],0});
       for(int i=0;i<n;i++)
       {
           while(!st.empty() && st.top().first>v[i])
           {
               r1[st.top().second]=i;
               st.pop();
           }
           st.push({v[i],i});
       }
       st1.push({v[n-1],n-1});
        for(int i=n-2;i>=0;i--)
       {
           while(!st1.empty() && st1.top().first>v[i])
           {
               r2[st1.top().second]=i;
               st1.pop();
           }
           st1.push({v[i],i});
       }
       long long maxx=-1;
       for(int i=0;i<n;i++)
           maxx=max(maxx,(r1[i]-r2[i]-1)*v[i]);
           
        // for(auto i:r1)
        // cout<<i<<" ";
        // cout<<endl;
        // for(auto i:r2)
        // cout<<i<<" ";
           
    return maxx;
       
    }
};


// { Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}
  // } Driver Code Ends