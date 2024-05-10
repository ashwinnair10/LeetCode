class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=0,r=height.size()-1;
        int max=-1;
        while(l<r){
            if(height[l]>=height[r]){
                if((r-l)*height[r]>max)
                max=(r-l)*height[r];
                r--;
            }
            else{
                if((r-l)*height[l]>max)
                max=(r-l)*height[l];
                l++;
            }
        }
        return max;
    }
};