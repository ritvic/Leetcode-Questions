class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int a=0;
        for(int i=1;i<=nums.size();i++)
            a^=i;
        for(auto i:nums)
            a^=i;
        return a;
        
    }
};