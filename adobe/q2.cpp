
//      https://practice.geeksforgeeks.org/problems/longest-arithmetic-progression1019/1/

class Solution
{
public:
    int lengthOfLongestAP(int A[], int n)
    {
        // code here
        if (n == 1 || n == 2)
            return n;
        int dp[n][n];
        int res = 2;
        for (int i = 0; i < n - 1; i++)
        {
            dp[i][n - 1] = 2;
            dp[i][i + 1] = 2;
        }
        for (int j = n - 2; j > 0; j--)
        {
            int i = j - 1, k = j + 1;
            //dp[j][k]=2;
            while (i >= 0 && k < n)
            {
                if (A[i] + A[k] == 2 * A[j])
                {
                    dp[i][j] = dp[j][k] + 1;
                    //cout<<i<<" "<<j<<"   "<<dp[i][j]<<"  ";
                    res = max(dp[i][j], res);
                    i--;
                    k++;
                }
                else if (A[i] + A[k] > 2 * A[j])
                {
                    dp[i][j] = 2;
                    i--;
                }
                else
                {
                    k++;
                }
            }
            while (i >= 0)
            {
                dp[i][j] = 2;
                i--;
            }
        }
        return res;
    }