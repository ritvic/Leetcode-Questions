class Solution {
public:
    int maximumWealth(vector<vector<int>>& v) {
        
        int m=-1;
        for(auto i:v)
        {
            int c=0;
            for(auto j:i)
                c+=j;
            m=max(m,c);
        }
        return m;
    }
};