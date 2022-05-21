// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int v[], int n){
        // code here
        
        
        vector<int> v1(n,-1),v2(n,-1);
        int m=-1;
        long long c=0;
        for(int i=0;i<n;i++)
        {
            m=max(m,v[i]);
            v1[i]=m;
        }
        m=-1;
        for(int i=n-1;i>-1;i--)
        {
            m=max(m,v[i]);
            v2[i]=m;
        }
        for(int i=0;i<n;i++)
        {
            c+=min(v1[i],v2[i])-v[i];
        }
        return c;
        
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