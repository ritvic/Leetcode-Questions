// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
void fun(vector<int>&arr,int low,int high,vector<int>&v){
    int mid;
    if(low<=high){
        mid = (high+low)/2;
        v.push_back(arr[mid]);
        fun(arr,low,mid-1,v);
        fun(arr,mid+1,high,v);
    }
}
    vector<int> sortedArrayToBST(vector<int>& nums) {
        vector<int>v;
        fun(nums,0,nums.size()-1,v);
        return v;
        // Code here
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution obj;
		vector<int>ans = obj.sortedArrayToBST(nums);
		for(auto i: ans)
			cout << i <<" ";
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends