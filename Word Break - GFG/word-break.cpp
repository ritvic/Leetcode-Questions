// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
public:
    int wordBreak(string A, vector<string> &B) 
    {
        unordered_set<string> st;
        for(auto &str: B) st.insert(str);
        
        vector<int> dp(A.size() + 1, 0);
        for(int i = 1; i <= A.size(); i++) {
            if(st.find(A.substr(0, i)) != st.end()) dp[i] = 1;
            for(int j = 1; j <= i; j++) {
                string part1 = A.substr(0, j);
                string part2 = A.substr(j, i - j);
                if(st.find(part2) != st.end()) dp[i] += dp[j];
            }
        }
        return dp[A.size()];
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}
  // } Driver Code Ends