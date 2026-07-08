class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        vector<long long> numbers,sum,len;
        long long p=10,n=0,q=0,l=0;
        int mod=1000000007;
        vector<long long> pow10(s.length() + 1, 1);
        for (int i = 1; i <= s.length(); i++) {
            pow10[i] = (pow10[i - 1] * 10) % mod;
        }
        numbers.push_back(n);
        sum.push_back(q);
        len.push_back(l);
        for(auto i:s){
            // cout<<i<<" -- "<<(i-'0')<<"\n";
            if((i-'0')!=0){
                n=((n*p)+(i-'0'))%mod;
                l++;
                // cout<<"n : "<<n<<" -- p : "<<p<<"\n";
                q+=(i-'0');
            }
            numbers.push_back(n);
            sum.push_back(q);
            len.push_back(l);
        }
        // for(auto i:numbers)
        // cout<<i<<" ";
        // cout<<"\n";
        // for(auto i:sum)
        // cout<<i<<" ";
        vector<int> ans;
        for(auto i:queries){
            int k=len[i[1]+1]-len[i[0]];
            if (k == 0) {
                ans.push_back(0);
                continue;
            }
            ans.push_back(((numbers[i[1]+1]-(numbers[i[0]]*pow10[k]%mod)+mod)%mod)*(sum[i[1]+1]-sum[i[0]])%mod);
        }
        return ans;
    }
};