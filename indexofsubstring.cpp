class Solution {
public:
    int strStr(string haystack, string needle) {
        if(haystack.find(needle)!=std::string::npos)
        return haystack.find(needle);
        return -1;
    }
};