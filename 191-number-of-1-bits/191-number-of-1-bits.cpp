class Solution {
public:
    int hammingWeight(uint32_t N) {
        
        int count0 = 0, count1 = 0;
 
    // Iterate through all the bits
    while (N > 0) {
 
        // If current bit is 1
        if (N & 1) {
            count1++;
        }
 
        // If current bit is 0
        else {
            count0++;
        }
 
        N = N >> 1;
        
    }
        return count1;
    }
};