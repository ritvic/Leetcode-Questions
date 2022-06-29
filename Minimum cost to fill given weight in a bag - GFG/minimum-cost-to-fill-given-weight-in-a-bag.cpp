// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
#include <bits/stdc++.h>
using namespace std;
//Position this line where user code will be pasted.

class Solution{
		

	public:
	int minimumCost(int cost[], int N, int W) 
	{ 
        vector<int> v(W+1,INT_MAX);
        v[0]=0;
        for(int i=1;i<=W;i++)
        {
            for(int j=0; j<N;j++)
            {
                if(j+1<=i and cost[j]!=-1 and v[i-j-1]!=INT_MAX)
                    v[i]=min(v[i],v[i-j-1]+cost[j]);
            }
        }
        return (v[W]==INT_MAX)?-1:v[W];
	}
};


// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, w;
        cin >> n >> w;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minimumCost(a, n, w) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends