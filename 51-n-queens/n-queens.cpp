class Solution {
public:

void func(vector<string>&chess,int col,int row,vector<int>& rightdiagonal,vector<int>&leftdiagonal,vector<int>&rows,vector<vector<string>>&ans){
    if(col==chess.size()){
        ans.push_back(chess);
        return;
    }
    for(int i=0;i<chess.size();i++){
        if(rightdiagonal[i+col]==-1 and leftdiagonal[chess.size()-i+col]==-1 and rows[i]==-1){
            chess[i][col]='Q';
            rightdiagonal[i+col]=1;
            leftdiagonal[chess.size()-i+col]=1;
            rows[i]=1;
            func(chess,col+1,row,rightdiagonal,leftdiagonal,rows,ans);
            chess[i][col]='.';
            rightdiagonal[i+col]=-1;
            leftdiagonal[chess.size()-i+col]=-1;
            rows[i]=-1;
        }
    }
}
    vector<vector<string>> solveNQueens(int n) {
        vector<int> rightdiagonal(2*n,-1);
        vector<int> leftdiagonal(2*n,-1);
        vector<int> rows(n,-1);
vector<vector<string>> ans;
        vector<string> chess(n,string(n,'.'));
        func(chess,0,0,rightdiagonal,leftdiagonal,rows,ans);
        return ans;


    }
};