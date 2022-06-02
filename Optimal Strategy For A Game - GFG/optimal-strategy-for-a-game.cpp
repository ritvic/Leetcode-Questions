// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

//Function to find the maximum possible amount of money we can win.
vector<vector<long long>> dp;
class Solution{
    public:
    long long oSRec(int arr[], int i, int j, long long sum)
    {
        if (j == i + 1)
        return max(arr[i], arr[j]);
 
    if (dp[i][j] != -1)
        return dp[i][j];
    dp[i][j] = max((sum - oSRec(arr, i + 1, j, sum - arr[i])),
                     (sum - oSRec(arr, i, j - 1, sum - arr[j])));
 
    return dp[i][j];
    }

    long long maximumAmount(int arr[], int n){
        dp=vector<vector<long long>>(n+1,vector<long long>(n+1,-1));
        long long sum = 0;
        sum = accumulate(arr, arr + n, sum);
        return oSRec(arr, 0, n - 1, sum);
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
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		cout<< ob.maximumAmount(a,n)<<endl;
	}
	return 0;
}  // } Driver Code Ends