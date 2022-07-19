class Solution {
public:
    string convert(string s, int nn) {
        if(nn==1)return s;
        vector<string> dp(nn,"");
        int n=s.size(),i=0,j=-1;
        while(i<n)
        {
             j++;
            while(j<nn && i<n)
            {
                dp[j]+=s[i];
                j++;i++;
            }
            j--;
            while(j>0 && i<n)
            {
                j--;
                dp[j]+=s[i];
                i++;
            }
        }
        string ss="";
        for(auto i:dp)
            ss+=i;
        return ss;
    }
};