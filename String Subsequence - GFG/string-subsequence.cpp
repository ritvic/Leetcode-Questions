// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int count=0;
    void helper(string s1,string s2,int m,int n)
    {
       if(m==0)
       {
           return;
       }
     if(s1[m-1]==s2[n-1])
       {
           if(n==1)
           count++;
           helper(s1,s2,m-1,n-1);
         }
      
         helper(s1,s2,m-1,n);
    }
   int countWays(string s1, string s2){
       // code here
       int m=s1.length();
       int n=s2.length();
   helper(s1,s2,m,n);
     return count; 
     
   }
};

// { Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        string S1, S2;
        cin>>S1;
        cin>>S2;
        
        Solution ob;
        cout<<ob.countWays(S1, S2)<<endl;
    }
    return 0;
}  // } Driver Code Ends