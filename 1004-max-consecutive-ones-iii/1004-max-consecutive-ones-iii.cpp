class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ans=0,c=0,f=k;
        int n=nums.size();
        int l=0;
        while(l<n){
            if(nums[l]){
                c++;
            }
            else{
                if(f){
                    c++;
                    f--;
                }
                else{
                    ans=max(ans,c);
                    while(nums[l-c]){
                        c--;
                    }
                }
            }
            l++;
        }
        return max(ans,c);
    }
};