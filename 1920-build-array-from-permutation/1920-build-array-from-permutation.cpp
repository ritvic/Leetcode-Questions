class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        
        vector<int> b(nums.size());
        for(int i=0;i<nums.size();i++)
        {
            b[i]=nums[nums[i]];
        }
        return b;
    }
};