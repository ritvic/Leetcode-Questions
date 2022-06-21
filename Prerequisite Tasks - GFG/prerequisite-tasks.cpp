// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	bool isPossible(int N, vector<pair<int, int>>& prerequisites) {
	    vector<vector<int>> AList(N, vector<int>());
	    vector<int> indegree(N, 0);
	    
	    for(pair<int,int> &edge : prerequisites){
	        AList[edge.first].push_back(edge.second);
	        indegree[edge.second]++;
	    }
	    
	    queue<int> queue;
	    
	    for(int i=0; i<N; i++){
	        if(indegree[i] == 0){
	            queue.push(i);
	        }
	    }
	    
	    while(not queue.empty()){
	        int u = queue.front();
	        queue.pop();
	        
	        for(int v : AList[u]){
	            indegree[v]--;
	            
	            if(indegree[v] == 0){
	                queue.push(v);
	            }
	        }
	    }
	    
	    for(int i=0; i<N; i++){
	        if(indegree[i] != 0){
	            return false;
	        }
	    }
	    
	    return true;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}  // } Driver Code Ends