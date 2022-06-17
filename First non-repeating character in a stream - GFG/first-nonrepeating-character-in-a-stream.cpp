// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    queue<char> q;
		    unordered_map<char,int>m;
		    string s="";
		    for(auto i:A)
		    {
		        m[i]++;
		        q.push(i);
		        if(m[q.front()]==1)
		        s+=q.front();
		        else 
		        {
		            while(!q.empty() && m[q.front()]!=1) q.pop();
		            {if(q.empty()) s+="#";
		            else s+=q.front();}
		        }
		    }
		    return s;
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends