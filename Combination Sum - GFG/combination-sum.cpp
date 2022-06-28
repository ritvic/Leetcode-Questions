// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution {
 public:
   vector<vector<int>> ans;
   void bt(int i, int sum, int B, vector<int> v, vector<int> &A) {
       if(i>=A.size() || sum>B) return;
       if(sum==B) {
           ans.push_back(v); return;
       }
       v.push_back(A[i]);
       bt(i, sum+A[i], B, v, A);
       v.pop_back();
       bt(i+1, sum, B, v, A);
   }
   vector<vector<int> > combinationSum(vector<int> &A, int B) {
       sort(A.begin(), A.end());
       auto it = unique(A.begin(), A.begin() + A.size());
       A.resize(distance(A.begin(), it));
       vector<int> v;
       bt(0, 0, B, v, A);
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
        vector<int> A;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }   
        int sum;
        cin>>sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
   		if(result.size()==0){
   			cout<<"Empty";
   		}
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}	  // } Driver Code Ends