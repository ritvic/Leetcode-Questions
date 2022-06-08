// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
public:
    vector<int> maxMeetings(int N,vector<int> &S,vector<int> &F){
        pair<int, int> a[N + 1];
   int i;
   for (i = 0; i < N; i++) {
       a[i].first = F[i];
       a[i].second = i;
   }
   
   sort(a, a + N);
   int time_limit = a[0].first;
   vector<int> ans;
   ans.push_back(a[0].second + 1);
   for (i = 1; i < N; i++) {
       if (S[a[i].second] > time_limit) {
           ans.push_back(a[i].second + 1);
           time_limit = a[i].first;
       }
   }
   sort(ans.begin(),ans.end());
       return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> S(n),F(n);
        for(int i=0;i<n;i++){
            cin>>S[i];
        }
        for(int i=0;i<n;i++){
            cin>>F[i];
        }
        Solution ob;
        vector<int> ans=ob.maxMeetings(n,S,F);
        for(int i=0;i<ans.size();i++){
            cout<<ans[i];
            if(i!=ans.size()-1){
                cout<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends