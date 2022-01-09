

//  https://practice.geeksforgeeks.org/problems/maximum-profit4657/1

class Solution
{
public:
    int help(int k, int A[], int n, int i, bool isBuy, vector<vector<vector<int>>> &dp)
    {
        if (i == n || k == 0)
            return 0;
        if (dp[i][k][isBuy] != -1)
            return dp[i][k][isBuy];
        int r1, r2;
        if (!isBuy)
        {
            r1 = help(k, A, n, i + 1, true, dp) - A[i];
        }
        else
        {
            r1 = help(k - 1, A, n, i + 1, false, dp) + A[i];
        }
        r2 = help(k, A, n, i + 1, isBuy, dp);
        return dp[i][k][isBuy] = max(r1, r2);
    }
    int maxProfit(int K, int N, int A[])
    {
        // code here
        vector<vector<vector<int>>> dp(N, vector<vector<int>>(K + 1, vector<int>(2, -1)));
        return help(K, A, N, 0, false, dp);
    }
};