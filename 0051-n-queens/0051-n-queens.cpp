class Solution {
public:
    bool valid(int i,int j,vector<int>& row,vector<int>& col,vector<int>& diag1,vector<int>& diag2,int& n){
        return (i<n&&j<n)&&!(row[i]||col[j]||diag1[i-j+n-1]||diag2[i+j]);
    }
    void test(vector<vector<string>>& ans,vector<string>& board,int i,int j,int q,int& n,vector<int>& row,vector<int>& col,vector<int>& diag1,vector<int>& diag2){
        cout<<"i : "<<i<<" -- j : "<<j<<" -- q : "<<q<<"\n";
        if(!valid(i,j,row,col,diag1,diag2,n))
        return;
        board[i][j]='Q';
        row[i]=1;
        col[j]=1;
        diag1[i-j+n-1]=1;
        diag2[i+j]=1;
        q+=1;
        if(q==n){
            ans.push_back(board);
            board[i][j]='.';
            row[i]=0;
            col[j]=0;
            diag1[i-j+n-1]=0;
            diag2[i+j]=0;
            return;
        }
        for(int k=0;k<n;k++){
            test(ans,board,k,j+1,q,n,row,col,diag1,diag2);
        }
        board[i][j]='.';
        row[i]=0;
        col[j]=0;
        diag1[i-j+n-1]=0;
        diag2[i+j]=0;
        return;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n);
        string s="";
        for(int i=0;i<n;i++)
        s+=".";
        for(int i=0;i<n;i++)
        board[i]=s;
        vector<vector<string>> ans;
        vector<int> row(n,0),col(n,0),diag1(2*n-1,0),diag2(2*n-1,0);
        for(int i=0;i<n;i++){
            test(ans,board,i,0,0,n,row,col,diag1,diag2);
        }
        return ans;
    }
};