/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int l=0,r=n,m;
        while(l<=r){
            m=l+(r-l)/2;
            int k=guess(m);
            if(k==0)
            return m;
            else if(k==1){
                l=m+1;
            }
            else{
                r=m-1;
            }
        }
        return m;
    }
};