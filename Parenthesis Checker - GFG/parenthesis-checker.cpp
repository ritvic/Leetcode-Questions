// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        // Your code here
        vector<char> stk;
    for( const char c: x ){
        if( c == '{' or c == '(' or c == '[' ){
            stk.push_back( c );
        } else {
            if( stk.empty() ) return false;
            if( c == '}' ){
                if( stk.back() != '{' ) return false;
            } else if( c == ')' ){
                if( stk.back() != '(' ) return false;
            } else if( c == ']' ){
                if( stk.back() != '[' ) return false;
            } else {
                return false;
            }
            stk.pop_back();
        }
    }
    return stk.empty();
    }

};

// { Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}  // } Driver Code Ends