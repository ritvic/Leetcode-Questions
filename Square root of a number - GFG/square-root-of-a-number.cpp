// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

  

 // } Driver Code Ends
// Function to find square root
// x: element to find square root
class Solution{
  public:
    long long int floorSqrt(long long int x) 
    {
        // Your code goes here   
        long long l=1,h=x,mid;
        while(l<=h)
        {
            mid=(l+h)/2;
            if((mid*mid)==x || ((mid*mid)<x && ((mid+1)*(mid+1))>x))
            return mid;
            if(mid*mid<x)
            l=mid;
            else
            h=mid;
        }
        return mid;
        
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		Solution obj;
		cout << obj.floorSqrt(n) << endl;
	}
    return 0;   
}
  // } Driver Code Ends