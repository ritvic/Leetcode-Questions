// { Driver Code Starts


#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
  public:
    int subArraySum(int nums[], int n, int k)
    {
    	unordered_map<int,int> help;
        help[0]++;
        int res=0;
        for(int i=0;i<n;i++){
            if(i>0)
                nums[i]+=nums[i-1];
            res+=help[nums[i]-k];
            help[nums[i]]++;
        }
        return res;
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,sum=0;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	    cin>>sum;
	    Solution ob;
	    cout<<ob.subArraySum(arr, n, sum);
	    cout<<'\n';
	}
	return 0;
}  // } Driver Code Ends