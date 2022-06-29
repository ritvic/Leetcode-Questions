// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++


class Solution
{
    public:
    //Function to find length of shortest common supersequence of two strings.
    int shortestCommonSupersequence(string X, string Y, int m, int n)
    {
        int arr[m+1][n+1];
       for(int i =0;i<m+1;i++)
       {
           for(int j =0;j<n+1;j++)
           {
               if(i==0 || j==0)
               {
                   arr[i][j] =0;
               }
               else if(X[i-1]==Y[j-1])
               {
                   arr[i][j] = 1+arr[i-1][j-1];
               }
               else{
                   arr[i][j] = max(arr[i-1][j],arr[i][j-1]);
               }
           }
       }
       return (m+n-arr[m][n]);
    }
};

// { Driver Code Starts.

int main()
{   
    
    int t;
    
    //taking total testcases
    cin >> t;
    while(t--){
    string X, Y;
    //taking String X and Y
	cin >> X >> Y;
	
	//calling function shortestCommonSupersequence()
	Solution obj;
	cout << obj.shortestCommonSupersequence(X, Y, X.size(), Y.size())<< endl;
    }
	return 0;
}

  // } Driver Code Ends