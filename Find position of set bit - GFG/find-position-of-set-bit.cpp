// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    int findPosition(int n) {
        // code here
        
        
        int count=0,p=1;
        while(n)
        {
            if(n&1)count++;
            else p++;
            n>>=1;
            
        }
        if (count==1)
        return p;
        else
        return -1;
        
        
    }
    
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;

        cin>>N;

        Solution ob;
        cout << ob.findPosition(N) << endl;
    }
    return 0;
}  // } Driver Code Ends