// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    string solve(int arr[], int n) {
        // code here
        sort(arr, arr + n, greater<int>());
        int i = 0, one, two, carry = 0, sum;
        
        string ans = "";
        
        do {
            if(i < n) 
                one = arr[i]; 
            else 
                one = 0;
            if(i + 1 < n) 
                two = arr[i + 1]; 
            else
                two = 0;
            
            sum = one + two + carry;
            carry = sum/10;
            if(sum == 0 && carry == 0) 
                break;
            
            ans += to_string(sum % 10);
            i += 2;
            
        } while(carry > 0 || i < n);
        
        reverse(ans.begin(), ans.end());
        return ans;
   }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.solve(arr, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends