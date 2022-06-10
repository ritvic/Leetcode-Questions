// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
public:
	bool recreationalSpot(int arr[], int n){
		// Your code goes here 
		stack<int>st;
		int k = INT_MIN;
		for(int  i = n-1; i>=0;i--)
		{
		    if(arr[i]<k)return true; //2
		    else{
		        while(!st.empty() and arr[i]>st.top())
		        {
		            k = st.top();
		            st.pop();
		        }
		        st.push(arr[i]);
		    }
		}
		return false;
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
		int arr[n];
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		Solution ob;
		if(ob.recreationalSpot(arr, n))
		    cout<<"True"<<endl;
		else
		    cout<<"False"<<endl;
	}
	return 0;
}  // } Driver Code Ends