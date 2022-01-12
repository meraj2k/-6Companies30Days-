

//   https://practice.geeksforgeeks.org/problems/spirally-traversing-a-matrix-1587115621/1/

class Solution
{
public:
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int>> matrix, int r, int c)
    {
        // code here
        vector<int> v;
        int ur = 0, br = r - 1, lc = 0, rc = c - 1, count = 0;
        while (lc <= rc && ur <= br)
        {
            switch (count)
            {
            case 0:
                for (int i = lc; i <= rc; i++)
                {
                    v.push_back(matrix[ur][i]);
                }
                ur++;
                count++;
                break;
            case 1:
                for (int i = ur; i <= br; i++)
                {
                    v.push_back(matrix[i][rc]);
                }
                rc--;
                count++;
                break;
            case 2:
                for (int i = rc; i >= lc; i--)
                {
                    v.push_back(matrix[br][i]);
                }
                br--;
                count++;
                break;
            case 3:
                for (int i = br; i >= ur; i--)
                {
                    v.push_back(matrix[i][lc]);
                }
                lc++;
                count++;
            }
            count = count % 4;
        }
        return v;
    }
};