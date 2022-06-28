// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    bool ispalin(string s)
    {
      int n=s.length();
      for(int i=0;i<n/2;i++)
      {
          if(s[i]!=s[n-1-i])return false;
      }
      return true;
  }
  void solve(string s,vector<vector<string>>&ans,vector<string>temp){
      if(s.size()==0){
          ans.push_back(temp);
          return;
      }
      for(int i=0;i<s.length();i++)
      {
          string chk=s.substr(0,i+1);
          if(ispalin(chk))
          {
              temp.push_back(chk);
              solve(s.substr(i+1),ans,temp);
              temp.pop_back();
          }
      }
      return;
  }
    vector<vector<string>> allPalindromicPerms(string S) {
        vector<vector<string>>ans;
        vector<string>temp;
        solve(S,ans,temp);
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        
        cin>>S;

        Solution ob;
        vector<vector<string>> ptr = ob.allPalindromicPerms(S);
        
        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                cout<<ptr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends