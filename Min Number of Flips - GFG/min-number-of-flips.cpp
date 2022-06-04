// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int minFlips (string s);
int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;

        cout << minFlips (s) << endl;
    }
}
// Contributed By: Pranay Bansal
// } Driver Code Ends


int minFlips (string s)
{
    // your code here
    int c0 = 0,c1 = 0;
		for(int i = 0;i<s.length();i++){
			if(i%2 == 0 && s[i] == '1') c0++;
			else if(i%2 != 0 && s[i] == '0') c0++;
		}
		for(int i = 0;i<s.length();i++){
			if(i%2 == 0 && s[i] == '0') c1++;
			else if(i%2 != 0 && s[i] == '1') c1++;
		}
		return min(c0,c1);
        
}