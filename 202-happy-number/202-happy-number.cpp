class Solution {
public:
    
    int cycle(int n)
    {
        int temp=0,a=0;
        while(n!=0)
        {
            temp=n%10;
            a+=temp*temp;
            n/=10;
        }
        return a;
    }
    
    
    bool isHappy(int n) {
        int slow=n,fast=n;
        do
        {
            slow=cycle(slow);
            fast=cycle(fast);
            fast=cycle(fast);
        }while(slow!=fast);
            
            if(slow==1)
                return true;
        else
            return false;
        
    }
};