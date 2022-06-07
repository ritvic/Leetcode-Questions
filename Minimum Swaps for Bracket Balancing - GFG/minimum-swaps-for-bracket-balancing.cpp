// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    int minimumNumberOfSwaps(string S){
        // code here 
        int swap =0,c=0;
       
       for(int i =0;i<S.length();i++)
       {
           if(S[i] ==']')
           {
               c++;
               
               if(c > 0)
               swap += c;
           }
           else
           {
               c--;
           }
       }
       return swap;
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
        cin >> S;
        Solution ob;
        cout << ob.minimumNumberOfSwaps(S) << endl;
    }
    return 0; 
}   // } Driver Code Ends