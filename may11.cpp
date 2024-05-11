class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = quality.size();
        vector<pair<double, int>> costToQuality;
        for (int i = 0; i < n; ++i) {
            double ratio = static_cast<double>(wage[i]) / quality[i];
            costToQuality.push_back(make_pair(ratio, quality[i]));
        }
        sort(costToQuality.begin(), costToQuality.end());
        for(auto num:costToQuality){
            cout<<"ratio: "<<num.first<<" quality: "<<num.second<<'\n';
        }
        priority_queue<int> maxHeap;
        int totalQuality = 0;
        double minCost = numeric_limits<double>::max();
        for (auto& [ratio, q] : costToQuality) {
            totalQuality += q;
            maxHeap.push(q);
            if (maxHeap.size() > k) {
                totalQuality -= maxHeap.top();
                maxHeap.pop();
            }
            if (maxHeap.size() == k) {
                minCost = min(minCost, totalQuality * ratio);
            }
        }
        return minCost;
    }
};
