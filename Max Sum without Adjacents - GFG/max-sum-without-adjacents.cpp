// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// calculate the maximum sum with out adjacent
// 	int f(int index,int*arr,vector<int>&dp)
// 	{
// 	    if(index==0)return arr[index];
// 	    if(index<0)return 0;
// 	    if(dp[index]!=-1)return dp[index];
// 	    int take= arr[index]+f(index-2,arr,dp);
// 	    int not_take=0+f(index-1,arr,dp);
// 	    return dp[index]=max(take,not_take);
// 	}
// 	int findMaxSum(int *arr, int n)
// 	{
// 	    vector<int>dp(n,-1);
// 	    return f(n-1,arr,dp);
// 	}
	int findMaxSum(int *arr, int n)
    {
      int prev=arr[0];
       int prev2=0;
       int curr;
       
       for(int i=1;i<n;i++)
       {
           int take=arr[i];
        //   if(i>1)
           take+=prev2;
           int not_take=prev;
           curr=max(take,not_take);
           prev2=prev;
           prev=curr;
       }
       return prev;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends