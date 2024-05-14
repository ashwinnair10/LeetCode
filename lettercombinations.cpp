class Solution {
public:
    void combine(string& digits,int i,string str,vector<string>& vec,unordered_map<char,string>& map){
        if(i==digits.length()){
            vec.push_back(str);
            return;
        }
        string chars=map.at(digits[i]);
        for(auto l:chars)
        combine(digits,i+1,str+l,vec,map);
    }
    vector<string> letterCombinations(string digits) {
        vector<string> vec;
        if(!digits.length())
        return vec;
        unordered_map<char,string> map={{'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };
        combine(digits,0,"",vec,map);
        return vec;
    }
};