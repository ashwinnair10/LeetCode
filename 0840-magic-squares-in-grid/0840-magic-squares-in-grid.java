class Solution {
    boolean test(int[][] a,int r,int c){
        HashSet<Integer> set=new HashSet<>();
        int s=a[0][0]+a[0][1]+a[0][2];
        for(int i=c;i<c+3;i++){
            set.add(a[r][i]);
            set.add(a[r+1][i]);
            set.add(a[r+2][i]);
            if(s!=a[r][i]+a[r+1][i]+a[r+2][i])
            return false;
        }
        for(int i=r;i<r+3;i++){
            if(s!=a[i][c]+a[i][c+1]+a[i][c+2])
            return false;
        }
        if(s!=a[r][c]+a[r+1][c+1]+a[r+2][c+2])
        return false;
        if(s!=a[r][c+2]+a[r+1][c+1]+a[r+2][c])
        return false;
        if(set.size()!=9)
        return false;
        for(int i=1;i<=9;i++)
        if(set.contains(i)==false)
        return false;
        return true;
    }
    public int numMagicSquaresInside(int[][] grid) {
        int ans=0;
        for(int i=0;i<grid.length-2;i++){
            for(int j=0;j<grid[0].length-2;j++){
                if(test(grid,i,j))
                ans++;
            }
        }
        return ans;
    }
}