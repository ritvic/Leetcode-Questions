// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n) ;


 // } Driver Code Ends
//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{
    public:
    vector<string>res;
    void helper(string &s,int open,int close){
        if(!open and !close){
            res.push_back(s);
            return;
        }
        if(open){
            s+="(";
            helper(s,open-1,close);
            s.pop_back();
        }
        if(close and close>open){
            s+=")";
            helper(s,open,close-1);
            s.pop_back();
        }
    }
    vector<string> AllParenthesis(int n) 
    {
        if(!n)return {};
        string s="";
        helper(s,n,n);
        return res;
    }
};

// { Driver Code Starts.


int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		Solution ob;
		vector<string> result = ob.AllParenthesis(n); 
		sort(result.begin(),result.end());
		for (int i = 0; i < result.size(); ++i)
			cout<<result[i]<<"\n";
	}
	return 0; 
} 
  // } Driver Code Ends