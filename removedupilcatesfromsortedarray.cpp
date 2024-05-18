class Solution {
public:
    int removeDuplicates(vector<int>& vec) {
        int j=1;
        for(int i=1;i<vec.size();i++){
            if(vec[i]!=vec[i-1])
            vec[j++]=vec[i];
        }
        return j;
    }
};