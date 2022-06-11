class Solution {
public:
    int jump(vector<int>& nums) {
        
        int farthest=0,current=0,jump=0,n=nums.size();
        for(int i=0;i<n-1;i++)
        {
            farthest=max(farthest,i+nums[i]);
            if(i==current){jump++;current=farthest;}
        }
        if(current<n-1) return -1;
        return jump;
        
    }
};