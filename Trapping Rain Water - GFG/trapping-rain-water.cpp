// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        int left[n];
        int right[n];
        int maxLeft = arr[0];
        int maxRight = arr[n-1];
        for(int i=0,j=n-1;i<n && j>=0;i++,j--){
            if(arr[i]>maxLeft){
                maxLeft = arr[i];
            }
            if(arr[j]>maxRight){
                maxRight = arr[j];
            }
            left[i] = maxLeft;
            right[j] = maxRight;
        }
        long long water = 0;
        for(int i=0;i<n;i++){
            water = water + (min(right[i],left[i])-arr[i]);
        }
        return water;
        
    }
};

// { Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}  // } Driver Code Ends