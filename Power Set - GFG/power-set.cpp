// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	vector<string> ans;
    void solve(string &s, string&temp, int ind){
        if(ind>=s.size()) {
            if(temp!="")
                ans.push_back(temp);
            return;
        }
        temp.push_back(s[ind]);
        solve(s, temp, ind+1);
        temp.pop_back();
        solve(s, temp, ind+1);
    }
	vector<string> AllPossibleStrings(string s){
	    string temp="";
	    solve(s, temp, 0);
	    sort(ans.begin(), ans.end());
	    return ans;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}  // } Driver Code Ends