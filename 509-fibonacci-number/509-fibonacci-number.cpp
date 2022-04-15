class Solution {
public:
    vector<int> v=vector<int> (31);
    int fib(int n) {
        if(n==0 || n==1)
            return v[n]=n;
        else
            return v[n]=fib(n-1)+fib(n-2);
        
    }
};