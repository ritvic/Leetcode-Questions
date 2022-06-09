// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool isSubsetSum(int arr[], int n, int sum,
                     vector<vector<int> >& dp)
    {
        if (sum == 0)
            return true;
        if (n == 0 && sum != 0)
            return false;
        if (dp[n][sum] != -1)
            return dp[n][sum];
            
        if (arr[n - 1] > sum)
            return isSubsetSum(arr, n - 1, sum, dp);
        return dp[n][sum]=isSubsetSum(arr,n-1,sum,dp)||isSubsetSum(arr,n-1,sum-arr[n-1],dp);
    }
    int equalPartition(int n, int arr[])
    {
        int sum = 0;
        for (int i = 0; i < n; i++)
            sum += arr[i];
        if (sum % 2 != 0)
            return false;
 
        vector<vector<int> > dp(n + 1,vector<int>(sum + 1, -1));
        return isSubsetSum(arr, n, sum / 2, dp);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}  // } Driver Code Ends