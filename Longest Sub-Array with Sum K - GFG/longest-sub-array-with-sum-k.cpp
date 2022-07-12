// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution{
    public:
    // int lenOfLongSubarr(int a[],  int n, int k) 
    // { 
    //     // Complete the function
    //     // int m=0;
    //     for(int i=1;i<n;i++)
    //     a[i]+=a[i-1];
    //     unordered_map<int,vector<int>> m;
    //     for(int i=0;i<n;i++)
    //     {
    //         m[a[i]].push_back(i);
    //     }
    //     for(auto i:m)
    //     {
    //         cout<<i.first<<" ";
    //         for(auto j:i.second)
    //         cout<<j<<" ";
    //     }
    //     for(auto x:m)
    //     {
    //         int i=x.first;
    //         vector<int> v1=x.second;
    //         if(m[k-i].size()!=0)
    //         {
    //             // return max({abs(m[i][0]-m[k-i].back()),abs(m[i].back()-m[k-i].back()),
    //             //             abs(m[i][0]-m[k-i][0]),abs(m[i].back()-m[k-i][0])});
    //             return max(v1[0],0);
    //         }
                
    //     }
    //     return 0;
    //     // 10 15 17 24 25 34
    // } 
    int lenOfLongSubarr(int a[],  int n, int k) 

    { 

        int ans=0,sum=0;

        unordered_map<int,int> mp;

        for(int i=0;i<n;i++){

            sum+=a[i];

            if(sum==k) 

            ans=i+1;

            if(mp.find(sum-k)!=mp.end())

                ans=max(ans,i-mp[sum-k]);

            if(mp.find(sum)==mp.end())

                mp[sum]=i;

        }

        return ans;

    }

};

// { Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends