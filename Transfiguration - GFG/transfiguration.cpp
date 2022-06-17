// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    
    public:
    int transfigure (string a, string b)
    {
    	// Your code goes here
    	int n=a.size();
    	if(n!=b.size()) return -1;
    	int i=n-1,j=n-1;
    	unordered_map<char,int> m;
    	
    	while(i>=0)
    	{
    	    if(a[i]==b[j]){i--;j--;}
    	    else
    	    {m[a[i]]++;i--;}
    	}
    	i=j;
    	int c=0;
    	for(auto it:m) c+=it.second;
    // 	cout<<c<< " "<<j+1;
    	if(c!=j+1)return -51;
    	
    	while(j>=0)
    	{
    	    if(m[b[j]]==0) return -1;
    	    else {m[b[j]]--;j--;}
    	}
    	for(auto it:m) if(it.second!=0) return -1;
    	return i+1;
    // 	return -41;
    }
};

// { Driver Code Starts.


int main () 
{
    int t; cin >> t;
    while (t--)
    {
        string A, B; 
        cin >> A >> B;
        Solution obj;
        cout << obj.transfigure (A, B) << endl;
    }
}  // } Driver Code Ends