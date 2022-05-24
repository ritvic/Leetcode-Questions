// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:

    int smallestSubWithSum(int v[], int n, int x)
    {
        // Your code goes here 
        int i=0,j=1,minn=INT_MAX,sum=v[i];
        while(i<n)
        {
            
            while(sum<=x && j<n)
            {
                sum+=v[j];
                j++;
            }
            // cout<<sum<<" ";
            if(sum>x)
            minn=min(minn,j-i);
            // cout<<j-i<<" ";
            sum-=v[i];
            i++;
        }
        return minn;
    }
};

// { Driver Code Starts.

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n,x;
		cin>>n>>x;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution obj;
		cout<<obj.smallestSubWithSum(a,n,x)<<endl;
	}
	return 0;
}  // } Driver Code Ends