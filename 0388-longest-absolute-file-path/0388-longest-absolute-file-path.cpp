class Solution {
public:
    int lengthLongestPath(string input) {
        stack<string> st;
        stack<int> level;
        int ans=0,len=0;
        string curr="";
        for(int i=0;i<input.length();i++){
            if(input[i]=='\n'){
                int tabs=0;
                while(curr[tabs]=='\t')
                tabs++;
                while(!st.empty()&&level.top()>=tabs){   
                    len-=st.top().length();
                    if(st.top().find(".")==string::npos)
                    len--;
                    st.pop();
                    level.pop();
                }
                st.push(curr.substr(tabs));
                level.push(tabs);
                len+=st.top().length();
                if(st.top().find(".")==string::npos)
                len++;
                else
                ans=max(ans,len);
                curr="";
            }
            else{
                curr+=input[i];
            }
        }
        int tabs=0;
        while(curr[tabs]=='\t')
        tabs++;
        while(!st.empty()&&level.top()>=tabs){   
            len-=st.top().length();
            if(st.top().find(".")==string::npos)
            len--;
            st.pop();
            level.pop();
        }
        st.push(curr.substr(tabs));
        level.push(tabs);
        len+=st.top().length();
        if(st.top().find(".")==string::npos)
        len++;
        else
        ans=max(ans,len);
        curr="";
        return ans;
    }
};