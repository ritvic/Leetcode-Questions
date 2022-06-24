// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/* The function returns 1 if
IP string is valid else return 0
You are required to complete this method */
class Solution {
    public:
        bool isvalid(string t)
        {
            if(t.size()>3 || t.empty()) return false;
            for(auto i:t)
            {
                if(i<'0' || i>'9') return false;
            }
            int n=stoi(t);
            if(n<0 || n>255) return false;
            if(t[0]=='0' && t.size()>1) return false;
            return true;
        }
        int isValid(string s) {
            // code here
            int n=s.size(),c=0;
            for(int i=0;i<n;i++)
            {
                if(s[i]=='.')c++;
            }
            if(c!=3) return 0;
            string t="";
            for(int i=0;i<n;i++)
            {
                if(s[i]!='.' && i!=n-1)t+=s[i];
                else
                {
                    if(i==n-1)t+=s[i];
                    if(!isvalid(t)) return false;
                    t="";
                }
            }
            return true;
        }
};

// { Driver Code Starts.

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.isValid(s) << endl;
    }
    return 0;
}  // } Driver Code Ends