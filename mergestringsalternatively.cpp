class Solution {
public:
    string mergeAlternately(string a, string b) {
        string str="";
        int i=0,j=0,c=0;
        while(i<a.length()&&j<b.length()){
            if(!c){
                str+=a[i];
                i++;
            }
            else{
                str+=b[j];
                j++;
            }
            c=(c+1)%2;
        }
        while(i<a.length()){
            str+=a[i];
            i++;
        }
        while(j<b.length()){
            str+=b[j];
            j++;
        }
        return str;
    }
};