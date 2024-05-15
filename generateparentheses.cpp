class Solution {
public:
    void parent(string s,int l,int n,vector<string>& vec){
        if(s.length()==2*n){
            if(l==n)
            vec.push_back(s);
            return ;
        }
        if(l>0&&l<=n)
        parent(s+'(',l-1,n,vec);
        if(l>=0&&l<n)
        parent(s+')',l+1,n,vec);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> vec;
        string s="";
        parent(s,n,n,vec);
        return vec;
    }
};