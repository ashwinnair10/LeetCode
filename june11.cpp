class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int,int> map;
        for(int i=0;i<arr1.size();i++){
            if(map.find(arr1[i])!=map.end())
            map[arr1[i]]++;
            else
            map.insert(make_pair(arr1[i],1));
        }
        int j=0;
        for(int i=0;i<arr2.size();i++){
            while(map[arr2[i]]--){
               arr1[j++]=arr2[i];
            }
            map.erase(arr2[i]);
        }
        int k=j;
        for(auto num:map){
            while((num.second)--){
                arr1[j++]=num.first;
            }
        }
        sort(arr1.begin()+k,arr1.end());
        return arr1;
    }
};