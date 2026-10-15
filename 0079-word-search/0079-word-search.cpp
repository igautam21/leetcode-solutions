class Solution {
public:
    bool find(int idx,int i,int j,vector<vector<char>>&board,string word){
        if(idx>=word.length()){
            return true;
        }
        int m=board.size(),n=board[0].size();
        if(i<0 || j<0 || i>=m || j>=n || word[idx]!=board[i][j] || board[i][j]=='$'){
            return false;
        }
        char temp=board[i][j];
        board[i][j]='$';
        if(find(idx+1,i+1,j,board,word)||
        find(idx+1,i-1,j,board,word)||
        find(idx+1,i,j+1,board,word)||
        find(idx+1,i,j-1,board,word)){
            return true;
        };
        board[i][j]=temp;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if( find(0,i,j,board,word)) return true;
            }
        }
        return false;
    }
};