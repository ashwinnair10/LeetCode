#include <cmath> 
class Solution {
public:
    bool judgeSquareSum(int c) {
        long left = 0; 
        long right = static_cast<long>(sqrt(c)); 
        
        while (left <= right) {
            long curr_sum = left * left + right * right; 
            if (curr_sum == c) return true;
            if (curr_sum < c) {
                left++;  
            } else {
                right--;  
            }
        }
        
        return false; 
    }
};