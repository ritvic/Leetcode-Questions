class Solution {
public:
    int rob(vector<int>& nums) { 
        int n = nums.size(), pre = 0, cur = 0,temp;
        for (int i = 0; i < n; i++) {
            temp = max(pre + nums[i], cur);
            pre = cur;
            cur = temp;
        }
        return cur;
    }
};