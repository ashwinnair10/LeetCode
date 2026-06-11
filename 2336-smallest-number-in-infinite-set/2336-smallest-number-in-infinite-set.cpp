class SmallestInfiniteSet {
public:
    priority_queue<int,vector<int>,greater<int>> pq;
    unordered_set<int> set;
    SmallestInfiniteSet() {
        for(int i=0;i<1000;i++){
            pq.push(i+1);
            set.insert(i+1);
        }
    }
    int popSmallest() {
        set.erase(pq.top());
        int r=pq.top();
        pq.pop();
        return r;
    }
    void addBack(int num) {
        if(set.find(num)==set.end()){
            pq.push(num);
            set.insert(num);
        }
        return;
    }
};