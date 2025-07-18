class Solution {
public:
    bool isPossible(vector<vector<char>>& board, int i, int j, string word, int index, string direction){
        // base case
        if(direction=="top" && index==word.length() && (i<0 || board[i][j]=='#')){
            return true;
        }
        if(direction=="bottom" && index==word.length() && (i==board.size() || board[i][j]=='#')){
            return true;
        }
        if(direction=="left" && index==word.length() && (j<0 || board[i][j]=='#')){
            return true;
        }
        if(direction=="right" && index==word.length() && (j==board[0].size() || board[i][j]=='#')){
            return true;
        }

        if((i<0 || i==board.size() || j<0 || j==board[i].size()) && index<word.length())
        return false;

        if(index==word.length() && board[i][j]!='#'){
            return false;
        }

        if(board[i][j]==' ' || board[i][j]==word[index]){
            if(direction=="top") 
            return isPossible(board, i-1, j, word, index+1, "top");
            
            if(direction=="bottom") 
            return isPossible(board, i+1, j, word, index+1, "bottom");
      
            if(direction=="left")
            return isPossible(board, i, j-1, word, index+1, "left");
          
            if(direction=="right")
            return isPossible(board, i, j+1, word, index+1, "right");
    
        }
        return false;
    }
    bool placeWordInCrossword(vector<vector<char>>& board, string word) {

        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                if(board[i][j]==' ' || board[i][j]==word[0]){
                    int index=0;
                    if((i+1==board.size() || board[i+1][j]=='#') && isPossible(board, i, j, word, index, "top")){
                    return true;
                    }
                    

                    if((i-1<0 || board[i-1][j]=='#') && isPossible(board, i, j, word, index, "bottom")){
                        return true;
                    }
                    
                    if((j+1==board[i].size() || board[i][j+1]=='#') &&isPossible(board, i, j, word, index, "left")){
                        return true;
                    }
                    
                    if((j-1<0 || board[i][j-1]=='#') && isPossible(board, i, j, word, index, "right")){
                        return true;
                    }
                    
                }
            }
        }
        return false;
    }
};