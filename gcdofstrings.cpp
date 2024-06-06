class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if (str1 == str2)
            return str1;
        while (str1 != str2) {
            if (str1.length() >= str2.length()) {
                if (str1.find(str2) == std::string::npos||str1.find(str2)%str2.length())
                    return "";
                else {
                    str1.erase(str1.find(str2), str2.length());
                }
            } else {
                if (str2.find(str1) == std::string::npos||str2.find(str1)%str1.length())
                    return "";
                else {
                    str2.erase(str2.find(str1), str1.length());
                }
            }
        }
        return str1;
    }
};