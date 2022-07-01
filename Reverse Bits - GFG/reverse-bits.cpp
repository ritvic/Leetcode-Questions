// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
//     long long reversedBits(long long X) {
//       // code here
//       long long res = 0;
//       for(int i = 0; i < 32; i++){
//           res <<= 1;
//           if(X & 1) res++;
//           X >>= 1;
//       }
//       return res;
//   }
   long long reversedBits(long long x) {
        string str = bitset<32>(x).to_string();
        reverse(str.begin(),str.end());
        return stoll(str, 0, 2);
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long X;
        
        cin>>X;

        Solution ob;
        cout << ob.reversedBits(X) << endl;
    }
    return 0;
}  // } Driver Code Ends