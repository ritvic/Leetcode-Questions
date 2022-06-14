// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int minValue(string s, int k){
        // code here
        int ans=0;
        priority_queue<int>pq;
        unordered_map<char,int>mp;
        for(auto x:s){
            mp[x]++;
        }
       
        for(auto x:mp){
            pq.push(x.second);
        }
        while(!pq.empty() && k--){
            int a=pq.top();
            pq.pop();
            if(--a>0){
                pq.push(a);
            }
            
        }
        while(!pq.empty()){
            ans+=pq.top()*pq.top();
            pq.pop();
        }
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        int k;
        cin>>s>>k;
        
        Solution ob;
        cout<<ob.minValue(s, k)<<"\n";
    }
    return 0;
}  // } Driver Code Ends