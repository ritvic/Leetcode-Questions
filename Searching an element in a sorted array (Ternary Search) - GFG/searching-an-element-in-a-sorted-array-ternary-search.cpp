// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std;

 // } Driver Code Ends

class Solution{
    public:
    // Function to find element in sorted array
    // arr: input array
    // N: size of array
    // K: element to be searche
    int ternary(int l,int r,int key,int ar[])
    {
        if (r >= l) {

        int mid1 = l + (r - l) / 3;
        int mid2 = r - (r - l) / 3;
        if (ar[mid1] == key) {
            return 1;
        }
        if (ar[mid2] == key) {
            return 1;
        }
        if (key < ar[mid1]) {
            return ternary(l, mid1 - 1, key, ar);
        }
        else if (key > ar[mid2]) {
            return ternary(mid2 + 1, r, key, ar);
        }
        else {
            return ternary(mid1 + 1, mid2 - 1, key, ar);
        }
    }
    return -1;
    }
    int ternarySearch(int arr[], int N, int K) 
    { 
       return ternary(0,N-1,K,arr);
    }
};

// { Driver Code Starts.
int main(void) 
{ 
    
    int t;
    cin >> t;
    while(t--){
        int N, K;
        cin >> N >> K;
        
        int arr[N];
        
        for(int i = 0;i<N;i++){
            cin >> arr[i];
        }
        Solution ob;
        cout << ob.ternarySearch(arr, N, K) << endl;

    }

	return 0; 
} 
  // } Driver Code Ends