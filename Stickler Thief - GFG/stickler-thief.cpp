// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int fun(int v[],int n,vector<int> &dp)
    {
        if(n<0)
        return 0;
        if(dp[n]!=-1)
        return dp[n];
        return dp[n]=max(fun(v,n-2,dp)+v[n],fun(v,n-3,dp)+v[n-1]);
    }
    int FindMaxSum(int arr[], int n)
    {
        // Your code here
        vector<int> dp(10007,-1);

         
         return fun(arr,n-1,dp);
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}
  // } Driver Code Ends