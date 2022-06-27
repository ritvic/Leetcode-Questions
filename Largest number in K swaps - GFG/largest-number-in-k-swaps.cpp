// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to find the largest number after k swaps.
    void helper(string str, string &maxi, int k, int idx){
       if(k==0) return;
       char c = str[idx];
       for(int i = idx+1; i<str.length(); ++i){
           if(str[i]>c) c = str[i];
       }
       if(c != str[idx]) k--;
       for(int i =0; i<str.length(); i++){
           if(str[i]==c){
               swap(str[idx], str[i]);
               if(maxi < str) maxi = str;
               helper(str, maxi, k, idx+1);
               swap(str[idx], str[i]);
           }
       }
   }
   string findMaximumNum(string str, int k)
   {
      // code here.
      string maxi = str;
      helper(str, maxi, k, 0);
      return maxi;
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