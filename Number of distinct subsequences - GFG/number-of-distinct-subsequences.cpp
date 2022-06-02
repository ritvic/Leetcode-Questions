// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
const int MAX_CHAR = 256;
const int mod=1e9+7;
class Solution{
  public:	
	int distinctSubsequences(string str)
	{
	    vector<int> last(MAX_CHAR, -1);
 
    int n = str.length();
 

    long long dp[n + 1];
 
    dp[0] = 1;
 
    for (int i = 1; i <= n; i++) {
        dp[i] = (2 * dp[i - 1]%mod)%mod;
        if (last[str[i - 1]] != -1)
            dp[i] = (dp[i] - dp[last[str[i - 1]]] +mod)%mod;
 
        last[str[i - 1]] = (i - 1);
    }
 
    return dp[n]%mod;
	}
};

// { Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

        Solution ob;
   		cout << ob.distinctSubsequences(s) << "\n";
   	}

    return 0;
}  // } Driver Code Ends