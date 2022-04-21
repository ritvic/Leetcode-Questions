class Solution {
public:
    int numIdenticalPairs(vector<int>& v) {
        
        sort(v.begin(),v.end());
        int c=0,count=0;
        for(int i=1;i<v.size();i++)
        {
            if(v[i]==v[i-1])
            {
                c++;
            }
           else
            {
                count+=(c)*(c+1)/2;
                c=0;
            }
        }
        count+=(c)*(c+1)/2;
        return count;
        
    }
};