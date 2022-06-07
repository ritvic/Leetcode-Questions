// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
		set<string> st;
	    void permutate(string k, string ans){
	        if(k.length() == 0){
	            st.insert(ans);
	            return;
	        }
	        for(int i=0;i<k.length();i++){
	         char ch = k[i];
	         string ros = k.substr(0,i) + k.substr(i+1);
	            
	            permutate(ros, ans+ch);
	        }
	    }
		vector<string>find_permutation(string S)
		{
		    permutate(S,"");
		    vector<string> Perm_ans(st.begin(),st.end());
		    return Perm_ans;
		}
};



// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}
  // } Driver Code Ends