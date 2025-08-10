class Solution {
public:
    bool findword(int i,int j,int ind,string word,vector<vector<char>>& board){

        int n=board.size();
        int m=board[0].size();

        if(ind==word.length()){
            return true; }

        if(i<0 || j<0 || i>=n || j>=m || board[i][j]=='#' ) {
            return false;
        }   

        if(board[i][j]!=word[ind]){
            return false;
        }

        char temp=board[i][j];
        board[i][j]='#';
        
        int delrow[]={-1,0,1,0};
        int delcol[]={0,-1,0,1};

        for(int z=0;z<4;z++){
            int nrow=i+delrow[z];
            int ncol=j+delcol[z];

            if(findword(nrow,ncol,ind+1,word,board)){
                return true;
            }

        }
        board[i][j]=temp;
        return false;


        






    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0] && findword(i,j,0,word,board)){
                    return true;
                }
            }
        }
        return false;
        
    }
};