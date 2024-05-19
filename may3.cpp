class Solution {
public:
    int compareVersion(string s1, string s2) {
        int i = 0, j = 0;
        
        while (i < s1.length() || j < s2.length()) {
            int num1 = 0, num2 = 0;
            
            while (i < s1.length() && s1[i] != '.') {
                num1 = num1 * 10 + (s1[i] - '0');
                i++;
            }
            
            while (j < s2.length() && s2[j] != '.') {
                num2 = num2 * 10 + (s2[j] - '0');
                j++;
            }
            
            if (num1 < num2) return -1;
            if (num1 > num2) return 1;
            
            i++;
            j++;
        }
        
        return 0;
    }
};
