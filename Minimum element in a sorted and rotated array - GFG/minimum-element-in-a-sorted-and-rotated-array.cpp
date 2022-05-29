// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int fun(int arr[],int low,int high)
    {
        
        if(low==high){
           return arr[low];
       }
        int mid = (low+high)/2;
       
           if(arr[mid]>arr[high]){
               fun(arr,mid+1,high);
           }
           else if(arr[mid]<arr[high]){
               fun(arr,low,mid);
           }
    }
    int findMin(int arr[], int n){
        //complete the function here
        return fun(arr,0,n-1);
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
		cin>>n;
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution ob;
		cout<<ob.findMin(a, n)<<endl;
	}
	return 0;
}  // } Driver Code Ends