class Solution {
public:
    int mostWordsFound(vector<string>& v) {
        
         int res=0;
        for(auto i:v)
            res=max(res,(int)count(i.begin(),i.end(),' ')+1);
        return res;
    }
};