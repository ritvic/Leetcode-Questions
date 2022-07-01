// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
		int nthPoint(int n){
		   long long int m = 1000000007;
		   vector<int>dp(n+1);
		   dp[0] = dp[1] = 1;
		   for(int i = 2 ; i <= n ; i++){
		       dp[i] = (dp[i-1] + dp[i-2])%m;
		   }
		   return dp[n];
		}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans  = ob.nthPoint(n);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends