class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        int n=a.size()+b.size();
        int l=n%2?(n-1)/2:n/2;
        int k=0,i=0,j=0;
        vector<int> c;
        while(k<=l&&i<a.size()&&j<b.size()){
            if(a[i]<b[j]){
                c.push_back(a[i]);
                i++;
            }
            else{
                c.push_back(b[j]);
                j++;
            }
            k++;
        }
        while(k<=l&&i<a.size()){
            c.push_back(a[i]);
            i++;
            k++;
        }
        while(k<=l&&j<b.size()){
            c.push_back(b[j]);
            j++;
            k++;
        }
        return n%2?2*c[l]/2.0:(c[l-1]+c[l])/2.0;
    }
};