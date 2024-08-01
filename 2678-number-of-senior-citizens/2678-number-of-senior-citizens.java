class Solution {
    public int countSeniors(String[] details) {
        int ans=0;
        for(int i=0;i<details.length;i++){
            String s="";
            s+=details[i].charAt(11);
            s+=details[i].charAt(12);
            int age=Integer.parseInt(s);
            if(age>60)
            ans++;
        }
        return ans;
    }
}