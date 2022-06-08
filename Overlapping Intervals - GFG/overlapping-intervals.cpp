// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    vector<vector<int>> overlappedInterval(vector<vector<int>>& arr) {
         // Code here
         vector<vector<int>> v;
         sort(arr.begin(),arr.end());
         v.push_back(arr[0]);
         for(int i=1;i<arr.size();i++)
         {
             if(arr[i][0]<=v[v.size()-1][1])
             {
                 v[v.size()-1][1]=max(arr[i][1], v[v.size()-1][1]);
             }
             else
             v.push_back(arr[i]);
             
         }
         return v;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>Intervals(n);
		for(int i = 0; i < n; i++){
			int x, y;
			cin >> x >> y;
			Intervals[i].push_back(x);
			Intervals[i].push_back(y);
		}
		Solution obj;
		vector<vector<int>> ans = obj.overlappedInterval(Intervals);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends