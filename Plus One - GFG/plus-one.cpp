// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    vector<int> increment(vector<int> arr ,int n) {
        // code here
        reverse(arr.begin(),arr.end());
        arr[0]++;
        int c=0;
        for(int i=0;i<n;i++)
        {
            arr[i]+=c;
            c=arr[i]/10;
            arr[i]%=10;
        }
        if(c==1)
        arr.push_back(1);
                reverse(arr.begin(),arr.end());
return arr;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        char c;
        
        cin>>N;
        vector<int> arr(N);
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        vector<int> res = ob.increment(arr,N);
        for(int i: res)
            cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends