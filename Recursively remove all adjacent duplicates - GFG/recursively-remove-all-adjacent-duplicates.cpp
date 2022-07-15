// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
public:
    bool palindrom(string s){
        int i=0,j=s.size()-1;
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++,j--;
        }
        return true;
    }
    void  removedub(string &s){
        string ans="";
        for(int i=0;i<s.size();i++){
            if(s[i]!='@') ans+=s[i];
        }
        s=ans;
    }
    void solve(string &s,int idx){
        
       
        for(int i=idx+1;i<s.size();i++){
            char a=s[i-1];
            if(s[i]==a){
                s[i-1]='@';
               while(i<s.size() and s[i]==a){
                   s[i]='@';i++;
               }
            }
        }
       
        string ans=s;
        removedub(s);
        if(ans==s) return ;
        solve(s,0);
       
    }
    string rremove(string s){
      if(palindrom(s)) return "";
      solve(s,0);
      return s;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);
        Solution ob;
        cout << ob.rremove(s) << "\n";
    }
    return 0;
}  // } Driver Code Ends