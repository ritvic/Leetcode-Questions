// { Driver Code Starts
#include<bits/stdc++.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

 // } Driver Code Ends
/* You are required to complete the function below
*  arr[]: input array
*  n: size of array
*/
class Solution{
  public:
    //Function to find triplets with zero sum.
    bool findTriplets(int arr[], int n)
    { 
        sort(arr, arr+n);
        
        // set hash maps for values
        map<int, int> values;
        for(int i = 0; i < n; i++) {
            values[arr[i]]++;
        }
        
        // loop through two arrays
        for(int i = 0; i < n-2; i++) {
            for(int j = i+1; j < n-1; j++) {
                values[arr[i]]--;
                values[arr[j]]--;
                int val = arr[i] + arr[j];
                int valInv = -val;
                if(values[valInv] != 0) {
                    return true;
                }
                values[arr[i]]++;
                values[arr[j]]++;
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
	while(t--){
    	int n;
    	cin>>n;
    	int arr[n]={0};
    	for(int i=0;i<n;i++)
    		cin>>arr[i];
    	Solution obj;
        if(obj.findTriplets(arr, n))
            cout<<"1"<<endl;
        else 
            cout<<"0"<<endl;
	}
    return 0;
}  // } Driver Code Ends