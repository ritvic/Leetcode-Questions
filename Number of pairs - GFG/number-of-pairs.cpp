// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
    public:
        vector<int>par;
        int parent(int x){
        if(x==par[x])
            return x;
        return par[x]=parent(par[x]);
        }
    
        void unio (int x,int y){
        int a=parent(x);
        int b=parent(y);
        par[b]=a;
        }
    
        long long int numberOfPairs(vector<vector<int>> &pairs,int p,int n)
        {
            par.clear();
            for(int i=0;i<n;i++){
                par.push_back(i);
            }
            for(int i=0;i<pairs.size();i++){
                unio(pairs[i][0],pairs[i][1]);
            }
            unordered_map<int,int>mp;
            
            for(int i=0;i<n;i++){
                mp[parent(i)]++;
            }
            long long ans=0;
            for(auto m:mp){
                ans=ans+(m.second*(n-m.second));
            }
            return ans/2;
        }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,p;
        cin>>n>>p;
        vector<vector<int>> pairs(p,vector<int>(2));
        for(auto &i:pairs)
            for(auto &j:i)
                cin>>j;
        Solution a;
        cout<<a.numberOfPairs(pairs,p,n)<<endl;
    }
}  // } Driver Code Ends