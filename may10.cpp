class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& vec, int k) {
        vector<pair<double,double>> arr;
        for(int i=0;i<vec.size()-1;i++){
            for(int j=i+1;j<vec.size();j++){
                arr.push_back(make_pair((double)vec[i]/vec[j],vec[j]));
            }
        }
        sort(arr.begin(),arr.end());
        int y=arr[k-1].first*arr[k-1].second;
        y=y%2?y:y==2?y:y+1;
        vector<int> result;
        result.push_back(y);
        result.push_back(arr[k-1].second);
        return result;
    }
};