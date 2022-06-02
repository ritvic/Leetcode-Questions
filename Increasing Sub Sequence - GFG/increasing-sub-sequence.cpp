// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int maxLength(string S)
    {
        // code here
        if(S.size()==0)
       return 0;
       vector<int> tail(S.size(),0);
       tail[0] = S[0];
       int length = 1;
       for(int i=1;i<S.size();i++)
       {
           auto it = lower_bound(tail.begin(),tail.begin()+length,S[i]);
           if(it == tail.begin()+length)
           {
               tail[length++] = S[i];
           }
           else *it = S[i];
       }
       return length;
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin>>S;
        Solution ob;
        cout << ob.maxLength(S) << endl;
    }
    return 0; 
}  // } Driver Code Ends