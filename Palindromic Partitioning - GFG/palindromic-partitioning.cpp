// { Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int palindromicPartition(string str)
    {
        // code here
        int n = str.size();
        vector<int> dp(n, 1e9);
        for(int i=0; i<n; i++){
            for(int l=i, r=i; l>=0 && r<n; l--, r++){
                if(str[l]==str[r]){
                    int t = l?dp[l-1]:0;
                    dp[r] = min(dp[r], t+1);
                }else{
                    break;
                }
            }
            for(int l=i-1, r=i; l>=0 && r<n; l--, r++){
                if(str[l]==str[r]){
                    int t = l?dp[l-1]:0;
                    dp[r] = min(dp[r], t+1);
                }else{
                    break;
                }
            }
        }
        return dp[n-1]-1;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}  // } Driver Code Ends