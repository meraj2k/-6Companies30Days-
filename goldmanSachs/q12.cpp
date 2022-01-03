

//     Find total number of Squares in a N*N chessboard

int fun(int n){
    int ans=0;
    for(int i=1;i<=n;i++){
        ans+=i*i;
    }
    return ans;
}