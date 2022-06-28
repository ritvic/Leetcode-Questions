// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<vector<int>> ans;
    
    bool check(int col, vector<int> & temp){
        int n = temp.size(), diff = 1;
        
        /*
        
        checking for upper diagonals elements and upper row same column elements
             \    |    /   Diff = 3
              \   |   /    Diff = 2
               \  |  /     Diff = 1
                  j
        
        Diff is the difference of the current elements and upper row diagonal elements
        
        */
        
        for(int i=n-1; i>-1; i--){
            if(col+1 == temp[i] || abs(temp[i]-col-1) == diff) return 0;
            diff++;
        }
        
        return 1;
        
    }
    
    void solve(int row, vector<int>&temp, int n){
      
        if(row == n)
        {
            ans.push_back(temp);
            return ;
        }
        for(int col=0; col<n; col++)
        {
            if(check(col, temp))
            {
                temp.push_back(col+1);
                solve(row+1, temp, n);
                temp.pop_back();
            }
        }
        return ;
    }
    vector<vector<int>> nQueen(int n) 
    {
        vector<int> temp;
        solve(0, temp, n);
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
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends