// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// calculate the maximum sum with out adjacent
	int f(int index,int*arr,vector<int>&dp)
	{
	    if(index==0)return arr[index];
	    if(index<0)return 0;
	    if(dp[index]!=-1)return dp[index];
	    int take= arr[index]+f(index-2,arr,dp);
	    int not_take=0+f(index-1,arr,dp);
	    return dp[index]=max(take,not_take);
	}
	int findMaxSum(int *arr, int n)
	{
	    vector<int>dp(n,-1);
	    return f(n-1,arr,dp);
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