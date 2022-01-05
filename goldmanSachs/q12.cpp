

//     Find total number of Squares in a N*N chessboard

// int fun(int n){
//     int ans=0;
//     for(int i=1;i<=n;i++){
//         ans+=i*i;
//     }
//     return ans;
// }

class Solution {
  public:
    long long squaresInChessBoard(long long n) {
        // code here
        return n*(n+1)*(2*n+1)/6;
    }
};