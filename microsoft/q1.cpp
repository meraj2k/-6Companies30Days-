
// https://practice.geeksforgeeks.org/problems/minimum-sum-partition3317/1/

class Solution
{

public:
    int minDifference(int arr[], int n)
    {
        // Your code goes here
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
        }
        int total = sum;
        sum = sum / 2;
        int dp[n + 1][sum + 1];
        for (int i = 0; i <= n; i++)
        {
            dp[i][0] = true;
        }
        for (int i = 1; i <= sum; i++)
        {
            dp[0][i] = false;
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= sum; j++)
            {
                if (arr[i - 1] > j)
                {
                    dp[i][j] = dp[i - 1][j];
                }
                else
                {
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
                }
            }
        }
        for (int i = sum; i >= 0; i--)
        {
            //cout<<dp[n][i]<<" ";
            if (dp[n][i])
            {
                return total - 2 * i;
            }
        }
    }
};