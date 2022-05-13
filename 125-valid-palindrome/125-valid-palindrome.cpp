class Solution {
public:
    bool isPalindrome(string s) {
        
        transform(s.begin(),s.end(),s.begin(),::toupper);
        for (int i = 0; i < s.size(); i++) {
            if ((s[i] < 'A' || s[i] > 'Z') &&
                (s[i] < '0' || s[i] > '9'))
            {  
                s.erase(i, 1);
                i--;
            }
         }
        // cout<<s;
        int i=0,j=s.size()-1;
            while(j>i)
            {
                if(s[i]!=s[j])
                    return false;
                i++;
                j--;
                    
            }
        return true;
    }
};