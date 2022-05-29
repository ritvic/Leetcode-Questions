// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int matSearch (vector <vector <int>> &v, int N, int M, int x)
	{
	    // your code here
	    int n=N-1,m=0;
	    while(n>=0 && m<M)
	    {
	        if(v[n][m]==x)
	        return 1;
	        else if(v[n][m]>=x)
	        n--;
	        else
	        m++;
	    }
	    return 0;
	}
};

// { Driver Code Starts.

int main ()
{
    int t; cin >> t;
    while (t--){
        int n, m; cin >> n >> m;
        vector <vector <int>> arr (n, vector <int> (m));
        for (int i=0;i<n;i++)
            for (int j=0;j<m;j++)
                cin >> arr[i][j];
                
        int x; cin >> x;
        Solution ob;
        cout << ob.matSearch (arr, n, m, x) << endl;
    }
}  // } Driver Code Ends