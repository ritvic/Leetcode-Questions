// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
#define ll long long

 // } Driver Code Ends
//User function template for C++
class Solution{
public:
	// #define ll long long
	ll countStrings(int n) {
	    // code here
	    long long m=1000000007;
	   long long int one=1;
	   long long int zero=1;
	   for(int i=2;i<=n;i++)
	   {
	      long long int newone= zero%m;
	      long long int newzero= (one+zero)%m;
	      
	      
	      one=newone;
	      zero=newzero;
	       
	   }
	   return (one+zero)%m;;
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.countStrings(n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends