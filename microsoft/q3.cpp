
//   https://practice.geeksforgeeks.org/problems/rotate-by-90-degree0356/1/

void rotate(vector<vector<int>> &matrix)
{
    // Your code goes here
    int r = matrix.size(), c = matrix[0].size();
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    for (int i = 0; i < c; i++)
    {
        int s = 0, e = r - 1;
        while (s < e)
        {
            swap(matrix[s][i], matrix[e][i]);
            s++;
            e--;
        }
    }
}