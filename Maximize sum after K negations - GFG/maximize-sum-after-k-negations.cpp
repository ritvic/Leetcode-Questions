// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    long long int maximizeSum(long long int a[], int n, int k)
    {
        // Your code goes here
        sort(a,a+n);
        int idx=0;
        while(k && idx<n)
        {
            if(a[idx]<0)
            {
               a[idx]=-1*a[idx];
               idx++;
               k--;
            }
            else
                break;
        }
        sort(a,a+n);
        if(k!=0 && k%2==1)
        {
            a[0]=-1*a[0];
        }
        long long int ans=0;
        for(int i=0;i<n;i++)
        {
            ans+=a[i];
        }
        return ans;
    }
};

// { Driver Code Starts.
int main()
 {
     int t;
     cin>>t;
     while(t--)
     {
         int n, k;
         cin>>n>>k;
         long long int a[n+5];
         for(int i=0;i<n;i++)
         cin>>a[i];
         Solution ob;
         cout<<ob.maximizeSum(a, n, k)<<endl;
     }
	
	return 0;
}  // } Driver Code Ends