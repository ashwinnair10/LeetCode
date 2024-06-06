class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        unordered_map<int,int> map;
        int n=hand.size();
        for(int i=0;i<n;i++){
            if(map.find(hand[i])==map.end()){
                map.insert(make_pair(hand[i],1));
            }
            else
            map[hand[i]]++;
        }
        sort(hand.begin(),hand.end());
        for(int i=0;i<n;i++){
            if(map.find(hand[i])!=map.end()){
                if(map[hand[i]]==1)
                map.erase(hand[i]);
                else
                map[hand[i]]--;
                for(int j=1;j<groupSize;j++){
                    if(map.find(hand[i]+j)==map.end())
                    return false;
                    else{
                        if(map[hand[i]+j]==1)
                        map.erase(hand[i]+j);
                        else
                        map[hand[i]+j]--;
                    }
                }
            }
        }
        return true;
    }
};