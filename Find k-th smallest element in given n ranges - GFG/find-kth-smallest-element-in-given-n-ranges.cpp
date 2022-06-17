// { Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    vector<int>kthSmallestNum(vector<vector<int>>&a, vector<int>q){
        //Write your code here
        
        sort(a.begin(),a.end(),[&](vector<int> &a,vector<int> &b){return a[0]<b[0];});
        vector<vector<int>> v;
        int n=a.size();
        v.push_back(a[0]);
        for(int i=1;i<n;i++)
        {
            if(a[i][0]>v[v.size()-1][1])
            v.push_back(a[i]);
            else{ v[v.size()-1][1]=max(a[i][1],v[v.size()-1][1]);}
        }
        vector<int> b;
        for(auto i:v)
        for(int j=i[0];j<=i[1];j++)
        b.push_back(j);
        n=b.size();
        for(int i=0;i<q.size();i++)
        {
            if(q[i]>n)
            q[i]=-1;
            else q[i]=b[q[i]-1];
        }
        return q;
    } 
};


// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    vector<vector<int>>range(n, vector<int>(2, 0));
	    for(int i = 0 ; i < n; i++){
	        cin >> range[i][0] >> range[i][1];
	    }
	    int q;
	    cin >> q;
	    vector<int>queries;
	    for(int i = 0 ; i < q; i++){
	        int x;
            cin >> x;
	        queries.push_back(x);
	    }
	    Solution ob;
	    vector<int>ans = ob.kthSmallestNum(range, queries);
	    for(auto it : ans){
	        cout << it << " ";
	    }
	    cout << endl;
	}
	return 0;
}
  // } Driver Code Ends