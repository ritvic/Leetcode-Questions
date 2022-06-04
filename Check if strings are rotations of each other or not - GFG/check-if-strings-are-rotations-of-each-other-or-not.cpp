// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution
{
    public:
    //Function to check if two strings are rotations of each other or not.
    bool areRotations(string s1,string s2)
   {
       if(s1.length() != s2.length()){
           return false;
       }
       
       int n = s2.length();
       
   // string could be rotated through last char at max (last case)
   // so we would perform n operations of ins, del and check.


       while(n--){
   //popping out the front character and inserting it at the end.


           s2.push_back(s2[0]);
           s2 = s2.substr(1);
           
// After every ins and del we will check whther the strings match
           if(s1 == s2){
               return true;
           }
       }


       return false;
   }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s1;
        string s2;
        cin>>s1>>s2;
        Solution obj;
        cout<<obj.areRotations(s1,s2)<<endl;

    }
    return 0;
}
  // } Driver Code Ends