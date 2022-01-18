
//   https://practice.geeksforgeeks.org/problems/express-as-sum-of-power-of-natural-numbers5647/1


class Solution{
    public:
    
    int pr(int x,int y){
        int res=1;
        for(int i=1;i<=y;i++){
            res*=x;
        }
        return res;
    }
    long long int helper(int n,int x,int i,vector<vector<long long int>> &dp){
        if(n==0) return 1;
        if(pr(i,x)>n) return 0;
        if(n<0) return 0;
        if(dp[n][i]!=-1) return dp[n][i];
        return dp[n][i]= (helper(n-pr(i,x),x,i+1,dp)+helper(n,x,i+1,dp));
    }
    long long int numOfWays(int n, int x)
    {
        // code here
        vector<vector<long long int>> dp(n+1,vector<long long int>(1002,-1));
        return helper(n,x,1,dp);
    }
};