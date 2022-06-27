// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
   public:
   //Function to find the largest number after k swaps.
   
   void backtrack(string & temp, string &s , int idx, int k){
       if(idx== s.size() or k==0) return; //BASE CASE
       int ii = idx;
       char maxv = temp[idx];
       // Finding the maximum character in the remaining substring
       for(int i=idx+1;i<s.size();i++){
           if(temp[i]>maxv){
               maxv = temp[i];
               ii = i;
           }
       }
       // if s[idx] is the maximum character
       if(ii==idx){
           backtrack(temp,s,idx+1,k);
       }
       else{
           vector<int> indices; //To store all possible indices of highest value
           for(int i=idx+1;i<s.size();i++){
               if(temp[i]==maxv) indices.push_back(i);
           }
           for(auto it : indices){
               swap(temp[it],temp[idx]);
               backtrack(temp,s,idx+1,k-1);
               s = max(s,temp);
               swap(temp[it],temp[idx]); //bakctrack
           }
       }
   }
   
   string findMaximumNum(string s, int k)
   {
      string temp = s;
      backtrack(temp,s,0,k);
      return s;
   }
};

// { Driver Code Starts.

int main()
{
    int t, k;
    string str;

    cin >> t;
    while (t--)
    {
        cin >> k >> str;
        Solution ob;
        cout<< ob.findMaximumNum(str, k) << endl;
    }
    return 0;
}
  // } Driver Code Ends