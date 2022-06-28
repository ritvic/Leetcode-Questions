// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
public:

   vector<string> res;
    void perm(string &S, int i, string curr){
        if(i == S.size()){
            res.push_back(curr);
            return;
        }
        if(i)
        perm(S, i + 1, curr + " " + S[i]);
        perm(S, i + 1, curr + S[i]);
        
    }
    vector<string> permutation(string S){
        // Code Here
        perm(S, 0, "");
        return res;
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