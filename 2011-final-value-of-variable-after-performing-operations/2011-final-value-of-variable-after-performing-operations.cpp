class Solution {
public:
    int finalValueAfterOperations(vector<string>& v) {
        
        
        int k=0;
        for(auto i:v)
        {
            if(i=="--X" ||i=="X--")
                k--;
            else
                k++;
        }
        return k;
    }
    
};