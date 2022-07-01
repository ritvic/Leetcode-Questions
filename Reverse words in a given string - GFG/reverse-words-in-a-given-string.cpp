// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:

        string reverseWords(string S) 
       { 
           // code here 
           string revS = "";
           int sz = S.length();
           int lastDot = sz;
           
           for(int i = sz-1 ; i >= 0; i--)
           {
               char c = S[i];
               if(c == '.') 
               {
                   string word  = S.substr(i + 1, lastDot - i - 1);
                   revS.append(word);
                   revS += '.';
                   
                   lastDot = i;
                   
               }
           }
           
           string word  = S.substr(0, lastDot);
           revS.append(word);
           
           return revS;
       }  
};

// { Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}  // } Driver Code Ends