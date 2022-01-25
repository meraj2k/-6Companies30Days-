
//    https://practice.geeksforgeeks.org/problems/word-search/1/


class Solution {
public:
    bool search(string &s,int i,vector<vector<char>> &board,int x,int y){
        if(i==s.length())  return true;
        if(x>=board.size() || x<0 || y>=board[0].size() || y<0){
            return false;
        }
        if(s[i]!=board[x][y]) return false;
        char ch=s[i];
        board[x][y]='#';
        bool res1=search(s,i+1,board,x,y+1);
        bool res2=search(s,i+1,board,x,y-1);
        bool res3=search(s,i+1,board,x+1,y);
        bool res4=search(s,i+1,board,x-1,y);
        board[x][y]=ch;
        return res1||res2||res3||res4;
    }
    bool isWordExist(vector<vector<char>>& board, string word) {
        // Code here
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]==word[0]){
                    if(search(word,0,board,i,j)) return true;
                }
            }
        }
        return false;
    }
};
