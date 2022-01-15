
//   https://practice.geeksforgeeks.org/problems/length-of-largest-region-of-1s-1587115620/1/

class Solution
{
public:
    //Function to find unit area of the largest region of 1s.
    int count1(vector<vector<int>> &grid, int i, int j, vector<vector<bool>> &visited)
    {
        if (i >= grid.size() || i < 0 || j >= grid[0].size() || j < 0)
        {
            return 0;
        }
        if (visited[i][j] || !grid[i][j])
            return 0;
        visited[i][j] = 1;
        static int adj[8][2] = {{0, -1}, {0, 1}, {-1, -1}, {-1, 0}, {-1, 1}, {1, -1}, {1, 0}, {1, 1}};
        int count = 1;
        for (int k = 0; k < 8; k++)
        {
            count += count1(grid, i + adj[k][0], j + adj[k][1], visited);
        }
        return count;
    }
    int findMaxArea(vector<vector<int>> &grid)
    {
        // Code here
        int res = 0;
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), 0));
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                res = max(res, count1(grid, i, j, visited));
            }
        }
        return res;
    }
};