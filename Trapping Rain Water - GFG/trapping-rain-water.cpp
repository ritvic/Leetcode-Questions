// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        long long result = 0;
    int left_max = 0, right_max = 0;
    int lo = 0, hi = n - 1;
       while (lo <= hi) {
        if (arr[lo] < arr[hi]) {      
            if (arr[lo] > left_max)   
                left_max = arr[lo];
            else
                result += left_max - arr[lo]; 
            lo++;
        }
        else {
            if (arr[hi] > right_max)
                right_max = arr[hi];
            else
                result += right_max - arr[hi];
            hi--;
        }
    }
 
    return result;
        
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