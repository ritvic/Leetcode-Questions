// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution
{
    public:
    int isCircle(int n, vector<string> A)
    {
        // code here
        unordered_map<char,int> m;
        unordered_map<char,int> m1;
        //m1 for finding the words which have same letters at the start and end
        unordered_map<char,int> m2;
        for(int i = 0 ; i < n ;i++)
        {
            m[A[i][0]]++; 
            if(A[i][0] == A[i][A[i].size()-1]) m1[A[i][0]]++;
            m2[A[i][A[i].size()-1]]++; 
        }
        for(int i = 0 ; i < n ;i++){
            if(m[A[i][0]] != m2[A[i][0]]) return 0;
            
            if(m[A[i][0]] == m1[A[i][0]]){ // IF THIS EXIST MEANS ALL STRINGS THERE SHOULD HAVE SAME FIRST AND LAST  DIGITS
                if(n != m[A[i][0]])
                return 0;
                return 1;
            }
        }
        return 1;
        
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<string> A;
        string s;
        
        for(int i = 0;i < N; i++)
        {
            cin>>s;
            A.push_back(s);
        }
        
        Solution ob;
        cout<<ob.isCircle(N, A)<<endl;
    }
    return 0;
}  // } Driver Code Ends