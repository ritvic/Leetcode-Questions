// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function template for C++
class Solution{
    public:int t[1001][1001] ;

    int match(string wild, string patt , int i , int j){
        if(i < 0 && j < 0){
            return 1 ;
        }
        if(i< 0 || j<0){
            return 0 ;
        }
        if(t[i][j] != -1){
            return t[i][j] ;
        }
        if(wild[i] == patt[j]){
            return t[i][j] = match(wild , patt , i-1,j-1);
        }
        if(wild[i] == '?'){
            return t[i][j] = match(wild , patt , i-1,j-1) ; 
        }
        if(wild[i] == '*'){
        return t[i][j] = match(wild ,patt ,i-1,j) || match(wild,patt,i-1,j-1) ||match(wild,patt,i,j-1) ;
        }
        return 0 ; // CASE WHERE wild[i] != patt[j] 
        
    }
    bool match(string wild, string patt)
    {
        // code here
        int n = wild.size() , m = patt.size() ;
        memset(t,-1,sizeof(t)) ;
        return match(wild , patt , n-1 , m-1) ;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string wild, pattern;
        cin>>wild>>pattern;
        
        Solution ob;
        if(ob.match(wild, pattern))
        cout<<"Yes\n";
        else
        cout<<"No\n";
    }
    return 0;
}  // } Driver Code Ends