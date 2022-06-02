// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    int circularSubarraySum(int a[], int n)
    {
        int max_kadane = kadane(a, n);
        if(max_kadane < 0)
        return max_kadane;
        int max_wrap = 0, i;
        int maxele=a[0];
        for (i = 0; i < n; i++) 
        {
            maxele=max(maxele,a[i]);
            max_wrap += a[i];
            a[i] = -a[i];
        }
        max_wrap = max_wrap + kadane(a, n);
        if (max(max_wrap, max_kadane) ==0)
        return maxele;
        return (max_wrap > max_kadane) ? max_wrap : max_kadane;
    }
    int kadane(int a[], int n)
    {
        int max_so_far = 0, max_ending_here = 0;
        int i;
        for (i = 0; i < n; i++) 
        {
            max_ending_here = max_ending_here + a[i];
            if (max_so_far < max_ending_here)
                max_so_far = max_ending_here;
            if (max_ending_here < 0)
                max_ending_here = 0;
        }
        return max_so_far;
    }
};

// { Driver Code Starts.

int main()
 {
	int T;
	
	//testcases
	cin>> T;
	
	while (T--)
	{
	    int num;
	    
	    //size of array
	    cin>>num;
	    int arr[num];
	    
	    //inserting elements
	    for(int i = 0; i<num; i++)
	        cin>>arr[i];
	        
	    Solution ob;
	    //calling function
	    cout << ob.circularSubarraySum(arr, num) << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends