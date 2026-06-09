class Solution {
public:
    bool increasingTriplet(vector<int>& arr) {
        int a=INT_MAX,b=INT_MAX;
        for(int i=0;i<arr.size();i++){
            if(arr[i]<=a){
                a=arr[i];
            }
            else if(arr[i]<=b){
                b=arr[i];
            }
            else
            return true;
        }
        return false;
    }
};