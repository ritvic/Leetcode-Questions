// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	

    bool allones(string s, int n)
{
    // Checking each index is 0 or not.
    int co = 0;
    for (int i = 0; i < s.size(); i++)
        co += (s[i] == '1');
 
    return (co == n);
}
	int maxSubstring(string s)
	{
	    int n=s.size();
	    if(allones(s,n))
	    return -1;
	    int current_sum = 0;
    int max_sum = 0;
    for (int i = 0; i < n; i++) {
        current_sum += (s[i] == '0' ? 1 : -1);
 
        if (current_sum < 0)
            current_sum = 0;
 
        max_sum = max(current_sum, max_sum);
    }

    return max_sum == 0 ? -1 : max_sum;
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

   		cout << ob.maxSubstring(s) << "\n";
   	}

    return 0;
}
  // } Driver Code Ends