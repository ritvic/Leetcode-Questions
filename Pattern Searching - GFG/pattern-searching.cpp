// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	
	int search(string text, string pat)
	{
	    // Your code goes here
	    int n=text.size(),m=pat.size();
	    if(n<m)return 0;
	    if(n==m && text!=pat)return 0;
	    int i=0;
	    string s="";
	    while(i<m)
	    {s+=text[i];i++;}
	    while(i<n)
	    {
	       // cout<<s/<<" ";
	        if(s==pat)return 1;
	        s+=text[i];
	        s=s.substr(1);
	        i++;
	    }
	    if(s==pat)return 1;
	    return 0;
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
   		string x, y;
   		cin >> x >> y;



        Solution ob;
   		cout << ob.search(x, y) << "\n";
   	}

    return 0;
}  // } Driver Code Ends