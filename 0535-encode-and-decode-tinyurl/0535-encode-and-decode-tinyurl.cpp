class Solution {
public:
    unordered_map<string,string> map;
    int temp=0;
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string hash="http:tinyurl.com/"+to_string(temp);
        map[hash]=longUrl;
        temp++;
        return hash;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return map[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));