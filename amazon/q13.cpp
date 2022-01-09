
//   https://leetcode.com/problems/rotting-oranges/

struct Node
{
    int x, y, z;
};

class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int t = 0, r = grid.size(), c = grid[0].size();
        queue<Node> q;
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (grid[i][j] == 2)
                {
                    q.push({i, j, 0});
                }
                if (grid[i][j] == 1)
                {
                    t++;
                }
            }
        }
        int adj[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int res = 0;
        while (!q.empty())
        {
            Node n = q.front();
            res = max(res, n.z);
            q.pop();
            for (int k = 0; k < 4; k++)
            {
                int x = adj[k][0] + n.x;
                int y = adj[k][1] + n.y;
                if (x >= 0 && x < r && y >= 0 && y < c)
                {
                    if (grid[x][y] == 1)
                    {
                        t--;
                        q.push({x, y, n.z + 1});
                        grid[x][y] = 2;
                    }
                }
            }
        }
        return t == 0 ? res : -1;
    }
};