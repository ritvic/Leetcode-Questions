class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        
        vector<int> c;
        for(auto i:nums)
            c.push_back(i);
        for(auto i:nums)
            c.push_back(i);
        return c;
        
    }
};