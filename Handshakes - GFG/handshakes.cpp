// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int count(int N){
        // code here
        
        
        vector<int>dp(N+1,0);
       dp[0]=1;
       for(int n=2;n<=N;n+=2){
           for(int i=0;i<=n-2;i+=2){
               dp[n]+=dp[i]*dp[n-2-i];
           }
       }
       return dp[N];
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.count(N) << endl;
    }
    return 0; 
}  // } Driver Code Ends