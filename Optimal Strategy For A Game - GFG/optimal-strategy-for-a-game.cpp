// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

//Function to find the maximum possible amount of money we can win.
vector<vector<long long>> dp;
class Solution{
    public:
    long long fun(int arr[],int i,int j)
    {
        if(i==j)
        return dp[i][j]=arr[i];
        if(j-i==1)
        return dp[i][j]=max(arr[i],arr[j]);
        if(i>j)
        return dp[i][j]=0;
        if(dp[i][j]!=-1)
        return dp[i][j];
        long long a,b;
        a=arr[i]+min(fun(arr,i+2,j),fun(arr,i+1,j-1));
        b=arr[j]+min(fun(arr,i+1,j-1),fun(arr,i,j-2));
        return dp[i][j]=max(a,b);
    }
    long long maximumAmount(int arr[], int n){
        // Your code here
        dp=vector<vector<long long>> (n+1,vector<long long> (n+1,-1));
        return fun(arr,0,n-1);
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