// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    string smallestNumber(int sum, int D){
        // code here 
        int i=D;
        string s="";
        if(sum>D*9)
        return "-1";
        while(i>0)
        {
            if(sum>9)
            {
                s=to_string(9)+s;
                sum-=9;
            }
            else if(sum==9)
            {
                if(i==1)
                s=to_string(9)+s;
                else if(i==2)
                s=to_string(1)+to_string(8)+s;
                else
                {
                    while(i>2)
                    {
                        s=to_string(0)+s;
                        i--;
                    }
                    s=to_string(1)+to_string(8)+s;
                }
                return s;
            }
            else
            {
                if(i==1)
                {
                    s=to_string(sum)+s;
                    return s;
                }
                else if(i==2)
                {
                    s=to_string(sum-1)+s;
                    s=to_string(1)+s;
                    return s;
                }
                else
                {
                    s=to_string(sum-1)+s;
                    i--;
                    while(i>1)
                    {
                        s=to_string(0)+s;i--;
                    }
                    s=to_string(1)+s;
                    return s;
                    
                    
                }
            }
            i--;
            
        }
        return s;
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int S,D;
        cin >> S >> D;
        Solution ob;
        cout << ob.smallestNumber(S,D) << endl;
    }
    return 0; 
}   // } Driver Code Ends