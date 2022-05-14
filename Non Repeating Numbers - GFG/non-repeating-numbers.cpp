// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
public:
    vector<int> singleNumber(vector<int> v) 
    {
        // Code here.
        int xo=0,n2,a=0,b=0;
        for(auto i:v)
        xo^=i;
        n2=xo & (~(xo-1));
        
        for(auto i:v)
        {
            if(i & n2)
            a^=i;
            else
            b^=i;
        }
        return vector<int> {min(a,b),max(a,b)};
    }
};

// { Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}  // } Driver Code Ends