// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
	const int mod=1e9+7;
		int CountWays(string digits){
		    // Code here
		    int n=digits.size();
    	    int count[n+1];
            count[0] = 1;
            count[1] = 1;
            if(digits[0]=='0') 
                 return 0;
            for (int i = 2; i <= n; i++)
            {
                count[i] = 0;
                if (digits[i-1] > '0')
                    count[i] = count[i-1]%mod;
                if (digits[i-2] == '1' ||
                      (digits[i-2] == '2' && digits[i-1] < '7') )
                    count[i] = (count[i]+count[i-2])%mod;
            }//two triling zero has benn taken care of
            return count[n];
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.CountWays(str);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends