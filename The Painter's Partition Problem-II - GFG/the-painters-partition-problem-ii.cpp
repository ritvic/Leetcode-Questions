// { Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution
{
  public:
  long long canbe(int arr[],long long n,long long m,long long min)
  {
      long long block=0,painter=1;
      for(int i=0;i<n;i++)
      {
          if(arr[i]>min) return false;
          if(block+arr[i]>min)
          {
              painter++;block=arr[i];
              if(painter>m) return false;
          }
          else block+=arr[i];
      }
      return true;
  }
    long long minTime(int arr[], int n, int k)
    {
        // code here
        // return minimum time
        long long sum=0,value=-1;
        for(int i=0;i<n;i++) sum+=arr[i];
        long long start=0,end=sum;
        while(start<=end)
        {
            long long mid=(start+end)/2;
            if(canbe(arr,n,k,mid))
            {
                value=mid;end=mid-1;
            }
            else start=mid+1;
        }
        return value;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int k,n;
		cin>>k>>n;
		
		int arr[n];
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		Solution obj;
		cout << obj.minTime(arr, n, k) << endl;
	}
	return 0;
}  // } Driver Code Ends