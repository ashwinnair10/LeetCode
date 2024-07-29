class Solution {
    public String freqAlphabets(String s) {
        String ans="";
        char map[]={'j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
        for(int i=0;i<s.length();i++){
            char ch=s.charAt(i);
            if(ch>='3'&&ch<='9'){
                ans+=(char)(ch+48);
            }
            else{
                if(i+2<s.length()&&s.charAt(i+2)=='#'){
                    int num=Integer.parseInt(s.substring(i,i+2));
                    ans+=map[num-10];
                    i+=2;
                }
                else{
                    ans+=(char)(ch+48);
                }
            }
        }
        return ans;
    }
}