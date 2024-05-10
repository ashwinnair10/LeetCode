class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<pair<int,int>> map;
        int k=score.size();
        for(int i=0;i<k;i++)
        map.push_back(make_pair(score[i],i));
        sort(map.begin(),map.end());
        vector<string> vec(k);
        for(int i=k-1;i>=0;i--){
            if(i==k-1){
                vec[map[i].second]="Gold Medal";
            }
            else if(i==k-2){
                vec[map[i].second]="Silver Medal";
            } 
            else if(i==k-3){
                vec[map[i].second]="Bronze Medal";
            }  
            else{
                vec[map[i].second]=to_string(k-i);
            }   
        }
        return vec;
    }
};