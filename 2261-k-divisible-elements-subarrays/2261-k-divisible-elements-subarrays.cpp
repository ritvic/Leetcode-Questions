class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        const int N = nums.size();
        set<vector<int> > ret;
        for (int i = 0;i < N; i++) {
            vector<int> sub;
            for (int j = i, d = 0;j < N; j++) {
                sub.push_back(nums[j]);
                if (nums[j] % p == 0) d++;
                if (d <= k) {
                    ret.insert(sub);
                } else break;
            }
        }
        
        return ret.size();
    }
};