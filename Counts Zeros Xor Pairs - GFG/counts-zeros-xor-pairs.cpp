// { Driver Code Starts
// C++ program to find number 
// of pairs in an array such
// that their XOR is 0
#include <bits/stdc++.h>
using namespace std;

// Function to calculate the
// count
long long int calculate(int a[], int n);

// Driver Code
int main()
{

	int t;
	cin>>t;
	while(t--)
	{
	  int n;
	  cin>>n;
	  int arr[n+1];
	  for( int i=0;i<n;i++)
	        cin>>arr[i];
	    cout << calculate(arr, n)<<endl;
        
	}
	return 0;
}

// } Driver Code Ends

#include<bits/stdc++.h>
long long int calculate(int a[], int n)
{
    // Complete the function
    map<vector<int>,int>m;
    for(int i=0;i<n;i++)
    {
        int x=a[i];
        vector<int> v(31,0);
        for(int j=0;j<31;j++)
        {
            v[j]=x&(1<<j);
        }
        m[v]++;
    }
    long long sum=0;
    for(auto i:m)
    {
        if(i.second>1)
        {
            long long x=i.second;
            sum+=((x-1)*x)/2;
        }
    }
    return sum;
    
}
