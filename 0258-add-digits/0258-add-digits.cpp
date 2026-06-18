class Solution {
public:
    int addDigits(int num) {
        if(num<10)
        return num;
        int k=0;
        while(num>0){
            k+=num%10;
            num/=10;
        }
        return addDigits(k);
    }
};