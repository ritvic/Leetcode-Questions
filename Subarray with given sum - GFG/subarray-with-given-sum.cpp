// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(int a[], int n, long long k)
    {
        // Your code here
        int i=0,j=0;
        long long sum=0;
        while(i<n && j<n)
        {
            sum+=a[j];
            if(sum==k)
            {
                break;
            }
            else if(sum<k)
            j++;
            else
            {
                sum-=a[i]+a[j];
                i++;
            }
        }
        if(j<n && i<n )
        return vector <int> {i+1,j+1};
        else return vector<int> {-1};
        
    }
};

// { Driver Code Starts.

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        long long s;
        cin>>n>>s;
        int arr[n];
        const int mx = 1e9;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}  // } Driver Code Ends