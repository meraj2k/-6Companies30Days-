
//    https://leetcode.com/problems/remove-colored-pieces-if-both-neighbors-are-the-same-color


class Solution {
public:
    bool winnerOfGame(string colors) {
        int c1=0,c2=0;
        int count=1,i=1;
        while(i<colors.size()){
            if(colors[i-1]==colors[i]){
                count++;
                if(count>=3){
                    if(colors[i]=='A'){
                        c1++;
                    }else{
                        c2++;
                    }
                }
            }else{
                count=1;
            }
            i++;
        }
        return c1>c2;
    }
};