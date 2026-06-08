class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> less,great;
        int c=0;
        for(auto i:nums){
            if(i<pivot)
            less.push_back(i);
            else if(i==pivot)
            c++;
            else
            great.push_back(i);
        }
        for(int i=0;i<c;i++)
        less.push_back(pivot);
        for(auto i:great)
        less.push_back(i);
        return less;
    }
};