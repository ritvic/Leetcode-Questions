// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int minFlips (string s);
int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;

        cout << minFlips (s) << endl;
    }
}
// Contributed By: Pranay Bansal
// } Driver Code Ends


int minFlips (string s)
{
    // your code here
    int e0=0,e1=0,o0=0,o1=0,n=s.size();
    for(int i=0;i<n;i++)
    {
        if(i%2==0)
        {
            if(s[i]=='0')
            e0++;
            else
            e1++;
        }
        else
        {
            if(s[i]=='0')
            o0++;
            else
            o1++;
        }}
        int a=0,b=0;
        // cout<<o1<<o0<<e1<<e0<<" ";  
        a=o1+e0;
        b=o0+e1;
        return min(a,b);
        
    
}