class Solution {
public:
    int subarraySum(vector<int>& a, int k) {
        
        unordered_map<int,int> m;
        m[0]++;
        int res=0;
        for(int i=0;i<a.size();i++){
            if(i>0)
                a[i]+=a[i-1];
            res+=m[a[i]-k];
            m[a[i]]++;
        }
        return res;
    }
        
};