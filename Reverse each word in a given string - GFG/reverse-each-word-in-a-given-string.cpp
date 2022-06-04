// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
  public:
    string reverseWords (string s)
    {
        //code here.
        string a="";
        stack<char> st;
        for(auto i:s)
        {
            if(i!='.')
            st.push(i);
            else
            {
                while(!st.empty())
                {
                    a+=st.top();
                    st.pop();
                }
                a+=".";
            }
        }
        while(!st.empty())
            {
                a+=st.top();
                st.pop();
            }
            return a;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.reverseWords (s) << endl;
    }
    return 0;
}

// Contributed By: Pranay Bansal
  // } Driver Code Ends