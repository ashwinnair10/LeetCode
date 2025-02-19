class Solution {
public:
    void create(string s,int l,int& n,vector<string>& vec){
        if(l==n){
            vec.push_back(s);
            return;
        }
        if(l>0){
            vector<char> v={'a','b','c'};
            for(int i=0;i<3;i++){
                cout<<"s:"<<s<<" v[i]:"<<v[i]<<" s[l-1]:"<<s[l-1]<<'\n';
                if(s[l-1]!=v[i]){
                    create(s+v[i],l+1,n,vec);
                }
            }
        }
        if(l==0){
            create(s+"a",l+1,n,vec);
            create(s+"b",l+1,n,vec);
            create(s+"c",l+1,n,vec);
        }
    }
    string getHappyString(int n, int k) {
        vector<string> vec;
        create("",0,n,vec);
        for(auto i:vec)
        cout<<i<<'\n';
        if(vec.size()<k)
        return "";
        return vec[k-1];
    }
};