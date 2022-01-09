
//   https://practice.geeksforgeeks.org/problems/is-sudoku-valid4820/1/

class Solution
{
public:
    int isValid(vector<vector<int>> mat)
    {
        // code here
        int countr[9][10] = {0}, countc[9][10] = {0}, count[9][10] = {0};
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (mat[i][j] == 0)
                {
                    continue;
                }
                countr[i][mat[i][j]]++;
                countc[j][mat[i][j]]++;
                int k = (i / 3) * 3 + (j / 3);
                count[k][mat[i][j]]++;
                if (countr[i][mat[i][j]] > 1 || countc[j][mat[i][j]] > 1 || count[k][mat[i][j]] > 1)
                {
                    return false;
                }
            }
        }
        return true;
    }
};