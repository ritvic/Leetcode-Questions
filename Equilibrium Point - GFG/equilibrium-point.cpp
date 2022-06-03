// { Driver Code Starts
#include <iostream>
using namespace std;


 // } Driver Code Ends

#include<bits/stdc++.h>
class Solution{
    public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    int equilibriumPoint(long long v[], int n) {
    
        // Your code here
        long long sum=accumulate(v,v+n,0LL);
        int a=0;
        for(int i=0;i<n;i++)
        {
            if(i>0)
            a+=v[i-1];
            sum-=v[i];
            if(a==sum)
            return i+1;
        }
        return -1;
    }

};

// { Driver Code Starts.


int main() {

    long long t;
    
    //taking testcases
    cin >> t;

    while (t--) {
        long long n;
        
        //taking input n
        cin >> n;
        long long a[n];

        //adding elements to the array
        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        Solution ob;

        //calling equilibriumPoint() function
        cout << ob.equilibriumPoint(a, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends