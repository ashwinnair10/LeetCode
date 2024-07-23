class Solution {
public:
    static bool cmp(pair<int,int>a,pair<int,int>b){
        if(a.second==b.second)
        return a.first>b.first;
        return a.second<b.second;
    }
    vector<int> frequencySort(vector<int>& a) {
        vector<pair<int,int>> vec;
        unordered_map<int,int> map;
        for(int i=0;i<a.size();i++){
            map[a[i]]++;
        }
        for(int i=0;i<a.size();i++){
            if(map.find(a[i])!=map.end()){
                vec.push_back({a[i],map[a[i]]});
                map.erase(a[i]);
            }
        }
        sort(vec.begin(),vec.end(),cmp);
        for(auto i:vec)
        cout<<i.first<<' '<<i.second<<'\n';
        vector<int> v;
        for(auto i:vec){
            while(i.second--)
            v.push_back(i.first);
        }
        return v;
    }
};