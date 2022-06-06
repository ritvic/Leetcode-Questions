// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    // Code here
	    int count = 0;
    vector <pair<int, int>> pairs;
    for (int i = 0; i < nums.size(); i++){
        pairs.push_back({nums[i], i});
    }
    sort(pairs.begin(), pairs.end());
    
    for (int i = 0; i < pairs.size();){
        if (pairs[i].second == i){  i++; }
        else{ 
            swap(pairs[i], pairs[pairs[i].second]); 
            count++;
        }
    }
    return count;
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
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends