class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> v(2*n);
        for(int i=0;i<n;i++)
        {
            v[2*i]=nums[i];
            v[2*i+1]=nums[n+i];
        }
        return v;
    }
};