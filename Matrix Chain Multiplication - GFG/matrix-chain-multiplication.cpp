// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
int dp[100][100];

class Solution{
public:
    int fun(int i,int j,int arr[])
    {
        if(i==j)
        return 0;
        if(dp[i][j]!=-1)
        return dp[i][j];
        dp[i][j]=INT_MAX;
        for(int k=i;k<j;k++)
        {
            dp[i][j]=min(dp[i][j],fun(i,k,arr)+fun(k+1,j,arr)+arr[i-1]*arr[k]*arr[j]);
        }
        return dp[i][j];

    }
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        memset(dp, -1, sizeof(dp));
        return fun(1,N-1,arr);
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
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}  // } Driver Code Ends