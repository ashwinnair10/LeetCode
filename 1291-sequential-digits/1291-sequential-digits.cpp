class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string s="123456789";
        vector<int> numbers;
        for(int i=2;i<10;i++){
            for(int j=0;j<10-i;j++){
                int x=stoi(s.substr(j,i));
                if(x>high)
                break;
                if(x>=low)
                numbers.push_back(x);
            }
        }
        return numbers;
    }
};