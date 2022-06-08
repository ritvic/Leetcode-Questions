// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string s) {
        //Your code here
        int n=s.size();
        int a=0,i=0,flag=1;
        if(s[0]=='-')
        {flag=0;i++;n--;}
        while(i<s.size())
        {
            if(s[i]>='0' && s[i]<='9')
            {a+=(s[i]-'0')*pow(10,n-1);
            n--;}
            else return -1;
            i++;
        }
        return (flag)?a:a*-1;
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}  // } Driver Code Ends