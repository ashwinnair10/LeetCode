class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k%=nums.size();
        vector<int> r(k);
        int c=k-1,i=nums.size()-1;
        while(c>=0)
        r[c--]=nums[i--];
        for(auto j:r)
        cout<<j<<" ";
        for(i=nums.size()-1;i>=k;i--)
        nums[i]=nums[i-k];
        for(i=0;i<k;i++)
        nums[i]=r[i];
        return;
    }
};