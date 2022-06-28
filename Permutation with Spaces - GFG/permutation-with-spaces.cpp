// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
public:
void solve(vector<string>&ans,string s,int n,int i,string temp){
    if(i==n){
        ans.push_back(temp);
        return;
    }
    if(s[i]==' '){
        solve(ans,s,n,i+1,temp+' ');
        solve(ans,s,n,i+1,temp);
        return;
    }
    else {
        solve(ans,s,n,i+1,temp+s[i]);
        return;
    }
    return;
}

    vector<string> permutation(string S){
        vector<string>ans;
        string s;
        int n=S.length();
        for(int i=0;i<n;i++){
            s+=S[i];
            if(i!=n-1)s+=' ';
            }
         
            solve(ans,s,s.length(),0,"");
            return ans;
    }
};

// { Driver Code Starts.

int  main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        vector<string> ans;
        Solution obj;
        ans = obj.permutation(S);
        for(int i=0;i<ans.size();i++){
            cout<<"("<<ans[i]<<")";
        }
        cout << endl;
    }
}
  // } Driver Code Ends