class LFUCache {
public:
    struct Node {
        int key, val, freq;
    };
    int cap;
    int minFreq;
    unordered_map<int, list<Node>::iterator> cacheMap;
    unordered_map<int, list<Node>> freqMap;

    LFUCache(int capacity) {
        cap = capacity;
        minFreq = 0;
    }

    void updateFrequency(list<Node>::iterator it) {
        int currentFreq = it->freq;
        Node currNode = *it;
        freqMap[currentFreq].erase(it);
        if (freqMap[currentFreq].empty() && currentFreq == minFreq) {
            minFreq++;
        }
        currNode.freq++;
        freqMap[currNode.freq].push_front(currNode);
        cacheMap[currNode.key] = freqMap[currNode.freq].begin();
    }
    
    int get(int key) {
        if (cacheMap.find(key) == cacheMap.end()) {
            return -1;
        }
        auto it = cacheMap[key];
        int val = it->val;
        updateFrequency(it);
        return val;
    }
    
    void put(int key, int value) {
        if (cap <= 0) return;
        if (cacheMap.find(key) != cacheMap.end()) {
            auto it = cacheMap[key];
            it->val = value;
            updateFrequency(it);
            return;
        }
        if (cacheMap.size() == cap) {
            auto nodeToEvict = freqMap[minFreq].back();
            cacheMap.erase(nodeToEvict.key);
            freqMap[minFreq].pop_back();
        }
        minFreq = 1;
        freqMap[1].push_front({key, value, 1});
        cacheMap[key] = freqMap[1].begin();
    }
};
