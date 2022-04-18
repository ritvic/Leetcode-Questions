class Solution {
public:
    int minMoves(vector<int>& v) {
        
        return accumulate(v.begin(),v.end(),0)-*min_element(v.begin(), v.end())*v.size();
        
        
    }
};