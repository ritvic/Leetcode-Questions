// { Driver Code Starts
// Initial Template for C++



#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
     list<int>dq;
   unordered_map<int ,list<int>::iterator> mp;
public:
   int ans=0;
   void refer(int x ,int c){
       if(mp.find(x)==mp.end()){
           if(dq.size()==c){
               mp.erase((int)dq.back());
               dq.pop_back();
           }
           ans++;
           dq.push_front(x);
           mp[x]=dq.begin();
       }
       else{
           dq.erase(mp[x]);
           dq.push_front(x);
           mp[x]=dq.begin();
       }
   }
   int pageFaults(int N, int C, int pages[]){
       for(int i=0;i<N;i++){
           refer(pages[i],C);
       }
       return ans;
   }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, C;
        cin>>N;
        int pages[N];
        for(int i = 0;i < N;i++)
            cin>>pages[i];
        cin>>C;
        
        Solution ob;
        cout<<ob.pageFaults(N, C, pages)<<"\n";
    }
    return 0;
}  // } Driver Code Ends