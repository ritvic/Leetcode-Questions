class Solution {
public:
    int hammingWeight(uint32_t N) {
        
        int count0 = 0, count1 = 0;
    while (N > 0) {
        if (N & 1) count1++;
        else count0++;
        N = N >> 1;
        
    }
        return count1;
    }
};