class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for(auto i:asteroids){
            if(i>=0){
                st.push(i);
            }
            else{
                while(!st.empty()&&st.top()>0&&st.top()<abs(i)){
                    st.pop();
                }
                if(!st.empty()){
                    if(st.top()==abs(i))
                    st.pop();
                    else if(st.top()<0)
                    st.push(i);
                }
                else
                st.push(i);
            }
        }
        vector<int> ans(st.size());
        int l=st.size()-1;
        while(!st.empty()){
            ans[l--]=st.top();
            st.pop();
        }
        return ans;
    }
};