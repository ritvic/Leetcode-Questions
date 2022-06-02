// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int canReach(int arr[], int n) {
        // code here
           if (n <= 1)
        return 1;
    if (arr[0] == 0)
        return 0;
    int maxReach = arr[0];
    
    int step = arr[0];
    
    int jump = 1;
    int i = 1;
    for (i = 1; i < n; i++) {
        if (i == n - 1)
            return 1;
 
        maxReach = max(maxReach, i + arr[i]);
        step--;
        if (step == 0) {
            jump++;
            if (i >= maxReach)
                return 0;
            step = maxReach - i;
        }
    }
 
    return 0;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int A[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];

        Solution ob;
        cout << ob.canReach(A,N) << endl;
    }
    return 0;
}  // } Driver Code Ends